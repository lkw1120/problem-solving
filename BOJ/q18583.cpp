#include<bits/stdc++.h>
using namespace std;
char arr[1001][1001];
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int x,y;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 'K') {
                x = i,y = j;
            }
        }
    }
    arr[x][y] = '-';
    for(int i=0;i<8;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
        if(0 < dx && dx <= N && 0 < dy && dy <= N) {
            arr[dx][dy] = '-';
        }
    }
    ans = 0;
    for(int i=1;i<N;i++) {
        for(int j=1;j<=N;j++) {
            if(arr[i][j] == '*') {
                if(j+2 <= N && arr[i][j+2] == '*' && arr[i+1][j+1] == '-') {
                    arr[i][j] = arr[i][j+2] = '-';
                    ans++;
                }
                else if(0 < j-1 && arr[i+1][j-1] == '-') {
                    arr[i][j] = '-';
                    ans++;
                }
                else if(j+1 <= N && arr[i+1][j+1] == '-') {
                    arr[i][j] = '-';
                    ans++;
                }
            }
            
        }
    }
    bool flag = true;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(arr[i][j] == '*') {
                flag = false;
            }
        }
    }
    if(flag) {
        cout<<ans<<"\n";
    }
    else {
        cout<<-1<<"\n";
    }
    return 0;
}