#include<bits/stdc++.h>
using namespace std;
int T,N,ans;
int gcd(int a, int b) {
	return b == 0? a: gcd(b,a%b);	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N;	
		ans = 0;
		for(int i=1;i<=sqrt(N);i++) {
			if(N%i == 0 && gcd(i,N/i) == 1) {
				ans++;	
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}