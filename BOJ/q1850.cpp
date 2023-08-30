#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll A,B,cnt;
ll gcd(ll a, ll b) {
	return b == 0? a: gcd(b,a%b);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	cnt = gcd(A,B);
	while(cnt--) {
		cout<<"1";
	}
	cout<<"\n";
	return 0;
}