#include<bits/stdc++.h>
using namespace std;
int arr[5][5];
bool visited[5][5];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
bool flag;
int R,C,ans;
int find(int x, int y, int d, int next) {
    if(next == 7) {
        flag = true;
        return d;
    }
    fill(&visited[0][0],&visited[4][5],false);
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    visited[x][y] = true;
    int cnt = d;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if(arr[x][y] == next) {
            cnt+=find(x,y,dist,next+1);
            break;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < 5 && 0 <= dy && dy < 5 && !visited[dx][dy] && 0 <= arr[dx][dy]) {
                visited[dx][dy] = true;
                q.push({{dx,dy},dist+1});
            }
        }
    }
    return cnt;
}
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
    ans = find(R,C,0,1);
    if(!flag) ans = -1;
    cout<<ans<<"\n";
    return 0;
}