#include<bits/stdc++.h>
using namespace std;
int K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>K;
	int k = 1;
	while(k < K) {
		k*=2;
	}
	ans = k;
	int cnt = 0;
	while(K) {
		if(k <= K) {
			K-=k;
		}
		else {
			k/=2;
			cnt++;
		}
	}
	cout<<ans<<" "<<cnt<<"\n";
	return 0;	
}