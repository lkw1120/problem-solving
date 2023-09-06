#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll P,A;
string ans;
bool isPrime(ll n) {
	for(int i=2;i*i<=n;i++) {
		if(n%i == 0) return false;
	}
	return n!=1;
}
ll modpow(ll a, ll n, ll p) {
	ll res = 1;
	while(n)  {
		if(n & 1) {
			res = res*a%p;
		}
		a = a*a%p;
		n/=2;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true) {
		cin>>P>>A;
		if(!P && !A) break;
		ans = "no";
		if(!isPrime(P) && modpow(A,P,P) == A) {
			ans = "yes";	
		}
		cout<<ans<<"\n";
	}
	return 0;
}