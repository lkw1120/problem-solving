#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int N, M, V;
int matrix[MAX][MAX];
int visited[MAX];
void dfs(int v) {
	cout<<v<<" ";
    visited[v] = 1;
    for(int i=1;i<=N;i++){
        if(matrix[v][i]==1 && visited[i]==0) {
            dfs(i);
        }
    }
}
void bfs(int v) {
    queue<int> que;
    que.push(v);
    visited[v] = 0;
    while(!que.empty()) {
        v = que.front();
        cout<<v<<" ";
        que.pop();
        for(int i=1;i<=N;i++) {
            if(matrix[v][i]==1 && visited[i]==1) {
                visited[i] = 0;
                que.push(i);
            }
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin>>N>>M>>V;
    int x,y;
    for(int i=0;i<M;i++) {
		cin>>x>>y;
        matrix[x][y] = matrix[y][x] = 1;
    }
    dfs(V);
	cout<<"\n";
    bfs(V);
	cout<<"\n";
	return 0;
}