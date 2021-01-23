#include"iostream"
#include"vector"
#include"algorithm"
#include"cmath"
using namespace std;
int aim;
int length;
int power;
int Maxfacsum = -1;

vector<int> store,temp,ans;

void Init() {
  int index = 0;
  while (pow(index,power) <= aim) {
    store.push_back(pow(index++,power));
  }
}

void DFS(int index,int tempsum,int templength,int facsum) {
  if(templength == length) {
    if(tempsum == aim && facsum > Maxfacsum) {
      Maxfacsum = facsum;
      ans = temp;
    }
    return;
  }
  while(index >= 1) {
    if(tempsum + store[index] <= aim) {
      temp[templength] = index;
      DFS(index,tempsum+store[index],templength+1,facsum+index);
    }
    if(index == 1)return;
    index--;
  }
}

int main(int argc, char const *argv[]) {
  cin>>aim>>length>>power;

  Init();
  temp.resize(length);
  DFS(store.size()-1,0,0,0);

  if(Maxfacsum == -1) {
    cout<<"Impossible";
    return 0;
  }
  cout<<aim<<" = ";
  for(int i = 0;i < length - 1;i++) {
    cout<<ans[i]<<"^"<<power<<" "<<"+"<<" ";
  }
  cout<<ans[length-1]<<"^"<<power;
  return 0;
}
