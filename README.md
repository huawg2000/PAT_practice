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
