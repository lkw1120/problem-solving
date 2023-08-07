#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX] = {0};
int N,K,B,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K>>B;
	for(int i=0;i<B;i++) {
		cin>>C;
		arr[C]++;
	}
	for(int i=1;i<=N;i++) {
		arr[i]+=arr[i-1];	
	}
	ans = B;
	for(int i=K;i<=N;i++) {
		ans = min(ans,arr[i]-arr[i-K]);
	}
	cout<<ans<<"\n";
	return 0;
}