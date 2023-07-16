#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> v;
ll N,K,ans;
ll check(ll n) {
	ll cnt = 0;
	for(int i=0;i<N;i++) {
		cnt+=(v[i]/n);
	}
	return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ll left,right;
	left = 1;
	right = INT_MAX;
	while(left <= right) {
		ll mid = (left+right)/2;
		if (check(mid) < K) {
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	}
	ans = right;
	cout<<ans<<"\n";
	return 0;
}