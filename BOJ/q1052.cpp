#include<bits/stdc++.h>
using namespace std;
int N,K,cnt,sum,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	ans = 0;
	if(N > K) {
		while(true) {
			cnt = 0;
			sum = N;
			while(sum > 0) {
				if(sum%2) cnt++;
				sum/=2;
			}
			if(cnt <= K) {
				break;
			}
			N++;
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}