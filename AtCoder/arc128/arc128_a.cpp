#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
int arr[MAX];
int res[MAX];
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	for(int i=1;i<N;i++) {
		if(arr[i+1] < arr[i]) {
			res[i]^=1;
			res[i+1]^=1;
		}
	}
	for(int i=1;i<=N;i++) {
		cout<<res[i]<<" ";
	}
	cout<<"\n";
	return 0;
}