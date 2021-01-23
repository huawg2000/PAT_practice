#include"iostream"
#include"vector"
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  long double sum = 0;
  vector<double> arr(n);
  for(int i = 1;i <= n;i++) {
    cin>>arr[i];
    sum += ((n - i + 1) * i)*arr[i];
  }
  printf("%.2Lf", sum);
  return 0;
}
