#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	if(N%2) {
		ans = 0;
	}
	else {
		N/=10;
		ans = N;
		ll n = 5;
		while(n <= N) {
			ans+=N/n;
			n = n*5;
		}
	}
	cout<<ans<<"\n";
	return 0;
}