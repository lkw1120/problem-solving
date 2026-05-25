#include<bits/stdc++.h>
using namespace std;
vector<string> s;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int H,W,ans;
bool bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    s[x][y] = '*';
    bool flag = true;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(x == 0 || y == 0 || x == H-1 || y == W-1) {
            flag = false;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < H && 0 <= dy && dy < W && s[dx][dy] == '.') {
                s[dx][dy] = '*';
                q.push({dx,dy});
            }
        }
    }
    return flag;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>H>>W;
    s.resize(H);
    for(int i=0;i<H;i++) {
        cin>>s[i];
    }
    ans = 0;
    for(int i=1;i<H-1;i++) {
        for(int j=1;j<W-1;j++) {
            if(s[i][j] == '.' && bfs(i,j)) {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}