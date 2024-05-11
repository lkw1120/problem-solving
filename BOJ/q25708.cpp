#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin>>arr[i][j];
            arr[i][0]+=arr[i][j];
            arr[0][j]+=arr[i][j];
        }
    }
    ans = INT_MIN;
    for(int i=1;i<=N;i++) {
        for(int j=i+1;j<=N;j++) {
            for(int k=1;k<=M;k++) {
                for(int l=k+1;l<=M;l++) {
                    int sum = arr[i][0]+arr[j][0]+arr[0][k]+arr[0][l];
                    sum-=(arr[i][k]+arr[i][l]+arr[j][k]+arr[j][l]);
                    sum+=(j-i-1)*(l-k-1);
                    ans = max(ans,sum);
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}