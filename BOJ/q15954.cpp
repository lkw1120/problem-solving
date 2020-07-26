#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,a;
long double m,d,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=0;i<N;i++) {
		cin>>a;
		v.push_back(a);
	}
	ans = INT_MAX;
	while(K <= N) {
		for(int i=0;i<N-K+1;i++) {
			m = d = 0;
			for(int j=0;j<K;j++) {
				m+=v[i+j];
			}
			m = m/K;
			for(int j=0;j<K;j++) {
				d+=(v[i+j]-m)*(v[i+j]-m);
			}
			d/=K;
			d=sqrt(d);
			ans = min(ans,d);
		}
		K++;
	}
    cout<<fixed;
    cout.precision(8);
	cout<<ans<<"\n";
	return 0;
}