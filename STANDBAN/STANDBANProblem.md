STANDBAN - Development Colored
#combinatorics #fast-fourier-transformation

There are N unique colors in the universe, numbered from 1 to N. George Michael wants to create a rainbow using these colors. The rainbow will consist of exactly M layers. For each layer, George Michael selects a color uniformly randomly from the N colors and colors the layer with it. George Michael wonders what will be the probability that there will be at least K distinct colors in the rainbow after all the layers are colored in this way.
Input
The first line of the input contains an integer T, denoting the number of test cases. Each of the next T lines will contain three integers, N, M and K.
Constraints
1 ≤ T ≤ 20
1 ≤ N, M, K ≤ 2 * 105
Output
For each test case, print the case number and the probability that the rainbow will contain at least K distinct colors after all the layers are colored. Formally, let this probability be an irreducible fraction P / Q. Then you need to print (P * Q-1) modulo 1000000007, where Q-1 is the modular inverse of Q modulo 1000000007. You may safely assume that there will be a unique modular inverse of Q modulo 1000000007.
Sample Input
3
1 1 1
2 2 2
4 2 2
Sample Output
Case 1: 1
Case 2: 500000004
Case 3: 750000006
