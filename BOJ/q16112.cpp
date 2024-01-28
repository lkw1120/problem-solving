#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	sort(v.begin(),v.end());
	ans = 0;
	for(int i=1;i<N;i++) {
		ans+=v[i]*min((ll)i,K);
	}
	cout<<ans<<"\n";
	return 0;
}