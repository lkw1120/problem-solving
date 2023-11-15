#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int T,N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N;
		v.resize(N);
		for(int i=0;i<N;i++) {
			cin>>v[i];	
		}
		sort(v.begin(),v.end());
		ans = 0;
		for(int i=0;i+2<N;i++) {
			for(int j=i+1;j+1<N;j++) {
				auto idx = lower_bound(v.begin(),v.end(),2*v[j]-v[i])-v.begin();
				if(idx != N) {
					if(v[j]-v[i] == v[idx]-v[j]) {
						ans++;
					}
				}
			}
		}
		v.clear();
		cout<<ans<<"\n";
	}
	return 0;
}