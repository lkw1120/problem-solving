#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
int arr[MAX];
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		if(arr[i]) {
			ans++;
			for(int j=i;j<=min(i+2,N);j++) {
				arr[j] = 1-arr[j];
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}