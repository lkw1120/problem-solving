#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int arr[1001][1001] = {0};
int T,N,K,ans;
int solve(int n, int k) {
    if(arr[n][k] != 0) {
		return arr[n][k];
	}
    if(n == k || k == 0) {
		return 1;
	}
    else {
        arr[n][k] = (solve(n-1,k-1)+solve(n-1,k))%MOD;
        return arr[n][k];
    }
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N>>K;
		ans = solve(N,K);
		cout<<ans<<"\n";
	}
	return 0;
}