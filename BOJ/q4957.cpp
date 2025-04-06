#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1e6+1;
const int INF = 987654321;
int arr[2][210];
int cnt[2];
int dp[2][MAX];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;;i++) {
        int tmp = i*(i+1)*(i+2)/6;
        if(MAX < tmp) break;
        arr[0][cnt[0]] = tmp;
        cnt[0]++;
        if(tmp%2) {
            arr[1][cnt[1]] = tmp;
            cnt[1]++;
        }
    }
    for(int k=0;k<2;k++) {
        dp[k][0] = 0;
        for(int i=1;i<MAX;i++) {
            dp[k][i] = i;
        }
    }
    for(int k=0;k<2;k++) {
        for(int i=0;i<cnt[k];i++) {
            int tmp = arr[k][i];
            for(int j=tmp;j<MAX;j++) {
                dp[k][j] = min(dp[k][j],dp[k][j-tmp]+1);
            }
        }
    }
    while(1) {
        cin>>N;
        if(N == 0) break;
        cout<<dp[0][N]<<" "<<dp[1][N]<<"\n";
    }
    
    return 0;
}
