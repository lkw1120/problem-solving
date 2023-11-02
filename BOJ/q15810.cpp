#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll N,M,ans;
ll find(ll t) {
	ll cnt = 0;
	for(auto item: v) {
		cnt+=t/item;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	ll l,r;
	l = 0;
	r = 1e12;
	while(l <= r) {
		ll mid = (l+r)/2;
		ll cnt = find(mid);
		if(M <= cnt) {
			r = mid-1;
			ans = mid;
		}
		else {
			l = mid+1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}