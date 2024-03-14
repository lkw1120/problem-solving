#include<bits/stdc++.h>
using namespace std;
char arr[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<int> v;
int N,M;
int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    arr[x][y] = '0';
    int cnt = 0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt++;
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M && arr[dx][dy] == '1') {
                arr[dx][dy] = '0';
                q.push({dx,dy});
            }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(arr[i][j] == '1') {
                v.push_back(bfs(i,j));
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}