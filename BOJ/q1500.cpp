#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll S,K,N,M,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>S>>K;
	N = S/K;
	M = S%K;
	ans = 1;
	while(K--) {
		if(M > 0) {
			ans*=(N+1);
			M--;
		}
		else {
			ans*=N;
		}
	}
	cout<<fixed;
	cout.precision(0);
	cout<<ans<<"\n";
	return 0;
}