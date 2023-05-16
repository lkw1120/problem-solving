#include<bits/stdc++.h>
using namespace std;
map<int,bool> check;
vector<int> v;
int N,M,ans;
void solve(int n, int sum) {
	if(n-1 == N || M < sum) return ;
	if(0 < sum && sum <= M) {
		check[sum] = true;
	}
	solve(n+1,sum);
	solve(n+1,sum+v[n]);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	M = 0;
	for(int i=0;i<N;i++) {
		cin>>v[i];
		M+=v[i];
	}
	solve(0,0);
	ans = M-check.size();
	cout<<ans<<"\n";
	return 0;
}