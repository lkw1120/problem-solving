#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int N,M,ans;
void solve(int n, string str) {
	if(n == N) {
		for(auto item: v) {
			if(str.find(item) == string::npos) {
				return ;
			}
		}
		ans++;
		return ;
	}
	for(int i=0;i<10;i++) {
		solve(n+1,str+to_string(i));
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	if(0 < M) {
		v.resize(M);
		for(int i=0;i<M;i++) {
			cin>>v[i];
		}
	}
	ans = 0;
	solve(0,"");
	cout<<ans<<"\n";
	return 0;
}