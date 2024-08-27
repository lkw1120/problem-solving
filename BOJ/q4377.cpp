#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double dp[101][10];
int K,N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>K>>N;
        if(cin.eof()) break;
        for(int k=0;k<=K;k++) {
            dp[1][k] = 1;
        }
        for(int i=2;i<=N;i++) {
            for(int k=0;k<=K;k++) {
                if(k == 0) {
                    dp[i][k] = (dp[i-1][k]+dp[i-1][k+1])/(K+1);
                }
                else if(k == K) {
                    dp[i][k] = (dp[i-1][k]+dp[i-1][k-1])/(K+1);
                }
                else {
                    dp[i][k] = (dp[i-1][k]+dp[i-1][k-1]+dp[i-1][k+1])/(K+1);
                }
            }
        }
        ans = 0;
        for(int k=0;k<=K;k++) {
            ans+=dp[N][k];
        }
        ans/=(K+1);
        ans*=100;
        cout<<fixed;
        cout.precision(5);
        cout<<ans<<"\n";
    }
    return 0;
}