#include<bits/stdc++.h>
using namespace std;
char arr[12][12];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int dist[12][12];
int N,M,E,ans;
int find(int x, int y) {
    fill(&dist[0][0],&dist[10][11],0);
    queue<pair<int,int>> q;
    q.push({1,E});
    dist[1][E] = 1;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        if(x == 0 || x == N+1 || y == 0 || y == M+1) {
            break;
        }
        ans++;
        q.pop();
        int dx,dy;
        if(arr[x][y] == 'E') {
            dx = x+dX[0];
            dy = y+dY[0];
        }
        else if(arr[x][y] == 'S') {
            dx = x+dX[1];
            dy = y+dY[1];
        }
        else if(arr[x][y] == 'W') {
            dx = x+dX[2];
            dy = y+dY[2];
        }
        else if(arr[x][y] == 'N') {
            dx = x+dX[3];
            dy = y+dY[3];
        }
        if(dist[dx][dy] != 0) {
            return dist[x][y]-dist[dx][dy]+1;
        }
        else {
            dist[dx][dy] = dist[x][y]+1;
            q.push({dx,dy});
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>N>>M>>E;
        if(!N && !M && !E) break;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) {
                cin>>arr[i][j];
            }
        }
        ans = 0;
        int loop = find(1,E);
        if(loop) {
            ans-=loop;
            cout<<ans<<" step(s) before a loop of "<<loop<<" step(s)"<<"\n";
        }
        else {
            cout<<ans<<" step(s) to exit"<<"\n";
        }
    }   
    return 0;
}