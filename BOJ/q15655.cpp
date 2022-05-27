#include<bits/stdc++.h>
using namespace std;
int arr[9] = {0};
int input[9] = {0};
bool isUsed[9] = {false}; 
int N,M;
void solve(int m) {
	if(m > M) {
		for(int i=1;i<=M;i++) {
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return ;
	}
	for(int i=1;i<=N;i++) {
		if(!isUsed[i] && arr[m-1] < input[i]) {
			arr[m] = input[i];
			isUsed[i] = true;
			solve(m+1);
			isUsed[i] = false;
		}
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
	solve(1);
}