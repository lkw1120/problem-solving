#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e6+1;
ll arr[MAX];
ll S,C,ans;
ll find(ll n) {
	ll cnt = 0;
	for(int i=0;i<S;i++) {
		cnt+=arr[i]/n;	
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>S>>C;
	for(int i=0;i<S;i++) {
		cin>>arr[i];
	}
	ll len = 0;
	ll l,r;
	l = 0;
	r = LONG_MAX;
	while(l <= r) {
		ll mid = (l+r)/2;
		ll res = find(mid);
		if(C <= res) {
			l = mid+1;
			len = mid;
		}
		else {
			r = mid-1;
		}
	}
	ll sum = 0;
	for(int i=0;i<S;i++) {
		sum+=arr[i];	
	}
	ans = sum-len*C;
	cout<<ans<<"\n";
	return 0;
}