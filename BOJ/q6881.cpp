#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
bool visited[101][101];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M;
bool check(int x, int y, int a, int b, int c) {
    return arr[x][y] == a || arr[x][y] == b || arr[x][y] == c;
}
bool find(int x, int y, int a, int b, int c) {
    fill(&visited[0][0],&visited[100][101],false);
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        if(x == N) {
            return true;
        }
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M 
            && check(dx,dy,a,b,c) && !visited[dx][dy]) {
                visited[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
    return false;
}
bool solve(int a, int b, int c) {
    for(int i=1;i<=M;i++) {
        if(check(1,i,a,b,c) && find(1,i,a,b,c)) {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>M>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<10;i++) {
        for(int j=i;j<10;j++) {
            for(int k=j;k<10;k++) {
                if(solve(i,j,k)) {
                    cout<<i<<" "<<j<<" "<<k<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"-1 -1 -1"<<"\n";
    return 0;
}