#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX] = {0};
int fail[MAX] = {0};
int N,Q,X,Y,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	for(int i=1;i<N;i++) {
		fail[i]+=fail[i-1];
		if(arr[i] > arr[i+1]) fail[i]++;
	}
	cin>>Q;
	for(int i=0;i<Q;i++) {
		cin>>X>>Y;
		ans = 0;
		if(X < Y) {
			ans = fail[Y-1]-fail[X-1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}