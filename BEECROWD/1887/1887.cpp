#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 150005; // N + M + Q (Cukup buat 30k + 30k + 30k)

// --- LINK-CUT TREE CORE ---
int ch[MAXN][2], fa[MAXN], rev[MAXN];
int val[MAXN], mx_idx[MAXN]; 
int stk[MAXN];

// Cek apakah node x adalah root di Splay Tree-nya
bool isRoot(int x) {
    return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
}

// Update index node dengan bobot maksimal di subtree
void pushUp(int x) {
    mx_idx[x] = x;
    if (ch[x][0] && val[mx_idx[ch[x][0]]] > val[mx_idx[x]]) mx_idx[x] = mx_idx[ch[x][0]];
    if (ch[x][1] && val[mx_idx[ch[x][1]]] > val[mx_idx[x]]) mx_idx[x] = mx_idx[ch[x][1]];
}

void pushDown(int x) {
    if (rev[x]) {
        swap(ch[x][0], ch[x][1]);
        if (ch[x][0]) rev[ch[x][0]] ^= 1;
        if (ch[x][1]) rev[ch[x][1]] ^= 1;
        rev[x] = 0;
    }
}

void rotate(int x) {
    int y = fa[x], z = fa[y];
    int k = (ch[y][1] == x);
    if (!isRoot(y)) ch[z][ch[z][1] == y] = x;
    fa[x] = z;
    ch[y][k] = ch[x][k ^ 1];
    fa[ch[x][k ^ 1]] = y;
    ch[x][k ^ 1] = y;
    fa[y] = x;
    pushUp(y); pushUp(x);
}

void splay(int x) {
    int top = 0; stk[++top] = x;
    for (int i = x; !isRoot(i); i = fa[i]) stk[++top] = fa[i];
    while (top) pushDown(stk[top--]);
    while (!isRoot(x)) {
        int y = fa[x], z = fa[y];
        if (!isRoot(y))
            (ch[y][1] == x) ^ (ch[z][1] == y) ? rotate(x) : rotate(y);
        rotate(x);
    }
}

void access(int x) {
    for (int y = 0; x; y = x, x = fa[x]) {
        splay(x); ch[x][1] = y; pushUp(x);
    }
}

void makeRoot(int x) {
    access(x); splay(x); rev[x] ^= 1;
}

int findRoot(int x) {
    access(x); splay(x);
    while (ch[x][0]) pushDown(x), x = ch[x][0];
    splay(x);
    return x;
}

void link(int x, int y) {
    makeRoot(x);
    if (findRoot(y) != x) fa[x] = y;
}

void cut(int x, int y) {
    makeRoot(x); access(y); splay(y);
    if (ch[y][0] == x && !ch[x][1]) {
        ch[y][0] = fa[x] = 0;
        pushUp(y);
    }
}

// Cari node (edge) termahal di jalur antara u dan v
int queryMax(int u, int v) {
    makeRoot(u); access(v); splay(v);
    return mx_idx[v];
}

// --- LOGIKA MST ---
struct Edge {
    int u, v, w;
} edges_store[MAXN];

long long current_mst_weight = 0;

void process(int u, int v, int w, int edge_node_idx, bool is_query) {
    if (u == v) {
        if (is_query) printf("%lld\n", current_mst_weight);
        return;
    }
    
    // Kalau belum nyambung, langsung sambungin
    if (findRoot(u) != findRoot(v)) {
        current_mst_weight += w;
        link(u, edge_node_idx);
        link(edge_node_idx, v);
    } else {
        // Kalau udah nyambung, cek apakah jalur baru lebih murah dari yang termahal di siklus
        int heaviest_edge_node = queryMax(u, v);
        if (val[heaviest_edge_node] > w) {
            current_cost_change:
            current_mst_weight = current_mst_weight - val[heaviest_edge_node] + w;
            
            // Putus jalur lama
            int old_u = edges_store[heaviest_edge_node].u;
            int old_v = edges_store[heaviest_edge_node].v;
            cut(old_u, heaviest_edge_node);
            cut(heaviest_edge_node, old_v);
            
            // Sambung jalur baru
            link(u, edge_node_idx);
            link(edge_node_idx, v);
        }
    }
    if (is_query) printf("%lld\n", current_mst_weight);
}

int main() {
    int t, n, m, q;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        if (scanf("%d %d %d", &n, &m, &q) != 3) break;
        
        current_mst_weight = 0;
        // Reset LCT data
        for (int i = 0; i <= n + m + q + 5; i++) {
            ch[i][0] = ch[i][1] = fa[i] = rev[i] = val[i] = 0;
            mx_idx[i] = i;
        }

        // Jalur awal (Index node mulai dari N+1)
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            int node_idx = n + i;
            edges_store[node_idx] = {u, v, w};
            val[node_idx] = w;
            mx_idx[node_idx] = node_idx;
            process(u, v, w, node_idx, false);
        }

        // Query (Index node lanjut terus biar unik)
        for (int i = 1; i <= q; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            int node_idx = n + m + i;
            edges_store[node_idx] = {u, v, w};
            val[node_idx] = w;
            mx_idx[node_idx] = node_idx;
            process(u, v, w, node_idx, true);
        }
    }
    return 0;
}
