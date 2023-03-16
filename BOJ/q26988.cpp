#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e3+7;
const ll MOD = 1e18;
ll dp1[MAX] = {0};
ll dp2[MAX] = {0};
ll N,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    dp1[0] = 1;
    for(int i=1;i<=K;i++) {
        for(int j=i;j<=N;j++) {
            dp2[j] = dp2[j]+dp2[j-i]+(dp1[j]+dp1[j-i])/MOD;
            dp1[j] = (dp1[j]+dp1[j-i])%MOD;
        }
    }
    if(dp2[N]) {
        cout<<dp2[N];
    }
    cout<<dp1[N]<<"\n";
    return 0;
}