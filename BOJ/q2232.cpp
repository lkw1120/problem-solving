#include<bits/stdc++.h>
using namespace std;
int arr[50001];
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	if(N == 1) {
		cout<<1<<"\n";
	}
	else {
		if(arr[1] >= arr[2]) {
			cout<<1<<"\n";
		}
		for(int i=2;i<N;i++) {
			if(arr[i-1] <= arr[i] && arr[i+1] <= arr[i]) {
				cout<<i<<"\n";
			}
		}
		if(arr[N] >= arr[N-1]) {
			cout<<N<<"\n";
		}
	}
	return 0;
}