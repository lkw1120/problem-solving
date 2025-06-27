#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[31];
int N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    arr[1] = 0;
    for(int i=2;i<=N;i++) {
        cin>>arr[i];
    }
    int need = 1;
    ans = 0;
    for(int i=2;i<=N;i++) {
        int lack = max(0,need-arr[i-1]);
        double tmp = pow(2.0,-(2*i-1)/4.0);
        ans+=lack*tmp;
        need = lack*2;
    }
    if(arr[N] < need) {
        cout<<"impossible"<<"\n";
    }
    else {
        cout<<fixed<<setprecision(6)<<ans<<"\n";
    }
    return 0;
}