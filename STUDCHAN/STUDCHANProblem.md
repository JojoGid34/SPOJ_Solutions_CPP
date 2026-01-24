STUDCHAN - Student Chains
no tags 

Problem Statement
There are n students, standing in a line, adjacent to each other, holding hands and forming a chain. You have to remove k students from the line, so that you can form a chain of students of any length between 1 and n. Find the smallest k with which this can be done.

Note:

1. The first and last students in the line are not holding their hands. Thus the chain is not circular.

2. Any one student, can link two chains of arbitrary length.

Input
The first line of input contains an integer T, denoting the number of test cases. Next T lines contain an integer n, denoting the number of students in the chain.

Output
For each test case, print a line denoting the required output.

Constraints
1 <= T <= 50
1 <= n <= 10^10

Sample Input
1
6

Sample Output
1

Explanation
Take one student from the chain so that, you will have three chains of length 1, 2, and 3. With these three student chains, you can form chains of any length from 1 to 6.
