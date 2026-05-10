#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	ans = 1;
	for(int i=1;i<=N;i++) {
		ans*=i;
		ans%=MOD;
	}
	cout<<ans<<"\n";
	return 0;
}