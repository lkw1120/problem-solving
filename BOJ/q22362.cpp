#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
bool check[101][101];
vector<pair<int,int>> v;
int W,H,N,D,B,X,Y,ans;
void game(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            for(int j=1;j<=D;j++) {
                int dx = x+dX[i]*j;
                int dy = y+dY[i]*j;
                if(0 < dx && dx <= W && 0 < dy && dy <= H && !check[dx][dy] && arr[dx][dy]) {
                    check[dx][dy] = true;
                    q.push({dx,dy});
                }
            }
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        fill(&arr[0][0],&arr[100][101],0);
        fill(&check[0][0],&check[100][101],false);
        v.clear();
        cin>>W>>H>>N>>D>>B;
        if(!W && !H && !N && !D && !B) break;
        for(int i=0;i<N;i++) {
            cin>>X>>Y;
            arr[X][Y] = 1;
            v.push_back({X,Y});
        }
        game(v[B-1].first,v[B-1].second);
        ans = 0;
        for(int i=1;i<=W;i++) {
            for(int j=1;j<=H;j++) {
                if(arr[i][j] && check[i][j]) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}