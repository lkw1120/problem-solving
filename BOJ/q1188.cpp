#include<bits/stdc++.h>
using namespace std;
int N,M,ans;
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	ans = M-gcd(N,M);
	cout<<ans<<"\n";
	return 0;
}