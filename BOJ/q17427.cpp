#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	ans = 0;
	for(int i=1;i<=N;i++) {
		ans+=(i*(N/i));
	}
	cout<<ans<<"\n";
	return 0;
}