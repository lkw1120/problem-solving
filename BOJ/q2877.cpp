#include<bits/stdc++.h>
using namespace std;
int K,N,M;
string ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>K;
	N = M = 0;
	while(M < K) {
		M+=pow(2,++N);
	}
	M-=pow(2,N);
	int tmp = K-M-1;
	while(N--) {
		if(tmp%2 == 1) {
			ans = "7"+ans;
		}
		else {
			ans = "4"+ans;	
		}
		tmp/=2;
	}
	cout<<ans<<"\n";
	return 0;	
}