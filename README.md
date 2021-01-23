# PAT_practice
To make progress in programing and to be a graduate student of Zhejiang University.
## 1007 Maximum subsequence sum.
1007 Maximum Subsequence Sum (25分) Given a sequence of K integers { N1 , N​2 ,...,
  NK }. A continuous subsequence is defined to be { Ni , Ni+1,..., Nj }
  where 1≤i≤j≤K.The
Maximum Subsequence is the continuous subsequen ce which has the largest
sum of its elements. For example, given sequenc e { -2, 11, -4, 13, -5,
-2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum
being 20.

Now you are supposed to find the largest sum, together with the first an
d the last numbers of the maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. Th
e first line contains a positive integer K (≤10000). The second line
K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with th
e first and the last numbers of the maximum subsequence. The numbers mus
t be separated by one space, but there must be no extra space at the end
of a line. In case that the maximum subsequence is not unique, output t
he one with the smallest indices i and j (as shown by the sample case).
If all the K numbers are negative, then its maximum sum is defined to
be 0, and you are supposed to output the first and the last numbers of
the whole sequence.

**Sample Input:**

10

-10 1 2 3 4 -5 -23 3 7 -21

**Sample Output:**

10 1 4

最大子序列问题
用动态规划解决,dp方程为
dp[i] = max(dp[i-1]+arr[i],dp[i-1])
随后查找dp数组中的最大值
找到了最大值项则该项为尾项，将arr数组向前求和直到等于dp[i]的值即可找到首项

需要另外考虑的问题是

1.全为负数的情况时，输出第一个数和最后一个数

2.全为非正数的情况时，要找到第一个0所在的位置并输出0.

3.首尾数字出现0，要将0去掉

[1007_Maximum_subsequence_sum.cpp](./1007_Maximum_subsequence_sum.cpp)

## 1040 Longest Symmetric String

Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given Is PAT&TAP symmetric?, the longest symmetric sub-string is s PAT&TAP s, hence you must output 11.

Input Specification:
Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:
For each test case, simply print the maximum length in a line.

**Sample Input:**

Is PAT&TAP symmetric?

**Sample Output:**

11

最长回文子串问题
第一次用动态规划解决问题，后面也没解决问题
具体哪一步出错了还不太清楚 得分19/25

[1040_Longest_Symmetric_String.cpp](./1040_Longest_Symmetric_String.cpp)

第二次直接暴力破解，过了，想想应该是dp超限？

还是不太清楚，待会参考大佬思路的

[1040_Longest_Symmetric_String.cpp](./1040_Longest_Symmetric_String.cpp)

## 1012 The Best rank

To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algrbra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (≤2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output Specification:
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output N/A.

**Sample Input:**

5 6

310101 98 85 88

310102 70 95 88

310103 82 87 94

310104 91 91 91

310105 85 90 90

310101

310102

310103

310104

310105

999999

**Sample Output:**

1 C

1 M

1 E

1 A

3 A

N/A

这道题暴力，代码如同屎山，以后看看大佬的解法

[1012_The_Best_Rank.cpp](./1012_The_Best_Rank.cpp)


## 1101 Quick Sort (25分)

There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?

For example, given N=5 and the numbers 1, 3, 2, 4, and 5. We have:

1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
and for the similar reason, 4 and 5 could also be the pivot.
Hence in total there are 3 pivot candidates.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤105
​​ ). Then the next line contains N distinct positive integers no larger than 109
​​ . The numbers in a line are separated by spaces.

Output Specification:
For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

**Sample Input:**

5

1 3 2 4 5

**Sample Output:**

3

1 4 5

暴力破解果然不行，超时间

优化是可以先从后遍历一次，记录当前位置之后的最小值min[i]

再从前向后遍历一次，记录当前位置之前的最大值max[i]

之后判断当前位置是否小于min[i],大于max[i]

若true则计数++，push_back到res数组的最后面，false则继续循环

[1101_Quick_Sort.cpp](./1101_Quick_Sort.cpp)

## 1102 Invert a Binary Tree (25分)

The following is from Max Howell @twitter:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node from 0 to N−1, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

**Sample Input:**

8

1 -

- -

0 -

2 7

- -

- -

5 -

4 6

**Sample Output:**

3 7 2 6 4 0 5 1

6 5 7 4 3 2 0 1

二叉树反转，就是把一般遍历从左到右变为从右到左

用bfs实现层序遍历

随后递归求中序遍历

[1102_Invert_a_Binary_Tree.cpp](./1102_Invert_a_Binary_Tree.cpp)


## 1103 Integer Factorization (30分)
The K−P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K−P factorization of N for any positive integers N, K and P.

Input Specification:
Each input file contains one test case which gives in a line the three positive integers N (≤400), K (≤N) and P (1<P≤7). The numbers in a line are separated by a space.

Output Specification:
For each case, if the solution exists, output in the format:

N = n[1]^P + ... n[K]^P
where n[i] (i = 1, ..., K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 12^2​​ + 4^2 + 2^2 + 2^2 + 1^2;or 11^2 + 6^2 + 2^2 + 2^2 +
2^2, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence {a_1
​​,a_2,…a_k}is said to be larger than {b_1,b_2,…,b_k}if there exists 1≤L≤K such that a_i​ = b_i
for i<L and a_L>b_L.

If there is no solution, simple output Impossible.

**Sample Input 1:**

169 5 2

**Sample Output 1:**

169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2

**Sample Input 2:**

169 167 3

**Sample Output 2:**

Impossible

第一次写除了图以外的dfs

首先先写截止条件，当dfs遍历的数等于五个时return，若等于目标数，则比较
序列和大小，若比之前的序列和大，则更新，否则继续进行循环至index = 1.

[1103_Integer_Factorization.cpp](./1103_Integer_Factorization.cpp)

## 1104 Sum of Number Segments (20分)

Given a sequence of positive numbers, a segment is defined to be a consecutive subsequence. For example, given the sequence { 0.1, 0.2, 0.3, 0.4 }, we have 10 segments: (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) and (0.4).

Now given a sequence, you are supposed to find the sum of all the numbers in all the segments. For the previous example, the sum of all the 10 segments is 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N, the size of the sequence which is no more than 10
​5
​​ . The next line contains N positive numbers in the sequence, each no more than 1.0, separated by a space.

Output Specification:
For each test case, print in one line the sum of all the numbers in all the segments, accurate up to 2 decimal places.

**Sample Input:**

4

0.1 0.2 0.3 0.4

**Sample Output:**

5.00

观察数学规律，发现每个数出现(n-i+1) * i次，累加即可

坑点是数据量过大，需要用long double 类型进行结果值的存储

[1104_Sum_of_Number_Segments.cpp](./1104_Sum_of_Number_Segments.cpp)
