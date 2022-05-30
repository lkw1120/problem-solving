#include<bits/stdc++.h>
using namespace std;
int arr[9] = {0};
int input[9] = {0};
bool isUsed[9] = {false};
set<vector<int>> output;
int N,M;
void solve(int m) {
	if(m > M) {
		vector<int> v;
		for(int i=1;i<=M;i++) {
			v.push_back(arr[i]);
		}
		output.insert(v);
		return ;
	}
	for(int i=1;i<=N;i++) {
		if(!isUsed[i]) {
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
	for(auto list: output) {
		for(int i=0;i<list.size();i++) {
			cout<<list[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}