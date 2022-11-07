#include<bits/stdc++.h>
#define MAX 50001
using namespace std;
map<int,bool> checked;
vector<set<int>> dp;
vector<int> v;
int N,K,ans;
void solve() {
	for(int i=2;i<=K;i++) {
		for(auto now: dp[i-1]) {
			for(auto next: v) {
				checked[now+next] = true;
				dp[i].insert(now+next);
			}
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
	}
	cin>>K;
	dp.resize(K+1);
	for(int i=0;i<N;i++) {
		dp[1].insert(v[i]);
		checked[v[i]] = true;
	}
	solve();
	for(int i=1;i<MAX;i++) {
		if(!checked[i]) {
			ans = i;
			break;
		}
	}
	if(ans%2) {
		cout<<"jjaksoon win at "<<ans<<"\n";
	}
	else {
		cout<<"holsoon win at "<<ans<<"\n";
	}
	return 0;	
}