#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
int arr[MAX];
int res[MAX];
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	res[N] = -1;
	for(int i=N-1;i>0;i--) {
	    if(arr[i] != arr[i+1]) {
	        res[i] = i+1;
	    }
	    else {
	        res[i] = res[i+1];
	    }
	}
	for(int i=1;i<=N;i++) {
	    cout<<res[i]<<" ";
	}
	cout<<"\n";
	return 0;
}