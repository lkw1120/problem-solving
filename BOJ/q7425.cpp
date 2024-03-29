#include<bits/stdc++.h>
using namespace std;
bool arr[4][4];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int ans;
bool solve(int n) {
    bool flip[4][4];
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            flip[i][j] = arr[i][j];
        }
    }
    int tmp = 0;
    while(n) {
        if(n%2) {
            int x = tmp/4;
            int y = tmp%4;
            flip[x][y] = !flip[x][y];
            for(int i=0;i<4;i++) {
                int dx = x+dX[i];
                int dy = y+dY[i];
                if(0 <= dx && dx < 4 && 0 <= dy && dy < 4) {
                    flip[dx][dy] = !flip[dx][dy];
                }
            }
        }
        n/=2;
        tmp++;
    }
    bool check = flip[0][0];
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(check != flip[i][j]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            char ch;
            cin>>ch;
            arr[i][j] = ch == 'b';
        }
    }
    ans = INT_MAX;
    for(int i=0;i<(1<<16);i++) {
        if(solve(i)) {
            int n,cnt;
            n = i;
            cnt = 0;
            while(n) {
                cnt+=n%2;
                n/=2;
            }
            ans = min(cnt,ans);
        }
    }
    if(ans == INT_MAX) {
        cout<<"Impossible"<<"\n";
    }
    else {
        cout<<ans<<"\n";
    }
    return 0;
}