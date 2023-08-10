#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+3;
int arr[MAX] = {0};
int N,K,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<K;i++) {
		cin>>A>>B;
		arr[A]++;
		arr[B+1]--;
	}
	int now = 0;
	for(int i=1;i<=N;i++) {
		now+=arr[i];
		arr[i] = now;
	}
	sort(arr+1,arr+N+1);
	ans = arr[(N+1)/2];
	cout<<ans<<"\n";
	return 0;
}