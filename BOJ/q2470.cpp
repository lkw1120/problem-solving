#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int arr[MAX] = {0};
int N,sum;
pair<int,int> ans;
void solve(int low, int high) {
	while(low<high) {
		int l, h;
		l = arr[low];
		h = arr[high];
		if(abs(l+h) < sum) {
			sum = abs(l+h);
			ans = {l,h};
		}
		if(l+h < 0) {
			low++;
		}
		else {
			high--;
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>arr[i];
	}
	sort(arr,arr+N);
	sum = INT_MAX;
	solve(0,N-1);
	cout<<ans.first<<" "<<ans.second<<"\n";
	return 0;
}