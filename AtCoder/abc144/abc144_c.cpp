#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	ll M = sqrt(N);
	for(int i=1;i<=M;i++) {
		if(N%i == 0) {
			v.push_back(i);
		}
	}
	int size = v.size();
	ans = LONG_MAX;
	for(int i=0;i<size;i++) {
		ans = min(ans,(N/v[i]-1)+(v[i]-1));
	}
	cout<<ans<<"\n";
	return 0;
}