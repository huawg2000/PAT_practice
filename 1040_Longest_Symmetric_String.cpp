#include"iostream"
#include"algorithm"
#include"string"
using namespace std;

int LengthOfRevese(int begin,int end,string str) {
  int b = begin;
  int e = end;
  int length = 0;
  while(b < e){
    if(str[b] != str[e]) return 1;
    b++;
    e--;
    length += 2;
  }
  if(length != 1 && b == e) length += 1;//加上中间的数的长度1
  return length;
}

int main(int argc, char const *argv[]) {
  string str;
  int Mlen = -1;
  getline(cin,str);
  int len = str.length();
  for(int i = 0; i < len;i++) {
    for(int j = len - 1;j >= i;j--) {
      int Len = LengthOfRevese(i,j,str);
      Mlen = max(Len,Mlen);
    }
  }
  cout<<Mlen<<endl;
  return 0;
}
