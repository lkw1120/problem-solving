#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+7;
int arr[MAX];
int dp[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    arr[0] = INT_MIN;
    arr[N+1] = INT_MAX;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    int x,p;
    x = p = 0;
    for(int i=2;i<=N;i++) {
        if(arr[i-1] > arr[i]) {
            x++;
            p = i;
        }
    }
    ans = 0;
    if(x == 0) {
        ans = N;
    }
    else if(x == 1) {
        if(arr[p-1] <= arr[p+1]) {
            ans++;
        }
        if(arr[p-2] <= arr[p]) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}