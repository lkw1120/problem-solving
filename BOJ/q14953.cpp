#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
vector<int> v[MAX];
int adj[MAX];
int dp[MAX];
int N,M,A,B,ans;
int find(int now) {
    if(dp[now]) return dp[now];
    int cnt = 1;
    for(int next: v[now]) {
        if(adj[now] < adj[next]) {
            cnt = max(find(next)+1,cnt);
        }
    }
    return dp[now] = cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        v[A].push_back(B);
        v[B].push_back(A);
        adj[A]++;
        adj[B]++;
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        ans = max(find(i),ans);
    }
    cout<<ans<<"\n";
    return 0;
}