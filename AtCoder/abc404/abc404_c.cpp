#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
int N,M,A,B,ans;
void dfs(int cur) {
    visited[cur] = true;
    for(auto next: graph[cur]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    graph.resize(N+1);
    visited.resize(N+1);
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    if(N != M) {
        cout<<"No"<<"\n";
        return 0;
    }
    for(int i=1;i<=N;i++) {
        if(graph[i].size() != 2) {
            cout<<"No"<<"\n";
            return 0;
        }
    }
    dfs(1);
    for(int i=1;i<=N;i++) {
        if(!visited[i]) {
            cout<<"No"<<"\n";
            return 0;
        }
    }
    cout<<"Yes"<<"\n";
    return 0;
}