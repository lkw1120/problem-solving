#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
vector<pair<int,int>> v;
double dp[MAX];
int N,X,Y;
double ans;
double dist(int a, int b) {
    return sqrt(pow(v[b].first-v[a].first,2)+pow(v[b].second-v[a].second,2));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        v.push_back({X,Y});
    }
    sort(v.begin(),v.end());
    ans = 0.0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<i;j++) {
            double d = dist(i,j);
            if(v[j].first < v[i].first) {
                dp[i] = max(dp[i],dp[j]+d);
            }
            ans = max(ans,dp[i]);
        }
    }
    cout.precision(6);
    cout<<fixed<<ans<<"\n";
    return 0;
}