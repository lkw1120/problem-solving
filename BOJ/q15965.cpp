#include<bits/stdc++.h>
using namespace std;
const int MAX = 7500000;
vector<int> v;
int N,ans;
void preload() {
    bool arr[MAX];
	fill(arr,arr+MAX,true);
	for(int i=2;i<MAX;i++) {
		if(!arr[i]) {
			continue;
		}
		else {
			v.push_back(i);	
		}
		for(int j=i+i;j<MAX;j+=i) {
			arr[j] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>N;
	ans = v[N-1];
	cout<<ans<<"\n";
	return 0;
}