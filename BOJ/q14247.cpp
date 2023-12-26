#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5+1;
vector<pair<ll,ll>> v;
vector<ll> h,a;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	h.resize(N);
	a.resize(N);
	for(int i=0;i<N;i++) {
		cin>>h[i];
	}
	for(int i=0;i<N;i++) {
		cin>>a[i];	
	}
	for(int i=0;i<N;i++) {
		v.push_back({a[i],h[i]});	
	}
	sort(v.begin(),v.end());
	ans = 0;
	for(int i=0;i<N;i++) {
		ans+=(v[i].first*i+v[i].second);
	}
	cout<<ans<<"\n";
	return 0;
}