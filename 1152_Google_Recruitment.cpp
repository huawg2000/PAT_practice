#include"iostream"
#include"string"
using namespace std;

bool isPrime(int n) {
  if (n == 0 || n == 1) return false;
  for(int i = 2;i*i < n;i++) {
    if(n % i == 0)return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  string num;
  int len,k;
  cin>>len>>k;
  cin>>num;

  for(int i = 0;i < len - k;i++) {
    string s = num.substr(i,k);
    int t = stoi(s);
    if(isPrime(t)) {
      cout<<s;
      return 0;
    }
  }
  cout<<"404\n";

  return 0;
}
