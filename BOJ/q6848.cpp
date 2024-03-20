#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int dp[10000];
int N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(N+1);
    while(true) {
        cin>>X>>Y;
        if(!X && !Y) break;
        v[Y].push_back(X);
    }
    dp[N] = 1;
    for(int i=N;i>0;i--) {
        if(!v[i].empty()) {
            for(auto jump: v[i]) {
                dp[jump]+=dp[i];
            }
        }
    }
    ans = dp[1];
    cout<<ans<<"\n";
    return 0;
}