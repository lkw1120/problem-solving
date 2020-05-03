#include<bits/stdc++.h>
#define DIV 987654321
#define MAX 5001
using namespace std;
typedef long long ll;
ll dp[MAX] = {0};
int N,ans;
int main() {
    cin>>N;
    dp[0] = 1;
    for(int i=1;i<=N/2;i++) {
        for(int j=0;j<i;j++) {
            dp[i]+=dp[j]*dp[i-1-j];
            dp[i]%=DIV;
        }
    }
    ans = dp[N/2];
    cout<<ans<<"\n";
    return 0;
}