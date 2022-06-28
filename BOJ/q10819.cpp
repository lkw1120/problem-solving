#include<bits/stdc++.h>
using namespace std;
int arr[8] = {0};
int N,A,sum,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>arr[i];
	}
	ans = 0;
	sort(arr,arr+N);
	do {
		sum = 0;
		for(int i=1;i<N;i++) {
			sum+=abs(arr[i-1]-arr[i]);
		}
		ans = max(ans,sum);
	} while(next_permutation(arr,arr+N));
	cout<<ans<<"\n";
	return 0;
}