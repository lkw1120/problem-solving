#include<bits/stdc++.h>
using namespace std;
const int MAX = 1234567;
bool dp[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    dp[N] = true;
    for(int i=N-1;i>0;i--) {
        int num,sum;
        num = sum = i;
        while(num) {
            sum+=num%10;
            num/=10;
        }
        if(dp[sum]) {
            dp[i] = true;
        }
    }
    ans = count(dp,dp+N+1,true);
    cout<<ans<<"\n";
    return 0;
}