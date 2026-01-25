#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 31;
int dp[MAX_N];
int T,N,ans;
void preset() {
    dp[0] = 2;
    dp[1] = 6;
    for(int i=2;i<MAX_N;i++) {
        dp[i] = 6*dp[i-1]-4*dp[i-2];
        dp[i]%=1000;
        if(dp[i] < 0) {
            dp[i]+=1000;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    preset();
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>N;
        ans = dp[N]-1;
        ans%=1000;
        if(ans < 0) {
            ans+=1000;
        }
        cout<<"Case #"<<tc<<": ";
        cout<<setw(3)<<setfill('0')<<ans<<"\n";
    }
    return 0;
}