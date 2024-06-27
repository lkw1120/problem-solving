#include<bits/stdc++.h>
using namespace std;
bool visited[101][101];
int dX[8] = {-2,-1,1,2,2,1,-1,-2};
int dY[8] = {1,2,2,1,-1,-2,-2,-1};
int R,C,A,B,X,Y,ans;
int find(int x, int y) {
    fill(&visited[0][0],&visited[100][101],false);
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    visited[x][y] = true;
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(x == X && y == Y) {
            return d;
        }
        for(int i=0;i<8;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= R && 0 < dy && dy <= C && !visited[dx][dy]) {
                visited[dx][dy] = true;
                q.push({{dx,dy},d+1});
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(!cin.eof()) {
        cin>>R>>C>>A>>B>>X>>Y;
        if(cin.eof()) break;
        ans = find(A,B);
        if(ans != -1) {
            cout<<ans<<"\n";
        }
        else {
            cout<<"impossible"<<"\n";
        }
    }
    return 0;
}