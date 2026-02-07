NOVICE45 - Problem 5
no tags 

Mahesh and I are always at conflict, Where I am a lazy person who would rather apply brute force and compute all possibilities of a problem to find the answer, he would rather solve it on paper to find a mathematical formula and reduce computational time. Fed up of his daily taunts I formulated the following problem, lets see who wins here brute force or mathematical precalculation:

Given two positive integers N and K you have to find the number of distinct ways of writing N as the sum of integers (possibly only 1) in range of [1, K] (inclusive).

For example if N = 4 and K = 2, we have these 3 ways => (2+2), (2+1+1), (1+1+1+1).

Input
Line 1: T(number of test cases)

Line 2 to T+1: 2 space separated integers N, K. (1<=N<=10000 and 1<=K<=100) 

Output
1 line per test case telling the number of ways. Since the answer can be very large print it modulo 1000000007.

Example
Input:
3
1 10
2 1
4 2

Output:
1
1
3
