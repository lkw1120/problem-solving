#include<bits/stdc++.h>
using namespace std;
int arr[5][5];
int dist[5][5];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C,ans;
void find(int x, int y, int move, int cnt) {
    if(cnt == 3) {
        ans = min(ans,move);
        return ;
    }
    for(int i=0;i<4;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
        if(0 <= dx && dx < 5 && 0 <= dy && dy < 5) {
            if(arr[dx][dy] == 1) {
                arr[dx][dy] = -1;
                find(dx,dy,move+1,cnt+1);
                arr[dx][dy] = 1;
            }
            else if(arr[dx][dy] == 0) {
                arr[dx][dy] = -1;
                find(dx,dy,move+1,cnt);
                arr[dx][dy] = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin>>arr[i][j];
        }
    }
    cin>>R>>C;
    ans = INT_MAX;
    arr[R][C] = -1;
    find(R,C,0,0);
    if(ans == INT_MAX) {
        ans = -1;
    }
    cout<<ans<<"\n";
    return 0;
    
}