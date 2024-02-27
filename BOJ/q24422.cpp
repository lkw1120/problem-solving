#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5+1;
int dp[MAX];
int N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>X>>Y;
        dp[i] = dp[i-1];
        if(Y == 0) {
            dp[i]++;
        }
        else if(Y <= dp[i]-dp[i-X-1]) {
            dp[i]++;
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}