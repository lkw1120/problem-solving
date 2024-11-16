#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int N,M,K,X,A;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K>>X;
    for(int i=1;i<=N;i++) {
        cin>>A;
        X+=A;
        dp[i]+=dp[i-1];
        if(X < K) {
            dp[i]++;
        }
    }
    for(int i=1;i<=M;i++) {
        int l,r;
        cin>>l>>r;
        cout<<dp[r-1]-dp[l-1]<<"\n";
    }
    return 0;
}