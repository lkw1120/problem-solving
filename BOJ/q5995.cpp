#include<bits/stdc++.h>
using namespace std;
vector<int> w;
int dp[45001] = {0};
int H,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>H>>N;
    w.resize(N);
    for(int i=0;i<N;i++) {
        cin>>w[i];
    }
    dp[0] = 1;
    for(int i=0;i<N;i++) {
        for(int j=H;j>=w[i];j--) {
            if(w[i] <= j) {
                dp[j]+=dp[j-w[i]];
            }
        }
    }
    for(int i=H;i>=0;i--) {
        if(dp[i]) {
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}