#include<bits/stdc++.h>
using namespace std;
int arr[61] = {0};
int N,K,A,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=0;i<N;i++) {
		cin>>A;
		arr[A]++;
	}
	ans = 1;
	for(int i=1;i<=N;i++) {
		if(arr[i] == 0) {
			ans = 0;
			break;
		}
		while(arr[i] > 1) {
			arr[i]--;
			arr[i+K]++;
		}
	}
	cout<<ans<<"\n";
	return 0;	
}