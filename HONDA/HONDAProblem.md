World Cup 2014 has started. Honda wants to watch the matches with his friend Kagawa. So he is planning to visit his friend every night. But just watching the matches is pretty boring. So he will be bringing some snacks. He decided that he will buy chips and juice before going to Kagawa’s house.

Optimum path for travelling
<img width="423" height="308" alt="image" src="https://github.com/user-attachments/assets/dafe7a8f-f102-4fca-a080-c12fddf00d1c" />


There are many possible path from Honda’s house to Kagawa’s house. But exactly one path is the shortest.

Honda lives at (Hx, Hy) coordinate, where Hx and Hy are positive integers. All the chips shops are located over the x-axis, and all the juice shops are located over the y-axis. Note that, this means, the shop at (0, 0) sells both chips and juice. Kagawa lives at (Kx, Ky) coordinate.

So Honda needs to travel the shop(s) and buy chips and juice before heading towards Kagawa’s house. Since he is really excited about watching the match, he wants to do it as fast as possible. Find the smallest distance he needs to travel.

Note: that a shop is considered a point on the axis. It has no length or width. As a result, even though Honda and Kagawa have their homes at a point with integer coordinates, a shop can have real number in its coordinate. For example, there is a shop at (0, 2.12341) and at (1312.3123, 0).

Input
First line will contain a single integer T (T < 10000) indicating the number of test cases. After that T line will follow. Each line will contain four positive integers: Hx, Hy, Kx, Ky, representing the coordinates of Honda’s house and Kagawa’s house. The coordinates will be less than 10000.

Output
For each case, print the case number and the minimum distance required to travel by Honda. Error less than 10-6 will be ignored.

Sample
Input
5
1 1 2 2
2 1 1 2
1 1 1 3
4 5 10 12
1345 123 123 2

Input
Case 1: 4.242641
Case 2: 4.242641
Case 3: 4.472136
Case 4: 22.022716
Case 5: 1473.312255
Hints
In the first case, the optimum route is (1,1) → (0,0) → (2,2)

In the second case, the optimum route is (2,1) → (1,0) → (0,1) → (1,2)

In the third case, the optimum route is (1,1) → (0.5,0) → (0,1) → (1,3)
