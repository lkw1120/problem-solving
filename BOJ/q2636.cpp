#include<bits/stdc++.h>
using namespace std;
int arr[109][109];
bool visited[109][109];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
int bfs() {
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx <= N+1 && 0 <= dy && dy <= M+1 && !visited[dx][dy]) {
                if(arr[x][y] == 0 && arr[dx][dy] == 1) {
                    visited[dx][dy] = true;
                    arr[dx][dy] = 2;
                    cnt++;
                }
                else if(arr[x][y] == 0 && arr[dx][dy] == 0) {
                    visited[dx][dy] = true;
                    q.push({dx,dy});
                }
            }
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(arr[i][j] == 2) arr[i][j] = 0;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    int t,cnt;
    t = cnt = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
            if(arr[i][j]) cnt++;
        }
    }
    while(cnt) {
        fill(&visited[0][0],&visited[108][109],false);
        ans = bfs();
        cnt-=ans;
        t++;
    }
    cout<<t<<"\n";
    cout<<ans<<"\n";
    return 0;
}