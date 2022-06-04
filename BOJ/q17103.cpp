#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
bool p[MAX] = {};
int T,N,ans;
void primeCheck() {
	memset(p,1,sizeof(p));
	p[0] = p[1] = false;
	int n = sqrt(MAX);
	for(int i=2;i<=n;i++) {
		if(p[i]) {
			for(int j=i*i;j<MAX;j+=i) {
				p[j] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	primeCheck();
	cin>>T;
	for(int t=0;t<T;t++) {
		cin>>N;
		ans = 0;
		for(int i=0;i*2<=N;i++) {
			if(p[i] && p[N-i]) ans++;	
		}
		cout<<ans<<"\n";
	}
	return 0;
}