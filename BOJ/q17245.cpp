#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr[1001][1001] = {0};
ll N,M,ans;
ll find(ll h) {
	ll cnt = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(arr[i][j] < h) {
				cnt+=arr[i][j];
			}
			else {
				cnt+=h;	
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	M = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cin>>arr[i][j];	
			M+=arr[i][j];
		}
	}
	if(M%2) M++;
	M/=2;
	ll l,r;
	l = 0;
	r = 1e7;
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