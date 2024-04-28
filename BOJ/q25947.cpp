#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+1;
ll arr[MAX] = {0};
ll dp[MAX] = {0};
int N,B,A,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>B>>A;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	sort(arr+1,arr+N+1);
	for(int i=1;i<=N;i++) {
		dp[i] = dp[i-1]+arr[i];
	}
	for(int i=1;i<=N;i++) {
	    ll sum = dp[i-min(i,A)]+(dp[i]-dp[i-min(i,A)])/2;
	    if(B < sum) {
	        break;
	    }
	    else {
	        ans = i;
	    }
	}
	cout<<ans<<"\n";
	return 0;
}