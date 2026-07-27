#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	ans = 12;
	for(ll i=1;i<=sqrt(N);i++) {
		if(N%i == 0) {
			ll size1 = to_string(N/i).size();
			ll size2 = to_string(i).size();
			ans = min(max(size1,size2),ans);
		}
	}
	cout<<ans<<"\n";
	return 0;
}