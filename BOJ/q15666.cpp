#include<bits/stdc++.h>
using namespace std;
int arr[9] = {0};
int input[9] = {0};
vector<int> v;
int N,M;
void solve(int m) {
	if(m > M) {
		for(int i=1;i<=M;i++) {
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return ;
	}
	for(int i=0;i<v.size();i++) {
		if(arr[m-1] <= v[i]) {
			arr[m] = v[i];
			solve(m+1);
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
	for(int i=1;i<=N;i++) {
		if(input[i] != input[i-1]) {
			v.push_back(input[i]);
		}
	}
	solve(1);
	return 0;
}