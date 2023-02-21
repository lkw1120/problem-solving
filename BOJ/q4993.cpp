#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int W,H;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>W>>H) {
        if(W == 0 || H == 0) break;
        vector<string> v(H);
        int x,y,ans;
        for(int i=0;i<H;i++) {
            cin>>v[i];
            for(int j=0;j<W;j++) {
                if(v[i][j] == '@') {
                    x = i, y = j;
                }
            }
        }
        queue<pair<int,int>> q;
        q.push({x,y});
        v[x][y] = '#';
        ans = 0;
        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            ans++;
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
        cout<<ans<<"\n";
    }
    return 0;
}