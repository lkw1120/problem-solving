#include<bits/stdc++.h>
using namespace std;
int N,K,n,k,cnt,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	cnt = n = k = 0;
	while(9*pow(10,k)*(k+1) < K) {
		cnt+=(9*pow(10,k)*(k+1));
		k++;
	}
	n = pow(10,k);
	while(cnt+(k+1) < K) {
		cnt+=(k+1);
		n++;
	}
	if(N >= n) {
		ans = (int)(n/pow(10,(k-(K-cnt-1))))%10;
	}
	else {
		ans = -1;
	}
	cout<<ans<<"\n";
	return 0;	
}