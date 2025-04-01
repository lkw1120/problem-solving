#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;
const int MAX = 1e6+1;
ll dp[MAX][2];
ll N,day,water;
void find() {
    queue<tuple<ll,ll,ll>> q;
    q.push({1,1,1});
    ll next,nd,nw;
    while(!q.empty()) {
        auto [n,d,w] = q.front();
        q.pop();
        next = n+1;
        if(next <= N) {
            nd = d+1;
            nw = w+1;
            if(nd < dp[next][0] || (nd == dp[next][0] && nw < dp[next][1])) {
                dp[next][0] = nd;
                dp[next][1] = nw;
                q.push({next, nd, nw});
            }
        }
        next = n*3;
        if(next <= N) {
            nd = d+1;
            nw = w+3;
            if(nd < dp[next][0] || (nd == dp[next][0] && nw < dp[next][1])) {
                dp[next][0] = nd;
                dp[next][1] = nw;
                q.push({next, nd, nw});
            }
        }
        next = n*n;
        if(next <= N) {
            nd = d+1;
            nw = w+5;
            if(nd < dp[next][0] || (nd == dp[next][0] && nw < dp[next][1])) {
                dp[next][0] = nd;
                dp[next][1] = nw;
                q.push({next, nd, nw});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    fill(&dp[0][0],&dp[MAX-1][2],INF);
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = dp[1][1] = 1;
    find();
    day = dp[N][0];
    water = dp[N][1];
    cout<<day<<" "<<water<<"\n";
    return 0;
}