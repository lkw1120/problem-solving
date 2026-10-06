#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
vector<int> v = {6,9};
int dp[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        dp[i] = i;
    }
    for(auto item: v) {
        for(int i=0;i<=N;i++) {
            for(int j=1;i+pow(item,j)<=N;j++) {
                int next = i+pow(item,j);
                dp[next] = min(dp[next],dp[i]+1);
            }
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}