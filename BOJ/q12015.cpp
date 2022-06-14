#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
int arr[MAX] = {0};
int lis[MAX] = {0};
int N,ans;
int binarySearch(int l, int r, int t) {
	int mid;
	while(l < r) {
		mid = (l+r)/2;
		if(lis[mid] < t) {
			l = mid+1;
		}
		else {
			r = mid;
		}
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	int i = 2;
	int j = 1;
	lis[1] = arr[1];
	while(i <= N) {
		if(lis[j] < arr[i]) {
			lis[j+1] = arr[i];
			j++;
		}
		else {
			int k = binarySearch(0, j, arr[i]);
			lis[k] = arr[i];
		}
		i++;
	}
	ans = j;
	cout<<ans<<"\n";
	return 0;
}