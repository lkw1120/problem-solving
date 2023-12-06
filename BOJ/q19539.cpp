#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX];
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int sum,cnt;
	sum = cnt = 0;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		sum+=arr[i];
		cnt+=arr[i]/2;
	}
	if(sum%3 == 0 && sum/3 <= cnt) {
		cout<<"YES"<<"\n";	
	}
	else {
		cout<<"NO"<<"\n";	
	}
	return 0;
}