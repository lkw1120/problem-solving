#include<bits/stdc++.h>
using namespace std;
char arr[101][101];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M;
bool solve(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    int cnt = 0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx < N && 0 <= dy && dy < M
            && arr[dx][dy] == ' ' || arr[dx][dy] == '.') {
                if(arr[dx][dy] == '.') cnt++;
                arr[dx][dy] = 'X';
                q.push({dx,dy});
            }
        }
    }
    return 0 < cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    string str;
    getline(cin,str);
    for(int i=0;i<N;i++) {
        getline(cin,str);
        for(int j=0;j<M;j++) {
            arr[i][j] = str[j];
        }
    }
    int cnt,dots;
    cnt = dots = 0;
    for(int i=0;i<N;i++) {
        if(arr[i][0] != 'X' && solve(i,0)) cnt++;;
        if(arr[i][M-1] != 'X' && solve(i,M-1)) cnt++;
    }
    for(int j=0;j<M;j++) {
        if(arr[0][j] != 'X' && solve(0,j)) cnt++;
        if(arr[N-1][j] != 'X' && solve(N-1,j)) cnt++;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j] == '.') dots++;
        }
    }
    cout<<cnt<<" "<<dots<<"\n";
    return 0;
}