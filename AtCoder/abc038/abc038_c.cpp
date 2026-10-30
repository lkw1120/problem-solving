#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+7;
int arr[MAX];
int dp[MAX];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ans = 0;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        dp[i] = arr[i-1] < arr[i]? dp[i-1]+1: 1;
        ans+=dp[i];
    }
    cout<<ans<<"\n";
    return 0;
}