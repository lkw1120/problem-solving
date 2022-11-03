#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll A,B,ans;
void solve(ll n) {
	if(B < n) return ;
	if(A <= n && n <= B) {
		ans++;	
	}
	solve(n*10+4);
	solve(n*10+7);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	ans = 0;
	solve(4);
	solve(7);
	cout<<ans<<"\n";
	return 0;
}