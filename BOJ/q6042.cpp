#include<bits/stdc++.h>
using namespace std;
int arr1[181];
int arr2[181];
int dp[181];
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		cin>>arr1[i];	
	}
	for(int i=1;i<=M;i++) {
		cin>>arr2[i];	
	}
    for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(arr1[i] == arr2[j]) {
				int cnt = 0;
				int k = 0;
				while(i+k <= N || j+k <= M) {
					if(arr1[i+k] == arr2[j+k]) {
						cnt++;	
					}
					else {
						break;
					}
					k++;
				}
				dp[i] = max(dp[i],cnt);
			}
		}
    }
	ans = *max_element(dp+1,dp+N+1);
    cout<<ans<<"\n";
	return 0;
}