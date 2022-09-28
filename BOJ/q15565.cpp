#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++) {
		cin>>M;
		if(M == 1) {
			v.push_back(i);
		}
	}
	if(v.size() < K) {
		ans = -1;
	}
	else {
		ans = INT_MAX;
		for(int i=0;i+K-1<v.size();i++) {
			ans = min(ans,v[i+K-1]-v[i]+1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}