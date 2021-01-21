#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int Min = 1e9,Max = 0;
  int cnt = 0;
  vector<int> dp_maxmin(n);
  vector<int> dp_minmax(n);
  vector<int> res;
  vector<int> arr(n);

  for(int i = 0;i < n;i++) {
    cin>>arr[i];
    dp_maxmin[i] = arr[i];
    dp_minmax[i] = arr[i];
  }
  //扫描后i个数里最小值
  for(int i = n - 1;i >= 0;i--) {
    if(Min > dp_maxmin[i])Min = dp_minmax[i];
    else dp_maxmin[i] = Min;
  }
  // 扫描前i个数里最大值
  for(int i = 0;i < n;i++) {
    if(Max < dp_minmax[i])Max = dp_minmax[i];
    else dp_minmax[i] = Max;
  }
  // 满足两个条件放到数组中，并计数+1
  for(int i = 0;i < n;i++) {
    if(arr[i] >= dp_minmax[i] && arr[i] <= dp_maxmin[i]) {
      res.push_back(arr[i]);
      cnt++;
    }
  }
  cout<<cnt<<endl;
  for(int i = 0;i < cnt - 1;i++) {
    cout<<res[i]<<" ";
  }
  // 坑点 否则会发生段错误
  if(res.size()==0){
        printf("\n");
        return 0;
    }
  cout<<res[cnt-1];
  return 0;
}
