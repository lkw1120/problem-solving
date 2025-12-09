#include<bits/stdc++.h>
using namespace std;
int arr[301][301];
int psum[301][301];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            psum[i][j] = arr[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
        }
    }
    ans = INT_MIN;
    for(int k=1;k<=N;k++) {
        for(int i=1;i+k-1<=N;i++) {
            for(int j=1;j+k-1<=N;j++) {
                int x = i+k-1;
                int y = j+k-1;
                int sum = psum[x][y]-psum[i-1][y]-psum[x][j-1]+psum[i-1][j-1];
                ans = max(ans,sum);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}