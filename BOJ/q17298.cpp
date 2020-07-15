#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int arr[MAX] = {0};
int nge[MAX] = {0};
stack<int> s;
int N;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	s.push(INT_MAX);
	for(int i=N;i>0;i--) {
		while(s.top() <= arr[i]) {
			s.pop();
		}
		if(s.top() == INT_MAX) {
			nge[i] = -1;
		}
		else {
			nge[i] = s.top();
		}
		s.push(arr[i]);
	}
	for(int i=1;i<=N;i++) {
		cout<<nge[i]<<" ";
	}
	cout<<"\n";
	return 0;
}