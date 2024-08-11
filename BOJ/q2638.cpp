#include<bits/stdc++.h>
using namespace std;
int arr[102][102];
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int check[102][102];
int N,M,ans;
void find() {
    fill(&check[0][0],&check[101][102],0);
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int dx = x+dX[i];
            int dy = y+dY[i];
            if(0 <= dx && dx <= N+1 && 0 <= dy && dy <= M+1 && 0 <= check[dx][dy]) {
                if(arr[dx][dy] == 1) {
                    check[dx][dy]++;
                }
                else {
                    check[dx][dy] = -1;
                    q.push({dx,dy});
                }
            }
        }
    }
}
void melt() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(2 <= check[i][j]) {
                arr[i][j] = 0;
            }
        }
    }
}
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
    ans = 0;
    while(1) {
        int cnt = 0;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) {
                cnt+=arr[i][j];
            }
        }
        if(cnt == 0) {
            break;
        }
        else {
            find();
            melt();
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}