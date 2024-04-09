#include<bits/stdc++.h>
using namespace std;
int dX[8];
int dY[8];
int arr[31][31];
bool visited[31][31];
int M,N,X,Y,ans;
void find(int x, int y) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    visited[x][y] = true;
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        int jump = q.front().second;
        q.pop();
        if(arr[x][y] == 4) {
            ans = jump;
            break;
        }
        for(int i=0;i<8;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M 
            && !visited[dx][dy] && (arr[dx][dy] == 1 || arr[dx][dy] == 4)) {
                visited[dx][dy] = true;
                q.push({{dx,dy},jump+1});
            }
        }
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>X>>Y;
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            for(int k=0;k<2;k++) {
                dX[i*4+j*2+k] = X*(j==0?1:-1);
                dY[i*4+j*2+k] = Y*(k==0?1:-1);
            }
        }
        swap(X,Y);
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(arr[i][j] == 3) {
                find(i,j);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}