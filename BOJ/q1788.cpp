#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000000;
const int MAX = 1000001;
int dp[MAX];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N == 0) {
        cout<<0<<"\n";
    }
    else if(N < 0 && N%2 == 0) {
        cout<<-1<<"\n";
    }
    else {
        cout<<1<<"\n";
    }
    N = abs(N);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=N;i++) {
        dp[i] = (dp[i-1]+dp[i-2])%MOD;
    }
    cout<<dp[N]<<"\n";
    return 0;
}