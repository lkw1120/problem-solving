#include<bits/stdc++.h>
using namespace std;
string str = "YOKOHAMA";
char arr[11][11];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
int find(int x, int y, int idx) {
    if(idx == 8) {
        return 1;
    }
    int cnt = 0;
    for(int i=0;i<4;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
        if(0 < dx && dx <= N && 0 < dy && dy <= M && str[idx] == arr[dx][dy]) {
            cnt+=find(dx,dy,idx+1);
        }
    }
    return cnt;
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
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(arr[i][j] == 'Y') {
                ans+=find(i,j,1);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}