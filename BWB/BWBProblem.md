BWB - Black and White beads
no tags 

Well it's now time for some serious task. There are lots of beads available and in two colours, namely white and black. There are many beads of both colours. One has to make a string of beads by joining beads with end to end. But there are some constraints, and you have to follow that constraints. While making beads, you have to make sure that there should not be K beads of black colour consecutively and also there should not be any bead string which has black bead in front, i.e. it must have white bead in front. So the task is quite simple, find all possible ways of making a string of bead of length N which satisfies the above constraints.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

Next T lines contains 2 integers N and K.

Output
Print a line for each test case containing the required answer modulo 1000000007.

Constraints
1 ≤ T ≤ 1000000

1 ≤ N ≤ 10000

1 ≤ K ≤ 100

Sample
Input:
3
2 3
2 1
3 4

Output:
2
1
4
Explanation
For sample test case 1, N=2 and K=3, so as 3 beads of black colour should not present we have white-white, white-black.

Note black-white is not the valid one so in this case the answer is 2.
