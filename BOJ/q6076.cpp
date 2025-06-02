#include <bits/stdc++.h>
using namespace std;
const int MAX_C = 50001;
vector<int> v;
bool dp[MAX_C];
int C,H,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>C>>H;
    v.resize(H);
    for(int i=0;i<H;i++) {
        cin>>v[i];
    }
    dp[0] = true;
    for(int i=0;i<H;i++) {
        int tmp = v[i];
        for(int j=C;j>=tmp;j--) {
            if(dp[j-tmp]) {
                dp[j] = true;
            }
        }
    }
    for(int j=C;j>=0;j--) {
        if(dp[j]) {
            ans = j;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}