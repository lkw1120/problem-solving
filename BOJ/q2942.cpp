#include<bits/stdc++.h>
using namespace std;
int R,G,N;
int gcd(int a, int b) {
	return (b == 0)? a: gcd(b,a%b);	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>G;
	N = gcd(R,G);
	for(int i=1;i<=N;i++) {
		if(N%i == 0) {
			cout<<i<<" "<<R/i<<" "<<G/i<<"\n";
		}
	}
	return 0;
}