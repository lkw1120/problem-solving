#include<bits/stdc++.h>
using namespace std;
int arr[100007];
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    int sum = 0;
    for(int i=0;i<K;i++) {
        sum+=arr[i];
    }
    ans = sum;
    for(int i=K;i<N;i++) {
        sum+=arr[i]-arr[i-K];
        ans = max(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}