#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+2;
int top[MAX];
int bot[MAX];
int dp[MAX];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>top[i];
    }
    for(int i=1;i<=N;i++) {
        cin>>bot[i];
    }
    for(int i=0;i<N;i++) {
        dp[i] = dp[i-1];
        if(top[i+1] <= dp[i]) {
            dp[i] = top[i+1]-1;
        }
        if(dp[i] <= bot[i+1]) {
            dp[i] = bot[i+1]+1;
        }
    }
    for(int i=1;i<=N;i++) {
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
    return 0;
}