#include"iostream"
#include"algorithm"
#include"vector"
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int arr[n];
  int begin = 0;
  int end = n-1;
  int Maxsequence = -1;//考虑数组全不为正数时找到第一个0的下标
  vector <int>dp(n+1,0);
  for(int i = 0;i < n;i++) {
    cin>>arr[i];
    dp[i] = arr[i];
  }
  for(int i = 1;i < n;i++) {
      dp[i] = max(dp[i]+dp[i-1],dp[i]);
  }
  //找到最大子序列和尾项
  for(int i = 0;i < n;i++) {
    if(Maxsequence < dp[i]) {
      Maxsequence = dp[i];
      end = i;
    }
  }
  if(Maxsequence == -1) Maxsequence = 0;//如果数组全为负数时，置为0
  int sum = 0;
  //找首项
  if(Maxsequence >= 0) {
    for(int i = end;i >= 0;i--) {
      sum += arr[i];
      if(sum == Maxsequence)
      begin = i;
    }
 }
 //首尾为0时，去掉0这个数
  if(arr[begin] == 0 && begin != end) {
    begin+=1;
  }
  if(arr[end] == 0 && begin != end) {
    begin-=1;
  }
  cout<<Maxsequence<<" "<<arr[begin]<<" "<<arr[end];
  return 0;
}
