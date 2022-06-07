#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int arr[MAX] = {0};
int N,S,sum,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>S;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	int l,r;
	l = r = 1;
	ans = N+1;
	sum = arr[1];
	while(l <= r && r <= N) {
		if(sum < S) {
			r++;
			sum+=arr[r];
		}
		else if(sum >= S) {
			if(ans > r-l+1) {
				ans = r-l+1;
			}
			l++;
			sum-=arr[l-1];
		}
	}
	if(ans > N) ans = 0;
	cout<<ans<<"\n";
	return 0;
}