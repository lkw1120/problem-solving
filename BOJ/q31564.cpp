#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dY[6] = {-1,0,1,1,0,-1};
int dX1[6] = {1,1,1,0,-1,0};
int dX2[6] = {0,1,0,-1,-1,-1};
int N,M,K,Y,X,ans;
void solve() {
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    arr[0][0] = 1;
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(y == N-1 && x == M-1) {
            ans = d;
            break;
        }
        for(int i=0;i<6;i++) {
            int dy,dx;
            dy = y+dY[i];
            if(y%2) {
                dx = x+dX1[i];
            }
            else {
                dx = x+dX2[i];
            }
            if(0 <= dy && dy < N && 0 <= dx && dx < M && !arr[dy][dx]) {
                arr[dy][dx] = 1;
                q.push({{dy,dx},d+1});
            }
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<K;i++) {
        cin>>Y>>X;
        arr[Y][X] = 1;
    }
    solve();
    if(!ans) ans = -1;
    cout<<ans<<"\n";
    return 0;
}