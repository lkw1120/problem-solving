#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
bool visited[101][101];
int N,M,X;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
        }
    }
    cin>>X;
    queue<pair<int,int>> q;
    q.push({1,1});
    visited[1][1] = true;
    bool flag = false;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == N && y == M) {
            flag = true;
            break;
        }
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) {
                if(x == i && y == j) continue;
                int d = abs(x-i)+abs(y-j);
                if(d <= X && arr[1][1] == arr[i][j] && !visited[i][j]) {
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
    }
    if(flag) {
        cout<<"ALIVE"<<"\n";
    }
    else {
        cout<<"DEAD"<<"\n";
    }
    return 0;
}