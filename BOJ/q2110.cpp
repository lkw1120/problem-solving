#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll N,M,ans;
ll find(ll n) {
	int cnt = 1;
	int prev = v[0];
	for(int i=1;i<N;i++) {
		if(n <= v[i]-prev) {
			cnt++;
			prev = v[i];
		}
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
	sort(v.begin(),v.end());
	ll l,r;
	l = 1;
	r = v[N-1]-v[0];
	ans = 0;
	while(l <= r) {
		ll mid = (l+r)/2;
		ll cnt = find(mid);
		if(M <= cnt) {
			l = mid+1;
			ans = mid;
		}
		else { 
			r = mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}