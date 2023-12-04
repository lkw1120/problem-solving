#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll A,B,L,ans;
ll gcd(ll a, ll b) {
	return b == 0? a: gcd(b,a%b);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B>>L;
	ll lcm = A*B/gcd(A,B);
	if(L == lcm) {
		ans = 1;	
	}
	else if(L%lcm != 0) {
		ans = -1;
	}
	else {
		for(int i=1;i<=sqrt(L);i++) {
			if(L%i == 0) {
				v.push_back(i);
				if(i != L/i) {
					v.push_back(L/i);
				}
			}
		}
		sort(v.begin(),v.end());
		for(auto item: v) {
			if(L == (lcm*item)/gcd(lcm,item)) {
				ans = item;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}