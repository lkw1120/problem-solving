#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 101;
int arr[MAX_N];
ll dp[MAX_N][MAX_N];
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin>>N>>K;
        if(!N && !K) break;
        fill(&dp[0][0],&dp[0][0]+MAX_N*MAX_N,0);
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
        }
        ans = 0;
        for(int i=1;i<=N;i++) {
            dp[i][1] = 1;
            for(int k=2;k<=K;k++) {
                ll cnt = 0;
                for(int j=1;j<i;j++) {
                    if(arr[j] < arr[i]) {
                        cnt+=dp[j][k-1];
                    }
                }
                dp[i][k] = cnt;
            }
            ans+=dp[i][K];
        }
        cout<<ans<<"\n";
    }
    return 0;
}