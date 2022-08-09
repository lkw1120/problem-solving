#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int arr[MAX] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	int l,r;
	l = 1;
	r = N;
	ans = arr[l]+arr[r];
	while(l<r) {
		if(abs(arr[l]+arr[r]) < abs(ans)) {
			ans = arr[l]+arr[r];
		}
		if(arr[l]+arr[r] < 0) {
			l++;
		}
		else if(arr[l]+arr[r] > 0) {
			r--;
		}
		else {
			ans = 0;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}