#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 200001;
int arr[MAX_N];
int dp[MAX_N];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    if(N == 1) {
        ans = 1;
    }
    else {
        for(int i=0;i<N-1;i++) {
            if(arr[i] < arr[i+1]) {
                dp[i] = 1;
            }
            else if(arr[i+1] < arr[i]) {
                dp[i] = -1;
            }
            else {
                dp[i] = 0;
            }
        }
        ans = N;
        int len = 0;
        for(int i=0;i<N-1;i++) {
            if(dp[i] == 0) {
                len = 0;
            }
            else if(i == 0 || dp[i]*dp[i-1] == -1) {
                len++;
            }
            else {
                len = 1;
            }
            ans+=len;
        }
    }
    cout<<ans<<"\n";
    return 0;
}