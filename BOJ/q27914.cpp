#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+1;
int arr[MAX];
ll dp[MAX];
ll N,K,Q,X,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K>>Q;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    int cnt = 0;
    if(arr[1] != K) {
        dp[1] = cnt = 1;
    }
    else {
        dp[1] = 0;
    }
    for(int i=2;i<=N;i++) {
        if(arr[i] != K) {
            cnt++;
            dp[i]+=dp[i-1]+cnt;
        }
        else {
            dp[i] = dp[i-1];
            cnt = 0;
        }
    }
    for(int i=1;i<=Q;i++) {
        cin>>X;
        cout<<dp[X]<<"\n";
    }
    return 0;
}