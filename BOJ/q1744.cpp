#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
int num[MAX] = {0};
int dp[MAX] = {0};
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>num[i];
    }
    sort(num+1,num+N+1);
    dp[1] = num[1];
    for(int i=2;i<=N;i++) {
        dp[i] = max(dp[i-1]+num[i],dp[i-2]+num[i-1]*num[i]);
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}