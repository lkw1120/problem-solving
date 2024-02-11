#include<bits/stdc++.h>
using namespace std;
int arr[3][3];
int magic[3][3];
bool visited[10];
int ans;
void solve(int n) {
	if(n == 9) {
        int sum[8] = {0};
        for(int i=0;i<3;i++) {
          sum[0]+=magic[i][0];
          sum[1]+=magic[i][1];
          sum[2]+=magic[i][2];
          sum[3]+=magic[0][i];
          sum[4]+=magic[1][i];
          sum[5]+=magic[2][i];
          sum[6]+=magic[i][i];
          sum[7]+=magic[i][2-i];
        }
        for(int i=0;i<8;i++) {
            if(sum[i] != 15) return ;
        }
        int tmp = 0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                tmp+=abs(arr[i][j]-magic[i][j]);
            }
        }
        ans = min(ans,tmp);
        return ;
	}
    for(int i=1;i<10;i++) {
        if(visited[i]) continue;
        int x,y;
        x = n/3;
        y = n%3;
        magic[x][y] = i;
        visited[i] = true;
        solve(n+1);
        visited[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin>>arr[i][j];
        }
    }
    ans = INT_MAX;
    solve(0);
    cout<<ans<<"\n";
    return 0;
}