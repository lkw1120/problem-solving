#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
bool isPrime[MAX] = {false};
int dp[MAX] = {0};
int A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	fill(isPrime,isPrime+MAX,true);
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i<=B;i++) {
		if(isPrime[i]) {
			for(int j=i*2;j<=B;j+=i) {
				isPrime[j] = false;
				int n = j;
				while(n%i == 0) {
					n/=i;
					dp[j]++;
				}
			}
		}
	}
	ans = 0;
	for(int i=A;i<=B;i++) {
		if(isPrime[dp[i]]) {
			ans++;	
		}
	}
	cout<<ans<<"\n";
	return 0;
}