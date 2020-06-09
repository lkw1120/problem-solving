#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
char matrix[MAX][MAX] = {};
int fire[MAX][MAX] = {0};
int run[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int T,H,W,ans;
void fireBfs(queue<pair<int,int>> fq) {
    int y,x,d,nY,nX;
    while(!fq.empty()) {
        y = fq.front().first;
        x = fq.front().second;
        d = fire[y][x];
        fq.pop();
        for(int i=0;i<4;i++) {
            nY = y+dY[i];
            nX = x+dX[i];
            if(0 <= nY && nY < H && 0 <= nX && nX < W) {
                if(matrix[nY][nX] == '.' && fire[nY][nX] == 0) {
                    fire[nY][nX] = d+1;
                    fq.push({nY,nX});
                }
            }
        }
    }
}
void runBfs(queue<pair<int,int>> rq) {
    int y,x,d,nY,nX;
    while(!rq.empty()) {
        y = rq.front().first;
        x = rq.front().second;
        d = run[y][x];
        rq.pop();
        if(y == 0 || y == H-1 || x == 0 || x == W-1) {
            ans = (ans == -1)? d+1:min(ans,d+1);
        }
        for(int i=0;i<4;i++) {
            nY = y+dY[i];
            nX = x+dX[i];
            if(0 <= nY && nY < H && 0 <= nX && nX < W) {
                if(matrix[nY][nX] == '.' && run[nY][nX] == 0) {
                    if(fire[nY][nX] == 0 || fire[nY][nX] > d+1) {
                        run[nY][nX] = d+1;
                        rq.push({nY,nX});
                    }
                }
            }
        }
    }
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    while(T--) {
        fill(&matrix[0][0],&matrix[MAX-1][0]+MAX,NULL);
        fill(&fire[0][0],&fire[MAX-1][0]+MAX,0);
        fill(&run[0][0],&run[MAX-1][0]+MAX,0);
        cin>>W>>H;
        queue<pair<int,int>> fq;
        queue<pair<int,int>> rq;
        string str;
        for(int i=0;i<H;i++) {
            cin>>str;
            for(int j=0;j<W;j++) {
                matrix[i][j] = str[j];
                if(str[j] == '@') {
                    rq.push({i,j});
                }
                if(str[j] == '*') {
                    fq.push({i,j});
                }
            }
        }
        ans = -1;
        fireBfs(fq);
        runBfs(rq);
        if(ans > 0) {
            cout<<ans<<"\n";
        }
        else {
            cout<<"IMPOSSIBLE"<<"\n";
        }
    }
    return 0;
}