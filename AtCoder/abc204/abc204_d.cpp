#include<bits/stdc++.h>
using namespace std;
bool dp[100001];
int arr[101];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int sum = 0;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    dp[0] = true;
    for(int i=0;i<N;i++) {
        for(int j=sum;j>=arr[i];j--) {
            if(dp[j-arr[i]]) {
                dp[j] = true;
            }
        }
    }
    ans = sum;
    for(int i=0;i<=sum;i++) {
        if(dp[i]) {
            ans = min(ans,max(i,sum-i));
        }
    }
    cout<<ans<<"\n";
    return 0;
}