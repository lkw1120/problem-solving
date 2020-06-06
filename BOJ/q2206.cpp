#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int matrix[MAX][MAX] = {0};
int dist[MAX][MAX][2] = {0};
bool visit[MAX][MAX][2] = {false};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
int bfs(int y, int x, int broken) {
    queue<tuple<int,int,int>> q;
    q.push({y,x,broken});
    dist[y][x][broken] = 1;
    while(!q.empty()) {
        y = get<0>(q.front());
        x = get<1>(q.front());
        broken = get<2>(q.front());
        q.pop();
        if(y == N-1 && x == M-1) {
            return dist[y][x][broken];
        }
        for(int i=0;i<4;i++) {
            if(0 <= y+dY[i] && y+dY[i] < N && 0 <= x+dX[i] && x+dX[i] < M) {
                if(matrix[y+dY[i]][x+dX[i]] == 1 && broken == 0) {
                    dist[y+dY[i]][x+dX[i]][broken+1] = dist[y][x][broken]+1;
                    visit[y+dY[i]][x+dX[i]][broken+1] = true;
                    q.push({y+dY[i],x+dX[i],broken+1});
                }
                else if(matrix[y+dY[i]][x+dX[i]] == 0 && !visit[y+dY[i]][x+dX[i]][broken]) {
                    dist[y+dY[i]][x+dX[i]][broken] = dist[y][x][broken]+1;
                    visit[y+dY[i]][x+dX[i]][broken] = true;
                    q.push({y+dY[i],x+dX[i],broken});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    string str;
    for(int i=0;i<N;i++) {
        cin>>str;
        for(int j=0;j<M;j++) {
            matrix[i][j] = str[j]-'0';
        }
    }
    ans = bfs(0,0,0);
    cout<<ans<<"\n";
    return 0;
}