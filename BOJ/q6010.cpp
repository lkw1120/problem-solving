#include<bits/stdc++.h>
using namespace std;
int arr[50001];
int N,Q,T,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	for(int i=1;i<=N;i++) {
		arr[i]--;
	}
	for(int i=0;i<Q;i++) {
		cin>>T;
		ans = lower_bound(arr+1,arr+N+1,T)-arr;
		cout<<ans<<"\n";
	}
	return 0;
}