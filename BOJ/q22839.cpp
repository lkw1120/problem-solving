#include<bits/stdc++.h>
using namespace std;
int dp[301] = {0};
int N,ans;
void preload() {
    dp[0] = 1;
    for(int i=1;i<=17;i++) {
        for(int j=300;j>=0;j--) {
            if(dp[j]) {
                for(int k=1;;k++) {
                    if(300 < j+i*i*k) break;
                    dp[j+i*i*k]+=dp[j];
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    preload();
    while(cin>>N) {
        if(N == 0) break;
        ans = dp[N];
        cout<<ans<<"\n";
    }
    return 0;
}