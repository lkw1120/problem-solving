#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N,ans;
ll find(ll n) {
	if(n == 1) {
		return 0;
	}
	ll p = 1;
	while(p*2 < n) {
		p<<=1;
	}
	return 1-find(n-p);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	ans = find(N);
	cout<<ans<<"\n";
	return 0;
}