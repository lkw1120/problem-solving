#include<bits/stdc++.h>
#define MAX 1299710
using namespace std;
bool p[MAX] = {false};
int T,N,ans;
void eratosthenes() {
	memset(p,1,sizeof(p));
	p[0] = p[1] = false;
	for(int i=2;i<=sqrt(MAX);i++) {
		for(int j=2*i;j<MAX;j+=i) {
			p[j] = false;	
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	eratosthenes();
	cin>>T;
	for(int t=0;t<T;t++) {
		cin>>N;
		ans = 0;
		if(!p[N]) {
			int l,r;
			l = r = N;
			while(!p[l]) l--;
			while(!p[r]) r++;
			ans = r-l;
		}
		cout<<ans<<"\n";
	}
	return 0;	
}