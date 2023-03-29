#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int W,H,ans;
int bfs(int x, int y) {
    queue<pair<int,int>> q;
    int cnt = 0;
    q.push({x,y});
    v[x][y] = '#';
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        cnt++;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < H && 0 <= dy && dy < W && v[dx][dy] == '.') {
                v[dx][dy] = '#';
                q.push({dx,dy});   
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true) {
        cin>>W>>H;
        if(!W && !H) break;
        v.resize(H);
        for(int i=0;i<H;i++) {
            cin>>v[i];
        }
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                if(v[i][j] == 'A') {
                    ans = bfs(i,j);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}