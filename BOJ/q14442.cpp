#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
char arr[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int dist[1001][1001][10];
int N,M,K,ans;
int find(int x, int y, int k) {
    fill(&dist[0][0][0],&dist[1000][1000][10],INF);
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},0});
    dist[1][1][0] = 1;
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        k = q.front().second;
        q.pop();
        if(x == N && y == M) {
            return dist[x][y][k];
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M) {
                if(arr[dx][dy] == '1' && k+1 <= K && dist[dx][dy][k+1] == INF) {
                    dist[dx][dy][k+1] = dist[x][y][k]+1;
                    q.push({{dx,dy},k+1});
                }
                else if(arr[dx][dy] == '0' && dist[dx][dy][k] == INF) {
                    dist[dx][dy][k] = dist[x][y][k]+1;
                    q.push({{dx,dy},k});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    ans = find(1,1,0);
    cout<<ans<<"\n";
    return 0;
}