#include<bits/stdc++.h>
using namespace std;
int arr[9] = {0};
int input[9] = {0};
int N,M;
void solve(int m, int n) {
	if(m > M) {
		for(int i=1;i<=M;i++) {
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return ;
	}
	for(int i=n;i<=N;i++) {
		arr[m] = input[i];
		solve(m+1,i);
	}
}
bool compare(int a, int b) { return a < b; }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		cin>>input[i];
	}
	sort(input,input+N+1,compare);
	solve(1,1);
	return 0;
}