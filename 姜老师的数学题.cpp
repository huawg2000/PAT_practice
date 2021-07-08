#include"iostream"
using namespace std;
int main(int argc, char const *argv[]) {
    long long sum = 0;
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++) {
        cin>>a[i];
    }
    for(int i = 0;i < n;i++) {
        for(int j = i+1;j < n;j++) {
            int b = a[i]&a[j];
            cout<<b<<" ";
            if(b == a[i] || b == a[j])
                sum += max(a[i],a[j]);
            cout<<sum<<"* ";
        }
    }
    // cout<<b;
    cout<<sum;
    return 0;
    cout << "a test";
}
