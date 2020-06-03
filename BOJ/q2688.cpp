#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[65][10] = {0};
ll T,N,ans;
void init() {
    for(int i=0;i<10;i++) {
        dp[1][i] = 1;
    }
    for(int i=2;i<65;i++) {
        for(int j=0;j<10;j++) {
            for(int k=0;k<=j;k++) {
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    cin>>T;
    while(T--) {
        cin>>N;
        ans = 0;
        for(int i=0;i<10;i++) {
            ans+=dp[N][i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}