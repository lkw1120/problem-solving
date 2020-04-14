#include<bits/stdc++.h>
#define MAX 20
using namespace std;
int board[MAX][MAX] = {0};
int visited[MAX][MAX] = {0};
int alpha[26] = {0};
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int R,C,ans;
void move(int x, int y, int cnt) {
    visited[x][y]++;
    alpha[board[x][y]]++;
    cnt++;
    ans = max(cnt,ans);
    for(int i=0;i<4;i++) {
        if(0 <= x+dX[i] && x+dX[i] < R
        && 0 <= y+dY[i] && y+dY[i] < C
        && 0 == visited[x+dX[i]][y+dY[i]]
        && 0 == alpha[board[x+dX[i]][y+dY[i]]]) {
            move(x+dX[i],y+dY[i], cnt);
        }
    }
    alpha[board[x][y]] = 0;
    visited[x][y] = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>R>>C;
    string str;
    for(int i=0;i<R;i++) {
        cin>>str;
        for(int j=0;j<C;j++) {
            board[i][j] = str[j]-'A';
        }
    }
    ans = 0;
    move(0,0,0);
    cout<<ans<<"\n";
    return 0;
}