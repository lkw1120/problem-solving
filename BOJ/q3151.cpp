#include<bits/stdc++.h>
#define MAX 10001
typedef long long ll;
using namespace std;
int arr[MAX] = {0};
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>arr[i];	
	}
	sort(arr,arr+N);
	ans = 0;
	for(int i=0;i<N-2;i++) {
		if(0 < arr[i]) break;
		for(int j=i+1;j<N-1;j++) {
			int upper = upper_bound(arr+j+1,arr+N,-(arr[i]+arr[j]))-arr;
			int lower = lower_bound(arr+j+1,arr+N,-(arr[i]+arr[j]))-arr;
			ans+=(upper-lower);
		}
	}
	cout<<ans<<"\n";
	return 0;
}