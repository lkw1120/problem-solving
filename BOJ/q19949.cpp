#include<bits/stdc++.h>
using namespace std;
vector<int> v(10);
int ans;
void solve(int n, int a, int b, int cnt) {
	if(n == 10) {
		if(5 <= cnt) ans++;
		return ;
	}
	for(int i=1;i<=5;i++) {
		if(a == i && b == i) continue;
		if(i == v[n]) {
			solve(n+1,i,a,cnt+1);
		}
		else {
			solve(n+1,i,a,cnt);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<10;i++) {
		cin>>v[i];
	}
	ans = 0;
	solve(0,0,0,0);
	cout<<ans<<"\n";
	return 0;
}