#include<bits/stdc++.h>
#define MAX 20001
using namespace std;
vector<int> graph[MAX];
int visited[MAX];
int K,V,E;
void dfs(int x, int color) {
    visited[x] = color;
    int SIZE = graph[x].size();
    for(int i=0;i<SIZE;i++) {
        if(visited[graph[x][i]] == 0) {
            dfs(graph[x][i],-color);
        } 
    }
}
bool isBipartite() {
    int SIZE;
    for(int i=1;i<=V;i++) {
        SIZE = graph[i].size();
        for(int j=0;j<SIZE;j++) {
            if(visited[i] == visited[graph[i][j]]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>K;
    for(int k=0;k<K;k++) {
        for(int i=0;i<MAX;i++) {
            graph[i].clear();
            visited[i] = 0;
        }
        cin>>V>>E;
        int x,y;
        for(int i=0;i<E;i++) {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int i=1;i<=V;i++) {
            if(visited[i] == 0) dfs(i,1);
        }
        if(isBipartite()) {
            cout<<"YES"<<"\n";
        }
        else {
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}