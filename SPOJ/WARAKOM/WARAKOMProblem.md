WARAKOM - PiggybankRI
no tags 

Ramy, a college tutor interested in algorithms decided to help out his students in problem solving by giving them an easy problem to solve to practice for their algorithms exam. Below is the description of the problem that Ramy is facing.

Ramy has a piggy bank with a certain capacity m and containing an amount q. He is going to use it for saving money and paying his debts for n days. Each day he can either add an amount to it or remove the same amount from it. Mr ramy can not exceed the maximum capacity of his piggy bank and neither can he withraw an amount that is not there. He is now wondering what is the maximum amount he can have in his piggy bank after n days. Can you help Ramy with his problem???

You will be given a list of the amounts he can add or withdraw and you are required to tell him the maximum amount he can have . If it's not possible for him to do the operations tell him that.

Input
The first line will start with a number t, the number of test cases (t <= 10).

Each test case will consist of 2 lines. The first line contain n, q, m (as explained in the problem) n <= 50,

0 <= q < m <= 1000.

The next line contains n space separated values ai 0 < i <= n, 0<= ai <= m.

Please note that in the test files there are no empty lines like the ones shown below.

Output
For each test case print 1 number in a separate line which is the maximum amount Mr. Ramy can have in his piggy bank after n days or -1 if he can't do it.

Please note that you should output the results without any empty lines, unlike the format given in the output. No seperate empty lines should be present in your output.

Example
Input:
2

3 5 10

5 3 7

4 8 20

15 2 9 10
Output:

10

-1
