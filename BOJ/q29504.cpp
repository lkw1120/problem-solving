#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
map<int,bool> mp;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int n,m,k;
int bfs(int x, int y) {
    int p = arr[x][y];
    int cnt = 1;
    queue<pair<int,int>> q;
    q.push({x,y});
    arr[x][y] = -1;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < n && 0 <= dy && dy < m && arr[dx][dy] == p) {
                arr[dx][dy] = -1;
                q.push({dx,dy});
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    bool flag = true;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(0 < arr[i][j]) {
                if(mp[arr[i][j]]) {
                    flag = false;
                }
                else {
                    mp[arr[i][j]] = true;
                    if(bfs(i,j) != k) {
                        flag = false;
                    }
                }
            }
        }
    }
    cout<<(flag? "OK": "Wrong answer")<<"\n";
    return 0;
}