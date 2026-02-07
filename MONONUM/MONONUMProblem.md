MONONUM - Monotonous numbers
#dynamic-programming

Some integers possess interesting quality: each of their digits is not greater than the digit to the right. Let us define such integers as increasing integers. And let's call integers for which each digit is not lesser than the digit to the right decreasing integers. For example 24558 is increasing, 888410 is decreasing and 5 - is both increasing and decreasing. Given n calculate the ratio of the decreasing n-digit integers to the increasing n-digit integers. We consider only positive integers. Leading zeros are not allowed.

Input
The first line of the input contains number t – the number of tests. Then t test descriptions follow. Each test consists of the single integer n.

Constraints
1 ≤ t ≤ 10000
1 ≤ n ≤ 106

Output
For each test print the needed ratio with six digits in the fractional part.

Example
Input:
2
1
2

Output:
1.000000
1.200000
