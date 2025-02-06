#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int dp[1001];
int N,R,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(dp,dp+1001,1);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>R>>C;
        if(C < R) swap(R,C);
        v.push_back({R,C});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(v[j].second <= v[i].second) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    ans = *max_element(dp,dp+N);
    cout<<ans<<"\n";
    return 0;
}