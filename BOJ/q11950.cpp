#include <bits/stdc++.h>
using namespace std;
char arr[51][51];
int sum[51][3];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 'W') {
                sum[i][0]++;
            }
            else if(arr[i][j] == 'B') {
                sum[i][1]++;   
            }
            else {
                sum[i][2]++;
            }
        }
    }
    for(int i=2;i<=N;i++) {
        sum[i][0]+=sum[i-1][0];
        sum[i][1]+=sum[i-1][1];
        sum[i][2]+=sum[i-1][2];
    }
    ans = INT_MAX;
    for(int i=1;i<=N-2;i++) {
        for(int j=i+1;j<=N-1;j++) {
            int tmp = sum[i][1]+sum[i][2];
            tmp+=sum[j][0]+sum[j][2]-(sum[i][0]+sum[i][2]);
            tmp+=sum[N][0]+sum[N][1]-(sum[j][0]+sum[j][1]);
            ans = min(ans,tmp);
        }
    }
    cout<<ans<<"\n";
    return 0;
}