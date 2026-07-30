#include<bits/stdc++.h>
using namespace std;
double N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>K;
	ans = 0;
	for(int i=1;i<=N;i++) {
		double n = 1/N;
		for(int j=1;i*j<K;j*=2) {
			n*=(0.5);
		}
		ans+=n;
	}
	cout.precision(12);
	cout<<ans<<"\n";
	return 0;
}