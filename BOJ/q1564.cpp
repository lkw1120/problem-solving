#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e12;
ll N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	M = 1;
	for(int i=2;i<=N;i++) {
		M*=i;
		while(!(M%10)) {
			M/=10;
		}
		M%=MOD;
	}
	ans = M%100000;
	cout.width(5);
	cout.fill('0');
	cout<<ans<<"\n";
	return 0;
}