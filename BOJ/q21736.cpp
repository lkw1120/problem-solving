#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;
vector<string> v;
int visited[600][600] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(v[i][j] == 'I') {
                q.push({i,j});
                visited[i][j] = true;
            }
            if(v[i][j] == 'X') {
                visited[i][j] = true;
            }
        }
    }
    ans = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(v[x][y] == 'P') {
            ans++;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < N && 0 <= dy && dy < M) {
                if(visited[dx][dy]) continue;
                visited[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
    if(0 < ans) {
        cout<<ans<<"\n";
    }
    else {
        cout<<"TT"<<"\n";
    }
    return 0;
}