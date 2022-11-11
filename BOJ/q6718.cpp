#include<bits/stdc++.h>
#define MAX 32769
using namespace std;
bool isPrime[MAX];
int N,ans;
void preload() {
	fill(isPrime,isPrime+MAX,true);
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i<=sqrt(MAX);i++) {
		if(!isPrime[i]) continue;
		for(int j=i*2;j<MAX;j+=i) {
			isPrime[j] = false;	
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	while(true) {
		cin>>N;	
		if(N == 0) break;
		ans = 0;
		for(int i=2;i<=N/2;i++) {
			if(isPrime[i] && isPrime[N-i]) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}