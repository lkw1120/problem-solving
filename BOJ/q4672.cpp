#include<bits/stdc++.h>
using namespace std;
char arr[4][4];
int dX[2] = {0,1};
int dY[2] = {1,0};
int N,ans;
void find(int x, int y, int cnt) {
    arr[x][y] = '*';
    for(int i=0;i<2;i++) {
        for(int j=1;;j++) {
            int dx = x+dX[i]*j;
            int dy = y+dY[i]*j;
            if(0 <= dx && dx < N && 0 <= dy && dy < N && arr[dx][dy] == '.') {
                arr[dx][dy] = '*';
            }
            else {
                break;
            }
        }
    }
    ans = max(cnt,ans);
    for(int i=x;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j] == '.') {
                find(i,j,cnt+1);
            }
        }
    }
    return ;
}
void reset() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j] == '*') {
                arr[i][j] = '.';
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>N;
        if(!N) break;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin>>arr[i][j];
            }
        }
        ans = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(arr[i][j] == '.') {
                    find(i,j,1);
                    reset();
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}