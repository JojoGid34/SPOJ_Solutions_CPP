XORLATZ - Collatz Polynomial
no tags 

Everyone knows (or has heard of) the famous Collatz Conjecture: take a positive integer. If it's odd, multiply by 3 and add 1. If it's even, divide by 2. Repeat the process until you reach 1. Despite its simplicity, no one has proven if it actually reaches 1 for every starting number.

Aline, a fan of these curiosities, decided to create a variation using polynomials instead of numbers. Since she dislikes complications, she decided to work only with polynomials where each power of x appears at most once.

The game works as follows: if the polynomial has a constant term (a term that does not depend on x), she multiplies the polynomial by (x + 1) and then adds 1. Otherwise, she divides the polynomial by x.

Aline repeats this process, always applying one of these rules, until the polynomial becomes simply P(x) = 1.

For example, consider the polynomial P(x) = x3 + 1.

In the first step, there is a constant term, so we calculate:
(x3 + 1)(x + 1) + 1 = x4 + x3 + x + 1 + 1

Since Aline likes to keep things simple, whenever the sum of coefficients results in an even number, the corresponding term is discarded. Thus, the constant term (1 + 1 = 2) disappears, leaving the polynomial x4 + x3 + x.

In the next step, the constant term is no longer present, so we divide by x, obtaining x3 + x2 + 1.

Continuing the process:

Step 3: x4 + x2 + x
Step 4: x3 + x + 1
Step 5: x4 + x3 + x2
Step 6: x3 + x2 + x
Step 7: x2 + x + 1
Step 8: x3
Step 9: x2
Step 10: x
Step 11: 1
In total, 11 operations were required.

To make representing polynomials easier, we will use a simple convention: we use integers as binary masks. If the polynomial has the term xn, then the bit at position n (starting at zero, which is the least significant bit) will be activated (set to 1). For example, the polynomial x3 + x2 + 1 is represented by the number 13, because 13 in binary is 1101 (bits 0, 2, and 3 are set).

Input
The input contains a single integer P (1 ≤ P ≤ 106), representing the initial polynomial.

Output
Output a single integer representing the number of operations needed for the polynomial to become 1.

Example
Input:
9

Output:
11
Input:
5

Output:
6
Input:
1

Output:
0
