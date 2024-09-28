#include<bits/stdc++.h>
using namespace std;
char arr[10][10];
vector<pair<int,int>> v;
int dX[4] = {1,1,-1,-1};
int dY[4] = {1,-1,1,-1};
int T,ans;
void find(int x, int y, int cnt) {
    ans = max(cnt,ans);
    for(int i=0;i<4;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
        int ddx = x+dX[i]*2;
        int ddy = y+dY[i]*2;
        if(0 <= ddx && ddx < 10 && 0 <= ddy && ddy < 10 
        && arr[dx][dy] == 'B' && arr[ddx][ddy] == '#') {
            arr[dx][dy] = '#';
            find(ddx,ddy,cnt+1);
            arr[dx][dy] = 'B';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        v.clear();
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                cin>>arr[i][j];
                if(arr[i][j] == 'W') {
                    v.push_back({i,j});
                }
            }
        }
        ans = 0;
        for(auto [x,y]: v) {
            arr[x][y] = '#';
            find(x,y,0);
            arr[x][y] = 'W';
        }
        cout<<ans<<"\n";
    }
    return 0;
}