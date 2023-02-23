#include<bits/stdc++.h>
using namespace std;
int arr[5][5] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin>>arr[i][j];
        }
    }
    cin>>R>>C;
    queue<pair<pair<int,int>,int>> q;
    q.push({{R,C},0});
    ans = -1;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(arr[x][y] == 1) {
            ans = d;
            break;
        }
        arr[x][y] = -1;
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < 5 && 0 <= dy && dy < 5 && arr[dx][dy] != -1) {
                q.push({{dx,dy},d+1});
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}