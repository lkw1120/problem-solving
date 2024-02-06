#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
int arr[MAX];
int N,M,V,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>V;
	for(int i=0;i<N;i++) {
		cin>>arr[i];
	}
	for(int i=0;i<M;i++) {
		cin>>K;
		if(K < N) {
			ans = arr[K];
		}
		else {
			int idx = (K-(V-1))%(N-V+1)+(V-1);
			ans = arr[idx];
		}
		cout<<ans<<"\n";
	}
	return 0;
}