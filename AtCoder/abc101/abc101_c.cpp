#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>K;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	ans = (N-K)/(K-1);
	if((N-K)%(K-1)) {
		ans++;	
	}
	ans++;
	cout<<ans<<"\n";
	return 0;
}