#include"iostream"
#include"algorithm"
#include"vector"
#include"cmath"
using namespace std;

bool cmp(int &a,int &b) {
  return a > b;
}

int main(int argc, char const *argv[]) {
  int n,row,col,Min = 1e9;
  cin>>n;
  vector<int> a(n);
  for(int i = 0;i < n;i++) {
    cin>>a[i];
  }

  for (col =sqrt(n); col>=1; col--){
    if (n % col == 0){
      row = n / col;
      break;
    }
  }

  vector<vector<int>> res(row,vector<int>(col,-1));
  sort(a.begin(),a.end(),cmp);
  int up = 0, down = row - 1, left = 0, right = col - 1, cnt = 0;

  while(true) {
         for(int j = left; j <= right; j ++) res[up][j] = a[cnt ++];
         if(++ up > down) break;
         for(int i = up; i <= down; i ++) res[i][right] = a[cnt ++];
         if(-- right < left) break;
         for(int j = right; j >= left; j --) res[down][j] = a[cnt ++];
         if(-- down < up) break;
         for(int i = down; i >= up; i --) res[i][left] = a[cnt ++];
         if(++ left > right) break;
     }

  for(int i = 0;i < row;i++) {
    for(int j = 0;j < col - 1;j++) {
      cout<<res[i][j]<<" ";
    }
    cout<<res[i][col-1];
    cout<<endl;
  }

  return 0;
}
