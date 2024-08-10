#include<bits/stdc++.h>
using namespace std;
char arr[2001][2001];
int dX[7] = {0,1,1,0,-1,-1,-1};
int dY[7] = {1,1,-1,-1,-1,0,1};
int N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 'F') {
                X = i,Y = j;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({X,Y});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<7;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= N && arr[dx][dy] == '.') {
                arr[dx][dy] = '*';
                q.push({dx,dy});
            }
        }
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(arr[i][j] == '*') ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}