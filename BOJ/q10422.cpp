#include<bits/stdc++.h>
#define MAX 2501
#define DIV 1000000007
using namespace std;
typedef long long ll;
ll dp[MAX] = {0};
ll T,N,ans;
int main() {
    ios_base::sync_with_stdio(false);
    dp[0] = 1;
    for (int i=1;i<MAX;i++){
        for(int j=0;j<i;j++) {
            dp[i] += dp[j]*dp[i-1-j];
            dp[i] %= DIV;
        }
    }
    cin>>T;
    while(T--) {
        cin>>N;
        if(N%2) 
            ans = 0;
        else 
            ans = dp[N/2];
        cout<<ans<<"\n";
    }
    return 0;
}