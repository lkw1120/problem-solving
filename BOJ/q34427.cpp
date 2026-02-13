#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<pair<int,int>> v;
int W,H,X,Y,C;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>W>>H>>X>>Y;
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            cin>>arr[i][j];
        }
    }
    C = arr[Y][X];
    queue<pair<int,int>> q;
    arr[Y][X] = -1;
    q.push({Y,X});
    v.push_back({Y,X});
    while(!q.empty()) {
        auto [y,x] = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < W && 0 <= dy && dy < H && arr[dy][dx] == C) {
                arr[dy][dx] = -1;
                q.push({dy,dx});
                v.push_back({dy,dx});
            }
        }
    }
    sort(v.begin(),v.end());
    for(auto [y,x]: v) {
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}