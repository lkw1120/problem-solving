#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int arr[10] = {0};
int N,F;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>F;
	for(int i=1;i<=N;i++) {
		v.push_back(i);
	}
	do {
		fill(arr,arr+10,0);
		for(int i=0;i<N;i++) {
			arr[i] = v[i];	
		}
		for(int i=N;i>0;i--) {
			for(int j=0;j<i-1;j++) {
				arr[j]+=arr[j+1];
			}
		}
		if(arr[0] == F) {
			for(auto item: v) {
				cout<<item<<" ";
			}
			cout<<"\n";
			break;
		}
	} while(next_permutation(v.begin(),v.end()));
	return 0;	
}