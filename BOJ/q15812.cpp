#include<bits/stdc++.h>
using namespace std;
char arr[21][21];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
bool visited[21][21];
vector<pair<int,int>> v;
int N,M,town,ans;
int find(int a, int b) {
    fill(&visited[0][0],&visited[20][21],false);
    queue<pair<int,int>> q;
    visited[v[a].first][v[a].second] = true;
    visited[v[b].first][v[b].second] = true;
    q.push(v[a]);
    q.push(v[b]);
    int cnt,t;
    cnt = t = 0;
    while(!q.empty()) {
        int size = q.size();
        if(cnt == town) {
            return t;
        }
        while(size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx = x+dX[i];
                int dy = y+dY[i];
                if(0 <= dx && dx < N && 0 <= dy && dy < M && !visited[dx][dy]) {
                    if(arr[dx][dy] == '1') {
                        cnt++;
                    }
                    visited[dx][dy]=true;
                    q.push({dx,dy});
                }
            }
        }
        t++;
    }
    return t;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == '0') {
                v.push_back({i,j});
            }
            else {
                town++;
            }
        }
    }
    int size = v.size();
    ans = INT_MAX;
    for(int i=0;i<size;i++) {
        for(int j=i+1;j<size;j++) {
            ans = min(find(i,j),ans);
        }
    }
    cout<<ans<<"\n";
    return 0;
}