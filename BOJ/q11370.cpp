#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<string> v;
int W,H;
void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < H && 0 <= dy && dy < W && v[dx][dy] == 'T') {
                v[dx][dy] = 'S';
                q.push({dx,dy}); 
            }
        }
    }
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
                if(v[i][j] == 'S') {
                    bfs(i,j);
                }
            }
        }
        for(int i=0;i<H;i++) {
            cout<<v[i]<<"\n";
        }
        v.clear();
    }
    return 0;
}