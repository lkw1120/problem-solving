#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll N,K,ans;
ll find(ll x) {
	ll cnt = 0;
	for(auto item: v) {
		cnt+=max(0LL,item-x);
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
	ll l,r;
	l = 0;
	r = *max_element(v.begin(),v.end());
	while(l <= r) {
		ll mid = (l+r)/2;
		ll cnt = find(mid);
		if(K < cnt) {
			l = mid+1;
		}
		else {
			r = mid-1;
			ans = mid;
		}
	}
	cout<<ans<<"\n";
	return 0;
}