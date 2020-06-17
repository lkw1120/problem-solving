#include<bits/stdc++.h>
using namespace std;
const int MAX = 201;
int matrix[MAX][MAX] = {0};
bool visit[MAX][MAX][31] = {false};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int hX[8] = {1,2,2,1,-1,-2,-2,-1};
int hY[8] = {-2,-1,1,2,2,1,-1,-2};
int K,W,H,ans;
int bfs(int y, int x, int cnt, int k) {
    queue<tuple<pair<int,int>,int,int>> q;
    q.push({{y,x},cnt,k});
    visit[0][0][0] = true;
    while(!q.empty()) {
        y = get<0>(q.front()).first;
        x = get<0>(q.front()).second;
        cnt = get<1>(q.front());
        k = get<2>(q.front());
        q.pop();
        if(y == H-1 && x == W-1) {
            return cnt;
        }
        if(k < K) {
            for(int i=0;i<8;i++) {
                int nX = x+hX[i];
                int nY = y+hY[i];
                if(0 <= nX && nX < W && 0 <= nY && nY < H) {
                    if(!matrix[nY][nX] && !visit[nY][nX][k+1]) {
                        visit[nY][nX][k+1] = true;
                        q.push({{nY,nX},cnt+1,k+1});
                    }
                }
            }
        }
        for(int i=0;i<4;i++) {
            int nX = x+dX[i];
            int nY = y+dY[i];
            if(0 <= nX && nX < W && 0 <= nY && nY < H) {
                if(!matrix[nY][nX] && !visit[nY][nX][k]) {
                    visit[nY][nX][k] = true;
                    q.push({{nY,nX},cnt+1,k});
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
    cin>>K;
    cin>>W>>H;
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            cin>>matrix[i][j];
        }
    }
    ans = bfs(0,0,0,0);
    cout<<ans<<"\n";
    return 0;
}