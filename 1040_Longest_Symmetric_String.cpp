#include"iostream"
#include"string"
#include"vector"
#include"algorithm"
using namespace std;
int main(int argc, char const *argv[]) {
  string str;
  getline(cin,str);//输入空格有效
  int len = str.length();
  vector<vector<int>> dp(len,vector<int>(len));
  for(int i = len - 1;i >= 0;i--){
    dp[i][i] = 1;
    for(int j = i+1;j < len;j++){
      if(str[i] == str[j]) {
        dp[i][j] = dp[i+1][j-1] + 2;//i-j为回文串，长度+2
      }
      else
        dp[i][j] = max(dp[i+1][j],dp[i][j-1]);//更新dp数组的值
    }
  }
  cout<<dp[0][len-1];
  return 0;
}
