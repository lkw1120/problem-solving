#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
bool check[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<pair<int,int>> v;
int N,M,H,W,K,R,C,ans;
bool foot(int x, int y) {
    if(N < x+H-1 || M < y+W-1) return false;
    for(int i=x;i<x+H;i++) {
        for(int j=y;j<y+W;j++) {
            if(!check[i][j]) return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    cin>>H>>W;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    cin>>K;
    for(int i=0;i<K;i++) {
        cin>>R>>C;
        v.push_back({R,C});
    }
    queue<pair<int,int>> q;
    for(auto [x,y]: v) {
        q.push({x,y});
        check[x][y] = true;
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M
            && arr[x][y] <= arr[dx][dy] && !check[dx][dy]) {
                check[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(check[i][j] && foot(i,j)) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}