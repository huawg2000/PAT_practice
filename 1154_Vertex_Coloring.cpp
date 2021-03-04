#include"iostream"
#include"unordered_set"
using namespace std;

int main(int argc, char const *argv[]) {
  int M,N;
  int a[10000],b[10000];
  cin>>M>>N;
  for(int i = 0;i < N;i++) {
    cin>>a[i]>>b[i];
  }
  int k;
  cin>>k;
  while(k--) {
    unordered_set<int> color;
    int color_on_edge[M];
    for(int i = 0;i < M;i++) {
      cin>>color_on_edge[i];
      color.insert(color_on_edge[i]);
    }
    bool same_color = false;
    for(int i = 0;i < N;i++) {
      if(color_on_edge[a[i]] == color_on_edge[b[i]]) {
        same_color = true;
      }
      if(same_color == true) {
        cout<<"No"<<endl;
        break;
      }
    }
    if(same_color == false)cout<<color.size()<<"-coloring"<<endl;
  }
  return 0;
}
