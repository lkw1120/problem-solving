#include<bits/stdc++.h>
using namespace std;
int arr[1024][1024];
bool visited[1024][1024];
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
int H,W,S,L,R,G,B,ans;
int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    int pixel = arr[x][y];
    int cnt = 0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt++;
        for(int i=0;i<8;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < H && 0 <= dy && dy < W 
            && pixel == arr[dx][dy] && !visited[dx][dy]) {
                visited[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin>>H>>W>>S>>L;
        if(!H && !W && !S && !L) break;
        fill(&arr[0][0],&arr[0][0]+1024*1024,0);
        fill(&visited[0][0],&visited[0][0]+1024*1024,0);
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                cin>>R>>G>>B;
                R/=S,G/=S,B/=S;
                arr[i][j] = (R<<16) | (G<<8) | B;
            }
        }
        ans = 0;
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                if(!visited[i][j]) {
                    int cnt = bfs(i,j);
                    if(L <= cnt) ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}