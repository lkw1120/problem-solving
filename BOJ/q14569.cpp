#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> k,p;
ll N,M,K,P,A,B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>K;
		ll tmp = 0;
		for(int j=0;j<K;j++) {
			cin>>A;
			tmp|=(1LL<<(A-1));
		}
		k.push_back(tmp);
	}
	cin>>M;
	for(int i=0;i<M;i++) {
		cin>>P;
		ll tmp = 0;
		for(int j=0;j<P;j++) {
			cin>>B;
			tmp|=(1LL<<(B-1));
		}
		p.push_back(tmp);
	}
	for(int i=0;i<M;i++) {
		int cnt = 0;
		for(int j=0;j<N;j++) {
			ll tmp = k[j]&p[i];
			if(tmp == k[j]) cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}