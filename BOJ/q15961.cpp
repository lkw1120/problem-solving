#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int sushi[3001] = {0};
int N,D,K,C,A,cnt,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>D>>K>>C;
	for(int i=0;i<N;i++) {
		cin>>A;
		v.push_back(A);
	}
	cnt = 0;
	for(int i=0;i<K;i++) {
		if(!sushi[v[i]]) {
			cnt++;
		}
		sushi[v[i]]++;
	}
	ans = cnt;
	for(int i=K;i<N+K;i++) {
		if(!(--sushi[v[(i-K)%N]])) {
			cnt--;
		}
		if(!sushi[v[i%N]]++) {
			cnt++;
		}
		if(++sushi[C] == 1) {
			cnt++;
		}
		ans = max(cnt,ans);
	}
	cout<<ans<<"\n";
	return 0;	
}