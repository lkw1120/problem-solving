#include<bits/stdc++.h>
using namespace std;
int arr[50001];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    ans = 0;
    for(int i=2;i<=N;i++) {
        ans+=(arr[i-1]*arr[i-1]*2+arr[i]*arr[i]*2);
    }
    cout<<ans<<"\n";
    return 0;
}