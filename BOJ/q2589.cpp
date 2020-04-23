#include<bits/stdc++.h>
#define MAX 50
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int matrix[MAX][MAX];
int L,W,ans;
int bfs(int y, int x) {
    int cnt;
    bool visited[MAX][MAX];
    memset(visited,false,sizeof(visited));
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{y,x}});
    visited[y][x] = true;
    while(!q.empty()) {
        y = q.front().second.first;
        x = q.front().second.second;
        cnt = q.front().first;
        q.pop();
        for(int i=0;i<4;i++) {
            if(0 <= y+dY[i] && y+dY[i] < L
            && 0 <= x+dX[i] && x+dX[i] < W
            && matrix[y+dY[i]][x+dX[i]] == 1 
            && !visited[y+dY[i]][x+dX[i]]) {
                visited[y+dY[i]][x+dX[i]] = true;
                q.push({cnt+1,{y+dY[i],x+dX[i]}});
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>L>>W;
    string str;
    for(int i=0;i<L;i++) {
        cin>>str;
        for(int j=0;j<W;j++) {
            matrix[i][j] = str[j] == 'W'? 0:1;
        }
    }
    ans = 0;
    for(int i=0;i<L;i++) {
        for(int j=0;j<W;j++) {
            if(matrix[i][j]) {
                ans = max(ans,bfs(i,j));
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}