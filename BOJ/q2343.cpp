#include<bits/stdc++.h>
#define MAX 100001
typedef long long ll;
using namespace std;
ll arr[MAX] = {0};
ll low,high,mid;
ll N,M,sum,cnt,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	low = high = 0;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		low = max(low,arr[i]);
		high+=arr[i];
	}
	while(low <= high) {
		cnt = sum = 0;
		mid = (low+high)/2;
		for(int i=1;i<=N;i++) {
			if(mid < sum+arr[i]) {
				cnt++;
				sum = 0;
			}
			sum+=arr[i];
		}
		if(sum > 0) cnt++;
		if(cnt > M) {
			low = mid+1;	
		}
		else {
			high = mid-1;
		}
	}
	ans = low;
	cout<<ans<<"\n";
	return 0;	
}