#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int dist[1001][1001][2];
pair<int,int> p[2];
int N,M,hx,hy,ex,ey,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    cin>>hx>>hy>>ex>>ey;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{hx,hy},0});
    dist[hx][hy][0] = 0;
    ans = -1;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int broken = q.front().second;
        q.pop();
        if(x == ex && y == ey) {
            ans = dist[x][y][broken];
            break;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M && !dist[dx][dy][broken]) {
                if(broken) {
                    if(arr[dx][dy] == 0) {
                        dist[dx][dy][1] = dist[x][y][1]+1;
                        q.push({{dx,dy},1});
                    }
                }
                else {
                    if(arr[dx][dy] == 0) {
                        dist[dx][dy][0] = dist[x][y][0]+1;
                        q.push({{dx,dy},0});
                    }
                    else {
                        dist[dx][dy][1] = dist[x][y][0]+1;
                        q.push({{dx,dy},1});
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}