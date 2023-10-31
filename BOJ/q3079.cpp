#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll N,M,ans;
ll find(ll t) {
	ll sum = 0;
	for(auto item: v) {
		sum+=t/item;
		if(M <= sum) break;
	}
	return sum;
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
	sort(v.begin(),v.end());
	ll l,r;
	l = 0;
	r = M*v.back();
	ans = 0;
	while(l <= r) {
		ll mid = (l+r)/2;
		ll res = find(mid);
		if(M <= res) {
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