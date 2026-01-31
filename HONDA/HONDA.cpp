#include <cstudio>
#include <cmath>
using namespace std;

int main() {
  int cases;
  double Hx, Hy, Kx, Ky;
  scanf("%d", &cases);
  for(int no=1; no<=cases; no++) {
    scanf("%lf %lf %lf %lf", &Hx, &HY, &Kx, &Ky);
    printf("Case %d: %.6lf\n", no, sqrt((Hx+Kx)*(Hx+Kx) + (Hy+Ky)*(Hy+Ky))); //sqrt((Hx+Kx)^2 + (Hy+Ky)^2)
  }
  return 0;
}
