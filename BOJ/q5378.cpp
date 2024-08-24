#include<bits/stdc++.h>
using namespace std;
char arr[101][101];
int dX[6] = {0,1,1,0,-1,-1};
int dY[6] = {1,0,-1,-1,0,1};
int T,N,ans;
void find(int x, int y, char ch) {
    queue<pair<int,int>> q;
    q.push({x,y});
    char stone = arr[x][y];
    arr[x][y] = ch;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<6;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= N && arr[dx][dy] == stone) {
                arr[dx][dy] = ch;
                q.push({dx,dy});
            }
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<=N;i++) {
            if(arr[i][1] == 'W') {
                find(i,1,'$');
            }
            if(arr[1][i] == 'B') {
                find(1,i,'&');
            }
        }
        ans = 0;
        for(int i=1;i<=N;i++) {
            if(arr[i][N] == '$') {
                ans = 1;
            }
            if(arr[N][i] == '&') {
                ans = 2;
            }
        }
        if(ans == 0) {
            cout<<"Not finished"<<"\n";
        }
        else if(ans == 1) {
            cout<<"White wins"<<"\n";
        }
        else if(ans == 2) {
            cout<<"Black wins"<<"\n";
        }
    }
    return 0;
}