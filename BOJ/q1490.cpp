#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll N,ans;
bool divide(ll n) {
	for(auto div: v) {
		if(n%div) {
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	ll tmp = N;
	while(tmp) {
		if(tmp%10 != 0) {
			v.push_back(tmp%10);
		}
		tmp/=10;
	}
	if(divide(N)) {
		ans = N;
	}
	else {
		ans = 0;
		for(int i=0;;i++) {
			tmp = N*pow(10,i);
			for(int j=0;j<pow(10,i);j++) {
				if(divide(tmp+j)) {
					ans = tmp+j;
					break;
				}
			}
			if(ans != 0) {
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}