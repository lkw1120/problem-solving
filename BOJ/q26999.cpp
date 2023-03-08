#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int W,H,ans;
void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    v[x][y] = '.';
    int cnt = 0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt++;
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < H && 0 <= dy && dy < W) {
                if(v[dx][dy] == '.') continue;
                v[dx][dy] = '.';
                q.push({dx,dy});
            }
        }
    }
    ans = max(ans,cnt);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>W>>H;
    v.resize(H);
    for(int i=0;i<H;i++) {
        cin>>v[i];
    }
    ans = 0;
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            if(v[i][j] == '*') {
                bfs(i,j);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}