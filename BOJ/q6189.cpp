#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C,ans;
void bfs(int x, int y) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    int dist = 0;
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        dist = q.front().second;
        q.pop();
        if(v[x][y] == 'C') {
            ans = min(ans,dist);
            break;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < R && 0 <= dy && dy < C 
            && (v[dx][dy] == '.' || v[dx][dy] == 'C')) {
                if(v[dx][dy] == '.') {
                    v[dx][dy] = 'm';
                }
                q.push({{dx,dy},dist+1});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>R>>C;
    v.resize(R);
    for(int i=0;i<R;i++) {
        cin>>v[i];
    }
    ans = INT_MAX;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(v[i][j] == 'B') {
                bfs(i,j);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}