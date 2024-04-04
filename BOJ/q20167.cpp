#include<bits/stdc++.h>
using namespace std;
int arr[21];
int N,K,ans;
void find(int n, int k, int sum) {
    if(N < n) {
        ans = max(ans,sum);
        return ;
    }
    if(k == 0) {
        find(n+1,k,sum);
    }
    k+=arr[n];
    if(K <= k) {
        sum+=k-K;
        k = 0;
    }
    find(n+1,k,sum);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    ans = 0;
    find(1,0,0);
    cout<<ans<<"\n";
    return 0;
}