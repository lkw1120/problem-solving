#include<bits/stdc++.h>
using namespace std;
int arr[2001];
int N,K,cnt,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    cnt = ans = 0;
    for(int i=2;i<=N;i++) {
        if(arr[i-1] < arr[i]) {
            cnt+=arr[i]-arr[i-1];
            arr[i] = arr[i-1];
            ans++;
        }
    }
    cout<<cnt<<" "<<ans<<"\n";
    return 0;
}