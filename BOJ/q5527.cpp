#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5+1;
int arr[MAX_N];
int dp[MAX_N];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    for (int i=0;i<N-1;i++) {
        dp[i] = (arr[i] != arr[i+1])? 1: 0;
    }
    int l,r,cnt;
    l = r = cnt = 0;
    ans = 0;
    while(r < N-1) {
        if(dp[r] == 0) {
            cnt++;
        }
        while(2 < cnt) {
            if(dp[l] == 0) {
                cnt--;
            }
            l++;
        }
        ans = max(ans,r-l+1);
        r++;
    }
    ans++;
    cout<<ans<<"\n";
    return 0;
}