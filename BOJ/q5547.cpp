#include<bits/stdc++.h>
using namespace std;
int arr[102][102];
int dX[6] = {-1,0,1,1,0,-1};
int dY[2][6] = {
    {0,1,0,-1,-1,-1},
    {1,1,1,0,-1,0}
};
bool visited[102][102];
int W,H,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>W>>H;
    for(int i=1;i<=H;i++) {
        for(int j=1;j<=W;j++) {
            cin>>arr[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    ans = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<6;i++) {
            int dx = x+dX[i];
            int dy = y+dY[x%2][i];
            if(0 <= dx && dx <= H+1 && 0 <= dy && dy <= W+1 && !visited[dx][dy]) {
                if(arr[dx][dy]) {
                    ans++;
                }
                else {
                    visited[dx][dy] = true;
                    q.push({dx,dy});
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}