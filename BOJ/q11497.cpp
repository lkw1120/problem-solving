#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T--) {
		cin>>N;
		int n;
		for(int i=0;i<N;i++) {
			cin>>n;
			v.push_back(n);
		}
		sort(v.begin(),v.end());
		vector<int> vv;
		for(int i=0;i<N;i+=2) {
			vv.push_back(v[i]);
		}
		for(int i=N-N%2-1;i>0;i-=2) {
			vv.push_back(v[i]);
		}
		ans = 0;
		for(int i=1;i<N;i++) {
			ans = max(ans,abs(vv[i]-vv[i-1]));
		}
		cout<<ans<<"\n";
		v.clear();
	}
	return 0;
}