M_SEQ - Mosty! Find Gn
no tags 

Omar want to examine Mostafa in math, Mostafa asked to give G(n) that defined as:

G(n) = sqrt( F(n) - ( (n-1)^2 * F(n-1) / n^2 ) + 1/n^2 )

while:

F(n) = 8 + ( ((n-2)^2 )*(F(n-2)) /n^2 )

Mostafa need your help to find G(n) (n : given integer)

assume that : F(1) = 8, F(2) = 8;

Input
T number of test cases in the first line, T line follow with an integer n.

Output
Print G(n) for each test case with 8 decimal digits after the point (0 < G(n) < 3)

Example
Input:
3
5
7
42

Output:
2.20000000
2.14285714
2.02380952
Constraints
T < 104
2 < n < 109
