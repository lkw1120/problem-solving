#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> mp;
int N,K,A,l,r,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++) {
		cin>>A;
		v.push_back(A);
	}
	l = 0;
	r = 1;
	ans = 0;
	while(l < r && r <= v.size()) {
		if(mp[v[r-1]] < K) {
			mp[v[r-1]]++;
			r++;
		}
		else {
			if(mp[v[l]] == K) mp[v[l]]--;
			l++;
		}
		ans = max(ans,r-l-1);
	}
	cout<<ans<<"\n";
	return 0;	
}