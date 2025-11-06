#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
char mine[51][51];
int adj[51][51];
bool visited[51][51];
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
int T,N,ans;
void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(adj[x][y] == 0) {
            for(int i=0;i<8;i++) {
                int dx = x+dX[i];
                int dy = y+dY[i];
                if(0 <= dx && dx < N && 0 <= dy && dy < N
                && !visited[dx][dy] && adj[dx][dy] != INF) {
                    visited[dx][dy] = true;
                    q.push({dx,dy});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        fill(&adj[0][0],&adj[0][0]+51*51,0);
        fill(&visited[0][0],&visited[0][0]+51*51,0);
        cin>>N;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin>>mine[i][j];
            }
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(mine[i][j] == '*') {
                    adj[i][j] = INF;
                }
                else {
                    for(int k=0;k<8;k++) {
                        int dx = i+dX[k];
                        int dy = j+dY[k];
                        if(0 <= dx && dx < N && 0 <= dy && dy < N) {
                            if(mine[dx][dy] == '*') {
                                adj[i][j]++;
                            }
                        }
                    }
                }
            }
        }
        ans = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(adj[i][j] == 0 && !visited[i][j]) {
                    bfs(i,j);
                    ans++;
                }
            }
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(adj[i][j] != INF && !visited[i][j]) {
                    ans++;
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}