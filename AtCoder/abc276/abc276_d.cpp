#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll N,A,ans;
ll gcd(ll a, ll b) {
	return (b == 0)? a: gcd(b,a%b);	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	ll g = 0;
	for(int i=0;i<N;i++) {
		g = gcd(g,v[i]);
	}
	ans = 0;
	for(int i=0;i<N;i++) {
		A = v[i]/g;
		while(A%2 == 0) {
			A/=2;
			ans++;
		}
		while(A%3 == 0) {
			A/=3;
			ans++;
		}
		if(A != 1) {
			ans = -1;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}