#include<bits/stdc++.h>
using namespace std;
const int MAX = sqrt(1e9)+1;
int arr[MAX] = {0};
int A,B,ans;
void init() {
	for(int i=1;i<MAX;i++) {
		arr[i] = i*i;	
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	for(int t=1;;t++) {
		cin>>A>>B;
		if(A == 0 && B == 0) break;
		ans = 0;
		for(int i=1;i<=44721;i++) {
			int x = i*(i+1)/2;
			if(A < x+1 && x+1 < B) {
				auto idx = lower_bound(arr,arr+MAX,x+1)-arr;
				if(arr[idx] == x+1) {
					ans++;
				}
			}
		}
		cout<<"Case "<<t<<": "<<ans<<"\n";
	}
	return 0;
}