#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
map<ll,ll> mp;
ll N,P,Q,X,Y;
ll solve(ll n) {
	if(n <= 0) {
		return 1;
	}
	if(!mp[n]) {
		mp[n] = solve(n/P-X)+solve(n/Q-Y);
	}
	return mp[n];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>P>>Q>>X>>Y;
	cout<<solve(N)<<"\n";
	return 0;	
}