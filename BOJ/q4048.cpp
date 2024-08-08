#include<bits/stdc++.h>
using namespace std;
int arr[102][102];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
bool visited[102][102];
int N,M,ans;
void flood(int x, int y, int h) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx <= N+1 && 0 <= dy && dy <= M+1 && arr[dx][dy] <= h && !visited[dx][dy]) {
                visited[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
    return ;
}
void find(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M && !visited[dx][dy]) {
                visited[dx][dy] = true;
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
    for(int t=1;;t++) {
        cin>>N>>M;
        if(!N && !M) break;
        fill(&arr[0][0],&arr[100][101],0);
        int top = 0;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) {
                cin>>arr[i][j];
                top = max(arr[i][j],top);
            }
        }
        ans = -1;
        for(int k=0;k<top;k++) {
            fill(&visited[0][0],&visited[100][101],false);
            flood(0,0,k);
            int cnt = 0;
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=M;j++) {
                    if(!visited[i][j]) {
                        cnt++;
                        find(i,j);
                    }    
                }
            }
            if(2 <= cnt) {
                ans = k;
                break;
            }
        }
        if(ans != -1) {
            cout<<"Case "<<t<<": "<<"Island splits when ocean rises "<<ans<<" feet."<<"\n";
        }
        else {
            cout<<"Case "<<t<<": "<<"Island never splits."<<"\n";
        }
    }
    return 0;
}