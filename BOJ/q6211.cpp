#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int C,B,ans;
void solve(int n, int sum) {
	if(C < sum) return;
	ans = max(sum,ans);
	for(int i=n;i<B;i++) {
		solve(i+1,sum+v[i]);
		solve(i+1,sum);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>B;
	v.resize(B);
	for(int i=0;i<B;i++) {
		cin>>v[i];
	}
	ans = 0;
	solve(0,0);
	cout<<ans<<"\n";
	return 0;
}