#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,cnt;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	v.resize(N);
	for(int i=0;i<N;i++) {
		v[i] = i+1;
	}
	cnt = 0;
	for(int i=1;i<N;i++) {
		for(int j=N-1;j>i-1;j--) {
			if(cnt >= K) break;
			swap(v[j],v[j-1]);
			cnt++;
		}
		if(cnt >= K) break;
	}
	for(int i=0;i<N;i++) {
		cout<<v[i]<<" ";	
	}
	cout<<"\n";
	return 0;
}