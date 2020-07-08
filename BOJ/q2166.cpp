#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> v;
ll N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>X>>Y;
		v.push_back({X,Y});
	}
	ans = 0;
	for(int i=1;i<N-1;i++) {
		X = (v[i].first-v[0].first)*(v[i+1].second-v[0].second);
		Y = (v[i].second-v[0].second)*(v[i+1].first-v[0].first);
		ans+=X-Y;
	}
	ans = llabs(ans);
	if(ans%2) {
		cout<<ans/2<<".5"<<"\n";
	}
	else {
		cout<<ans/2<<".0"<<"\n";
	}
	return 0;
}