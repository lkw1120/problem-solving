#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,S,A,ans;
int gcd(int a, int b) {
	while(b!=0) {
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>S;
	for(int i=0;i<N;i++) {
		cin>>A;
		v.push_back(abs(A-S));
	}
	for(int i=1;i<N;i++) {
		v[i] = gcd(v[i],v[i-1]);
	}
	ans = v[N-1];
	cout<<ans<<"\n";
	return 0;
}