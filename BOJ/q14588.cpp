#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
vector<pair<int,int>> v;
int adj[301][301];
int N,L,R,Q,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    fill(&adj[0][0],&adj[300][301],INF);
    for(int i=0;i<N;i++) {
        cin>>L>>R;
        v.push_back({L,R});
        adj[i][i] = 0;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i == j) continue;
            if((v[i].first <= v[j].second && v[j].second <= v[i].second) 
            || (v[j].first <= v[i].second && v[i].second <= v[j].second)) {
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    for(int j=0;j<N;j++) {
        for(int i=0;i<N;i++) {
            if(j == i) continue;
            for(int k=0;k<N;k++) {
                if(i == k || j == k) continue;
                if(adj[i][j]+adj[j][k] < adj[i][k]) {
                   adj[i][k] = adj[i][j] + adj[j][k];
                }
            }
        }
    }
    cin>>Q;
    for(int i=0;i<Q;i++) {
        cin>>A>>B;
        A--,B--;
        ans = adj[A][B] != INF? adj[A][B]:-1;
        cout<<ans<<"\n";
    }
    return 0;
}