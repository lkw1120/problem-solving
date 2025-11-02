#include<bits/stdc++.h>
using namespace std;
char world[101][101];
bool visited[101][101];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    int r,c;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cin>>world[i][j];
            if(world[i][j] == 'S') {
                r = i,c = j;
                world[i][j] = '#';
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;
    ans = 0;
    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        ans++;
        for(int i=0;i<4;i++) {
            int dx = r+dX[i];
            int dy = c+dY[i];
            if(0 < dx && dx <= R && 0 < dy && dy <= C 
            && world[dx][dy] == '#' && !visited[dx][dy]) {
                visited[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}