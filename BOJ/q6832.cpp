#include<bits/stdc++.h>
using namespace std;
char arr[21][21];
int dist[21][21];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int T,R,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        fill(&dist[0][0],&dist[0][0]+21*21,-1);
        cin>>R>>C;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                cin>>arr[i][j];
            }
        }
        queue<pair<int,int>> q;
        dist[0][0] = 1;
        q.push({0,0});
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            char cell = arr[x][y];
            if(cell == '*') continue;
            vector<int> v;
            if(cell == '+') v = {0,1,2,3};
            if(cell == '-') v = {0,2};
            if(cell == '|') v = {1,3};
            for(int a: v) {
                int dx = x+dX[a];
                int dy = y+dY[a];
                if(0 <= dx && dx < R && 0 <= dy && dy < C) {
                    if(arr[dx][dy] == '*') continue;
                    if(dist[dx][dy] != -1) continue;
                    dist[dx][dy] = dist[x][y]+1;
                    q.push({dx,dy});
                }
            }
        }
        ans = dist[R-1][C-1];
        cout<<ans<<"\n";
    }
}