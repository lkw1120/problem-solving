#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> mp;
int N,D,K,C,A,cnt,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>D>>K>>C;
	for(int i=0;i<N;i++) {
		cin>>A;
		v.push_back(A);
	}
	for(int i=0;i<K;i++) {
		mp[v[i]] = mp.find(v[i]) != mp.end()? mp[v[i]]+1:1;
	}
	ans = mp.find(C) != mp.end()? mp.size():mp.size()+1;
	for(int i=K;i<N+K;i++) {
		mp[v[i%N]] = mp.find(v[i%N]) != mp.end()? mp[v[i%N]]+1:1;
		if(1 < mp[v[(i-K)%N]]) {
			mp[v[(i-K)%N]]--;
		}
		else {
			mp.erase(v[(i-K)%N]);
		}
		ans = max(ans,mp.find(C) != mp.end()? (int)mp.size():(int)mp.size()+1);
	}
	cout<<ans<<"\n";
	return 0;	
}