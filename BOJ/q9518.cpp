#include<bits/stdc++.h>
using namespace std;
char arr[51][51];
int dX[8] = {-1,0,1,1,1,0,-1,-1};
int dY[8] = {1,1,1,0,-1,-1,-1,0};
int R,S,ans;
int shake(int x, int y) {
    int cnt = 0;
    for(int i=0;i<8;i++) {
        int dx = x+dX[i];
        int dy = y+dY[i];
        if(0 < dx && dx <= R && 0 < dy && dy <= S) {
            if(arr[dx][dy] == 'o') cnt++;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>R>>S;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=S;j++) {
            cin>>arr[i][j];
        }
    }
    int cnt = 0;
    ans = 0;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=S;j++) {
            if(arr[i][j] == 'o') {
                cnt+=shake(i,j);
            }
            else {
                ans = max(ans,shake(i,j));    
            }
        }
    }
    ans+=cnt/2;
    cout<<ans<<"\n";
    return 0;
}