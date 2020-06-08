#include<bits/stdc++.h>
using namespace std;
const int MAX = 51;
queue<pair<int,int>> wq;
queue<pair<int,int>> sq;
char matrix[MAX][MAX] = {};
int water[MAX][MAX] = {0};
int dist[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C,ans;
void flood() {
    int y,x,d,nY,nX;
    while(!wq.empty()) {
        y = wq.front().first;
        x = wq.front().second;
        d = water[y][x];
        wq.pop();
        for(int i=0;i<4;i++) {
            nY = y+dY[i];
            nX = x+dX[i];
            if(0 <= nY && nY < R && 0 <= nX && nX < C) {
                if(water[nY][nX] == 0 && matrix[nY][nX] == '.') {
                    water[nY][nX] = d+1;
                    wq.push({nY,nX});
                }
            }
        }
    }
}
void bfs() {
    int y,x,d,nY,nX;
    while(!sq.empty()) {
        y = sq.front().first;
        x = sq.front().second;
        d = dist[y][x];
        sq.pop();
        for(int i=0;i<4;i++) {
            nY = y+dY[i];
            nX = x+dX[i];
            if(0 <= nY && nY < R && 0 <= nX && nX < C) {
                if((matrix[nY][nX] == '.' || matrix[nY][nX] == 'D') && dist[nY][nX] == 0) {
                    if(water[nY][nX] == 0 || water[nY][nX] > d+1) {
                        dist[nY][nX] = d+1;
                        sq.push({nY,nX});
                    }
                }
            }
        }
    }
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C;
    string str;
    int y,x;
    for(int i=0;i<R;i++) {
        cin>>str;
        for(int j=0;j<C;j++) {
            matrix[i][j] = str[j];
            if(str[j] == 'S') {
                sq.push({i,j});
            }
            if(str[j] == '*') {
                wq.push({i,j});
            }
            if(str[j] == 'D') {
                y = i, x = j;
            }
        }
    }
    flood();
    bfs();
    ans = dist[y][x];
    if(ans > 0) {
        cout<<ans<<"\n";
    }
    else {
        cout<<"KAKTUS"<<"\n";
    }
    return 0;
}