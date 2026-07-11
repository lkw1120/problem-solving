#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll L,R,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>L>>R;
	if(2019 <= R-L) {
		ans = 0;
	}
	else {
		ans = LONG_MAX;
		for(ll i=L;i<R;i++) {
			for(ll j=i+1;j<=R;j++) {
				ans = min(ans,i*j%2019);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}