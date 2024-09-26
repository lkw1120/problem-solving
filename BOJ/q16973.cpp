#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,H,W,S1,S2,F1,F2,ans;
bool check(int x, int y, int k) {
    if(k == 0) {
        int dy = y+W;
        if(M < dy) return false;
        for(int i=0;i<H;i++) {
            if(arr[x+i][dy] < 0) return false;
        }
    }
    else if(k == 1) {
        int dx = x+H;
        if(N < dx) return false;
        for(int j=0;j<W;j++) {
            if(arr[dx][y+j] < 0) return false;
        }
    }
    else if(k == 2) {
        int dy = y-1;
        if(dy == 0) return false;
        for(int i=0;i<H;i++) {
            if(arr[x+i][dy] < 0) return false;
        }
    }
    else if(k == 3) {
        int dx = x-1;
        if(dx == 0) return false;
        for(int j=0;j<W;j++) {
            if(arr[dx][y+j] < 0) return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
            arr[i][j]*=-1;
        }
    }
    cin>>H>>W>>S1>>S2>>F1>>F2;
    arr[S1][S2] = 1;
    queue<pair<int,int>> q;
    q.push({S1,S2});
    ans = -1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == F1 && y == F2) {
            ans = arr[x][y]-1;
            break;
        }
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(check(x,y,i) && !arr[dx][dy]) {
                arr[dx][dy] = arr[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}