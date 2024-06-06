#include<bits/stdc++.h>
using namespace std;
const int MAX = 51;
char arr1[MAX][MAX];
char arr2[MAX][MAX];
bool visited1[MAX][MAX];
bool visited2[MAX][MAX];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M;
void bfs(int a, int b) {
    queue<pair<int,int>> q;
    q.push({a,b});
    visited1[a][b] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M 
            && !visited1[dx][dy] && arr1[x][y] == arr1[dx][dy]) {
                visited1[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
    q.push({a,b});
    visited2[a][b] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M 
            && !visited2[dx][dy] && arr2[x][y] == arr2[dx][dy]) {
                visited2[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
}
bool check() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(visited1[i][j] && !visited2[i][j]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr1[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr2[i][j];
        }
    }
    bool flag = true;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            fill(&visited1[0][0],&visited1[MAX-1][MAX],false);
            fill(&visited2[0][0],&visited2[MAX-1][MAX],false);
            bfs(i,j);
            if(!check()) {
                flag = false;
            }
        }
    }
    if(flag) {
        cout<<"YES"<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
    }
    return 0;
}