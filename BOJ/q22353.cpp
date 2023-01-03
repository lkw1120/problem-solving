#include<bits/stdc++.h>
using namespace std;
double A,D,K,W,L,T,ans;
void solve(double d, double k) {
	W = 0;
	L = 1;
	T = 1;
	while(true) {
		ans+=T*A*L*d;
		T++;
		if(d == 1) break;
		L = L*(1-d);
		d+=d*k;
		if(d >= 1) d = 1;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>D>>K;
	ans = 0;
	solve(D/100,K/100);
	cout<<fixed;
	cout.precision(7);
	cout<<ans<<"\n";
	return 0;	
}