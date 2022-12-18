#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> mp;
int ans[20];
int N;
void solve(int n) {
	if(n == N*2) {
		for(int i=0;i<N*2;i++) {
			cout<<ans[i]<<" ";	
		}
		cout<<"\n";
		exit(0);
	}
	if(ans[n] != -1) {
		solve(n+1);
		return ;
	}
	for(int i=0;i<N;i++) {
		if(mp[v[i]] && n+v[i]+1 < N*2 && ans[n] == -1 && ans[n+v[i]+1] == -1) {
			mp[v[i]]--;
			ans[n+v[i]+1] = ans[n] = v[i];
			solve(n+1);
			ans[n+v[i]+1] = ans[n] = -1;
			mp[v[i]]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
		mp[v[i]] = 1;
	}
	sort(v.begin(),v.end());
	fill(ans,ans+20,-1);
	solve(0);
	cout<<-1<<"\n";
	return 0;
}