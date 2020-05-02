#include<bits/stdc++.h>
#define MAX 31
using namespace std;
typedef long long ll;
ll dp[MAX] = {0};
ll N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    dp[0] = 1;
    for (int i=1;i<MAX;i++){
        for(int j=0;j<i;j++) {
            dp[i] += dp[j]*dp[i-1-j];
        }
    }
    while(true) {
        cin>>N;
        if(N == 0) break;
        ans = dp[N];
        cout<<ans<<"\n";
    }
    return 0;
}