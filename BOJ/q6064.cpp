#include<bits/stdc++.h>
using namespace std;
int T,M,N,x,y,d,ans;
int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b,a%b);
}
int lcm(int a, int b) {
	return a*b/gcd(a,b);
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T--) {
		cin>>M>>N>>x>>y;
		d = lcm(M,N);
		ans = -1;
		for(int i=x;i<=d;i+=M) {
			if(i%N == y || (N == y && i%N == 0)) {
				ans = i;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}