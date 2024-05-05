#include<bits/stdc++.h>
using namespace std;
const int MAX = 5001;
vector<pair<int,int>> v[MAX];
bool visited[MAX];
int N,M,P,Q,R,K,V,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N-1;i++) {
        cin>>P>>Q>>R;
        v[P].push_back({Q,R});
        v[Q].push_back({P,R});
    }
    for(int i=0;i<M;i++) {
        fill(visited,visited+MAX,false);
        cin>>K>>V;
        queue<int> q;
        q.push(V);
        visited[V] = true;
        ans = 0;
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(auto item: v[now]) {
                int next = item.first;
                int k = item.second;
                if(K <= k && !visited[next]) {
                    visited[next] = true;
                    q.push(next);
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}