#include<bits/stdc++.h>
using namespace std;
int dp[101];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    dp[1] = 2;
    dp[2] = 4;
    int tmp = 3;
    for(int i=3;i<=N;i++) {
        dp[i] = dp[i-1]+tmp;
        if(i%3) tmp++;
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}