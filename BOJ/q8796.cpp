#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
vector<int> adj[MAX];
bool visited[MAX];
int dist[MAX];
int arrive[MAX];
int T,N,M,K,A,B,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        for(int i=0;i<MAX;i++) {
            adj[i].clear();
            visited[i] = false;
            dist[i] = arrive[i] = 0;
        }
        cin>>N>>M>>K;
        for(int i=0;i<M;i++) {
            cin>>A>>B;
            adj[A].push_back(B);
            adj[B].push_back(A);
        }
        queue<int> q;
        q.push(1);
        visited[1] = true;
        dist[1] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto next: adj[cur]) {
                if(!visited[next]) {
                    visited[next] = true;
                    dist[next] = dist[cur]+1;
                    q.push(next);
                }
            }
        }
        for(int i=2;i<=N;i++) {
            if(0 < dist[i]) arrive[dist[i]]++;
        }
        ans = -1;
        for(int i=1;i<=N;i++) {
            if(K < arrive[i]) {
                ans = i;
                break;
            }
        }
        if(0 < ans) {
            cout<<ans<<"\n";
        }
        else {
            cout<<"hurray!"<<"\n";
        }
    }
    return 0;
}