#include<bits/stdc++.h>
using namespace std;
int arr[9] = {0};
int N,M;
void solve(int m) {
	if(m > M) {
		for(int i=1;i<=M;i++) {
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return ;
	}
	for(int i=arr[m-1];i<=N;i++) {
		arr[m] = i;
		solve(m+1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	arr[0] = 1;
	solve(1);
	return 0;
}
