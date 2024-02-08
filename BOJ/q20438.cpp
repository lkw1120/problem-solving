#include<bits/stdc++.h>
using namespace std;
bool sleep[5003];
int arr[5003];
int N,K,Q,M,S,E,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(arr+3,arr+5003,1);
	cin>>N>>K>>Q>>M;
	int k,q;
	for(int i=0;i<K;i++) {
		cin>>k;
		sleep[k] = true;
	}
	for(int i=0;i<Q;i++) {
		cin>>q;
		if(!sleep[q]) {
			int n = q;
			while(n <= N+2) {
				if(!sleep[n]) {
					arr[n] = 0;
				}
				n+=q;
			}
		}
	}
	for(int i=4;i<=N+2;i++) {
		arr[i]+=arr[i-1];	
	}
	for(int i=0;i<M;i++) {
		cin>>S>>E;
		ans = arr[E]-arr[S-1];
		cout<<ans<<"\n";
	}
	return 0;
}