#include<bits/stdc++.h>
using namespace std;
int N,M,X,A,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M>>X;
	int sum1,sum2;
	sum1 = sum2 = 0;
	for(int i=0;i<M;i++) {
		cin>>A;
		if(A < X) {
			sum1++;
		}
		else {
			sum2++;	
		}
	}
	ans = min(sum1,sum2);
	cout<<ans<<"\n";
	return 0;
}