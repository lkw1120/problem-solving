#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int size = v.size();
	ans = 0;
	while(1 < size) {
		v[0]--;
		v[size-2]+=v[size-1];
		v.pop_back();
		if(v[0] == 0) {
			v.erase(v.begin());
		}
		size = v.size();
		ans++;
	}
	cout<<ans<<"\n";
	return 0;
}