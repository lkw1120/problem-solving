#include<bits/stdc++.h>
#define DIV 1000000009
typedef long long ll;
using namespace std;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	ans = 0;
	if(1 < N) {
		ans = 2;
		for(int i=2;i<N;i++) {
			ans*=3;
			ans%=DIV;
		}
	}
	cout<<ans<<"\n";
	return 0;	
}