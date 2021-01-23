#include"iostream"
#include"queue"
#include"string"
#include"vector"
#include"cstring"
#define null -1
using namespace std;

struct Node{
  int left;
  int right;
}Node[100];
bool isVis[100];//当前数字是否被访问
vector<int> level;
vector<int> in;

//层序遍历 右子树优先
void LevelOrder(int root) {
  queue<int> q;
  if(root != null) {
    q.push(root);
    level.push_back(root);
    // cout<<"1";
  }

  while(!q.empty()) {
    int data = q.front();
    q.pop();
    if(Node[data].right != null) {
      q.push(Node[data].right);
      level.push_back(Node[data].right);
    }
    if(Node[data].left != null) {
      q.push(Node[data].left);
      level.push_back(Node[data].left);
    }
  }
}

//中序遍历 右子树优先
void inOrder(int root) {
  if(root != null) {
    inOrder(Node[root].right);
    in.push_back(root);
    inOrder(Node[root].left);
  }
}
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  string left,right;
  for(int i = 0;i < n;i++) {
    cin>>left>>right;
    if(left != "-") {
      Node[i].left = stoi(left);//string转成int
      isVis[Node[i].left] = true;
    }
    else {
      Node[i].left = null;
    }
    if(right != "-") {
      Node[i].right = stoi(right);
      isVis[Node[i].right] = true;
    }
    else {
      Node[i].right = null;
    }
  }

  int root;
  for(int i = 0;i < n;i++) {
    //没访问过的数字作为根节点
    if(!isVis[i]) {
      root = i;
    }
  }

  LevelOrder(root);//层序遍历
  for(int i = 0;i < n-1;i++) {
    cout<<level[i]<<" ";
  }
  cout<<level[n-1]<<endl;

  inOrder(root);//中序遍历
  for(int i = 0;i < n-1;i++) {
    cout<<in[i]<<" ";
  }
  cout<<in[n-1];
  return 0;
}
