#include<bits/stdc++.h>
using namespace std;
const int MAX =1e6+1;
int arr[MAX] = {0};
int N,Q,S,E,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		arr[i]^=arr[i-1];
	}
	ans = 0;
	for(int i=0;i<Q;i++) {
		cin>>S>>E;
		ans = ans^arr[S-1]^arr[E];
	}
	cout<<ans<<"\n";
	return 0;
}