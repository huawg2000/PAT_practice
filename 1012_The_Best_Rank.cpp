#include"iostream"
#include"algorithm"
#include"vector"
#include"unordered_map"
using namespace std;
typedef struct Student{
  int id;
  int C;
  int M;
  int E;
  int A;
}Student;
bool cmpA(Student a,Student b) {
  return a.A > b.A;
}
bool cmpC(Student a,Student b) {
  return a.C > b.C;
}
bool cmpM(Student a,Student b) {
  return a.M > b.M;
}
bool cmpE(Student a,Student b) {
  return a.E > b.E;
}
int main(int argc, char const *argv[]) {
  int m,n;
  cin>>m>>n;
  vector<Student> stu(m);
  for(int i = 0;i < m;i++) {
    cin>>stu[i].id>>stu[i].C>>stu[i].M>>stu[i].E;
    stu[i].A = (stu[i].C + stu[i].M + stu[i].E) / 3;
  }
  sort(stu.begin(),stu.end(),cmpA);
  unordered_map<int,int> Arank(m);
  for(int i = 0; i < m;i++) {
    Arank.insert(pair<int,int>(stu[i].id,i+1));
    for(int j = 0;j < m && j!=i;j++) {
      int rank = j + 1;
      if(stu[i].A == stu[j].A){
        auto iter = Arank.find(stu[j].id);
        auto iter1 = Arank.find(stu[i].id);
        rank = min(iter1 -> second,iter -> second);
        iter -> second = rank;
        iter1 -> second = rank;
      }
    }
  }
  sort(stu.begin(),stu.end(),cmpC);
  unordered_map<int,int> Crank(m);
  for(int i = 0; i < m;i++) {
    Crank.insert(pair<int,int>(stu[i].id,i+1));
    for(int j = 0;j < m && j != i;j++) {
      int rank = j + 1;
      if(stu[i].C == stu[j].C){
        auto iter = Crank.find(stu[j].id);
        auto iter1 = Crank.find(stu[i].id);
        rank = min(iter1 -> second,iter -> second);
        iter -> second = rank;
        iter1 -> second = rank;
      }
    }
  }
  sort(stu.begin(),stu.end(),cmpM);
  unordered_map<int,int> Mrank(m);
  for(int i = 0; i < m;i++) {
    Mrank.insert(pair<int,int>(stu[i].id,i+1));
    for(int j = 0;j < m && j != i;j++) {
      int rank = j + 1;
      if(stu[i].M == stu[j].M){
        auto iter = Mrank.find(stu[j].id);
        auto iter1 = Mrank.find(stu[i].id);
        rank = min(iter1 -> second,iter -> second);
        iter -> second = rank;
        iter1 -> second = rank;
      }
    }
  }
  sort(stu.begin(),stu.end(),cmpE);
  unordered_map<int,int> Erank(m);
  for(int i = 0; i < m;i++) {
    Erank.insert(pair<int,int>(stu[i].id,i+1));
    for(int j = 0;j < m && j != i;j++) {
      int rank = j + 1;
      if(stu[i].E == stu[j].E){
        auto iter = Erank.find(stu[j].id);
        auto iter1 = Erank.find(stu[i].id);
        rank = min(iter1 -> second,iter -> second);
        iter -> second = rank;
        iter1 -> second = rank;
      }
    }
  }
  int rank[m];
  char Rank[m];
  int ID[n];
  for(int i = 0; i < n;i++) {
    cin>>ID[i];
  }
  for(int i = 0;i < n;i++) {
    int flag = 0;
    for(int j = 0;j < m;j++) {
      if(ID[i] == stu[j].id) {
        flag = 1;
        auto iter1 = Arank.find(ID[i]);
        auto iter2 = Crank.find(ID[i]);
        auto iter3 = Mrank.find(ID[i]);
        auto iter4 = Erank.find(ID[i]);
        rank[j] = iter1->second;
        Rank[j] = 'A';
        if(iter2->second < rank[j]) {
          rank[j] = iter2->second;
          Rank[j] = 'C';
        }
        if(iter3->second < rank[j]) {
          rank[j] = iter3->second;
          Rank[j] = 'M';
        }
        if(iter4->second < rank[j]) {
          rank[j] = iter4->second;
          Rank[j] = 'E';
        }
        cout<<rank[j]<<' '<<Rank[j]<<endl;
      }
    }
    if(flag == 0)cout<<"N/A"<<endl;
  }
  auto iter = Arank.find(ID[3]);
  return 0;
}
