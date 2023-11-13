#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> v;
int N,ans;
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
	int l,r,t;
	ans = 1;
	for(int i=0;i<N;i++) {
		l = r = i;
		t = 1;
		while(true) {
			auto idx = lower_bound(v.begin(),v.end(),v[l]-t)-v.begin();
			if(idx == l) break;
			l = idx;
			t++;
		}
		t = 1;
		while(true) {
			auto idx = upper_bound(v.begin(),v.end(),v[r]+t)-v.begin();
			idx--;
			if(idx == r) break;
			r = idx;
			t++;
		}
		ans = max(ans,r-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}