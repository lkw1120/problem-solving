#include<bits/stdc++.h>
using namespace std;
int dp[41] = {0};
int arr[41] = {0};
string str;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    N = str.size();
    for(int i=1;i<=N;i++) {
        arr[i] = str[i-1]-'0';
    }
    ans = 0;
    dp[0] = dp[1] = 1;
    for(int i=2;i<=N;i++) {
        if(arr[i] != 0) {
            dp[i] = dp[i-1];
        }
        int tmp = arr[i-1]*10+arr[i];
        if(10 <= tmp && tmp < 35) {
            dp[i]+=dp[i-2];
        }
        else if(35 <= tmp && !arr[i]) {
            break;
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}