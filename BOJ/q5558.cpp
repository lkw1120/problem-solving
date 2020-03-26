#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
char matrix[MAX][MAX] = {};
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int H,W,N,t,ans;
pair<int,int> cheese;
void bfs(bool visited[][MAX], int h, int w, int n) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{h,w},0});
    visited[h][w] = false;
    int x,y,cnt;
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        cnt = q.front().second;
        if(matrix[x][y] == n+'0') {
            cheese = {x,y};
            if(t == 0 || t > cnt) t = cnt; 
            return ;
        }
        for(int i=0;i<4;i++) {
            if(0 <= x+dX[i] && x+dX[i] < H
            && 0 <= y+dY[i] && y+dY[i] < W
            && matrix[x+dX[i]][y+dY[i]] != 'X'
            && !visited[x+dX[i]][y+dY[i]]) {
                visited[x+dX[i]][y+dY[i]] = true;
                q.push({{x+dX[i],y+dY[i]},cnt+1});
            }
        }
        q.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>H>>W>>N;    
    for(int i=0;i<H;i++) {
        string str;
        cin>>str;
        for(int j=0;j<W;j++) {
            matrix[i][j] = str[j];
            if(matrix[i][j] == 'S') {
                cheese = {i,j};
            }
        }
    }
    ans = 0;
    for(int n=1;n<=N;n++) { 
        t = 0;
        bool visited[MAX][MAX] = {false};
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                if(matrix[i][j] == '.') visited[i][j] = false;
                if(matrix[i][j] == 'X') visited[i][j] = true;
            }
        }

        int x, y;
        x = cheese.first;
        y = cheese.second;
        visited[x][y] = false;
        bfs(visited,x,y,n);
        matrix[x][y] = '.';
        ans+=t;
    }
    cout<<ans<<"\n";
    return 0;
}