#include<bits/stdc++.h>
using namespace std;
char arr[501][501];
int dX[8] = {1,2,2,1,-1,-2,-2,-1};
int dY[8] = {-2,-1,1,2,2,1,-1,-2};
bool visited[501][501];
int N,M,X,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 'H') {
                X = i, Y = j;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({X,Y});
    visited[X][Y] = true;
    arr[X][Y] = '#';
    bool flag = false;
    while(!q.empty()) {
        X = q.front().first;
        Y = q.front().second;
        q.pop();
        if(arr[X][Y] == 'H') {
            flag = true;
            break;
        }
        for(int i=0;i<8;i++) {
            int dx = X+dX[i];
            int dy = Y+dY[i];
            if(0 < dx && dx <= N && 0 < dy && dy <= M && !visited[dx][dy] && arr[dx][dy] != '#') {
                visited[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }
    if(flag) {
        cout<<"JA"<<"\n";
    }
    else {
        cout<<"NEJ"<<"\n";
    }
    return 0;
}