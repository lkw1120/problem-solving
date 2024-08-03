#include<bits/stdc++.h>
using namespace std;
int dX[4] = {1,1,-1,-1};
int dY[4] = {1,-1,1,-1};
int arr[2][2];
bool check[501][501][2];
int N,ans;
void find(int p) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},p});
    check[1][1][p] = true;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int p = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx,dy;
            dx = x+dX[i]*arr[p][0];
            dy = y+dY[i]*arr[p][1];
            if(0 < dx && dx <= N && 0 < dy && dy <= N && !check[dx][dy][p]) {
                check[dx][dy][p] = true;
                q.push({{dx,dy},1-p});
            }
            dx = x+dX[i]*arr[p][1];
            dy = y+dY[i]*arr[p][0];
            if(0 < dx && dx <= N && 0 < dy && dy <= N && !check[dx][dy][p]) {
                check[dx][dy][p] = true;
                q.push({{dx,dy},1-p});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<2;i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    find(0);
    find(1);
    ans = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(check[i][j][0] || check[i][j][1]) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}