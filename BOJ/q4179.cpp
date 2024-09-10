#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
char arr[1001][1001];
int fire[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<pair<int,int>> v;
int R,C,X,Y,ans;
void burning() {
    fill(&fire[0][0],&fire[1000][1001],INF);
    queue<pair<int,int>> q;
    for(auto [a,b]: v) {
        q.push({a,b});
        fire[a][b] = 0;
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= R && 0 < dy && dy <= C && arr[dx][dy] != '#' && fire[dx][dy] == INF) {
                fire[dx][dy] = fire[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
    return ;
}
int run() {
    queue<pair<int,int>> q;
    q.push({X,Y});
    fire[X][Y] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == 1 || x == R || y == 1 || y == C) {
            return fire[x][y]+1;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= R && 0 < dy && dy <= C && arr[dx][dy] != '#' && fire[x][y]+1 < fire[dx][dy]) {
                fire[dx][dy] = fire[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>R>>C;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 'F') {
                v.push_back({i,j});
            }
            if(arr[i][j] == 'J') {
                X = i,Y = j;
            }
        }
    }
    burning();
    ans = run();
    if(0 < ans) {
        cout<<ans<<"\n";
    }
    else {
        cout<<"IMPOSSIBLE"<<"\n";
    }
    return 0;
}