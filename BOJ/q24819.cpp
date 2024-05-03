#include<bits/stdc++.h>
using namespace std;
char arr[101][101];
char ch[4] = {'L','U','R','D'};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int T,N,M,X,Y,ans;
int solve(int x, int y) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    arr[x][y] = '1';
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(x == 1 || y == 1 || x == N || y == M) {
            return d;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M && arr[dx][dy] != '1') {
                if(arr[dx][dy] == '0' || arr[dx][dy] == ch[i]) {
                    arr[dx][dy] = '1';
                    q.push({{dx,dy},d+1});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 'S') {
                X = i,Y = j;
            }
        }
    }
    ans = solve(X,Y);
    if(0 <= ans && ans <= T) {
        cout<<ans<<"\n";
    }
    else {
        cout<<"NOT POSSIBLE"<<"\n";
    }
    return 0;
}