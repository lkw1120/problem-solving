#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX];
int dp[MAX];
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	for(int i=1;i<=N;i++) {
		if(i%2) {
			dp[0]+=arr[i];
		}
		else {
			dp[0]-=arr[i];	
		}
	}
	for(int i=1;i<=N;i++) {
		dp[i] = arr[i]*2-dp[i-1];
	}
	for(int i=0;i<N;i++) {
		cout<<dp[i]<<" ";
	}
	cout<<"\n";
	return 0;
}