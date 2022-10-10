#include<bits/stdc++.h>
#define MAX 40001
#define DIV 123456789
using namespace std;
int dp[MAX] = {0};
vector<int> v;
int N;
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
	dp[0] = 1;
	for(int i=0;i<v.size();i++) {
		for(int j=v[i];j<=N;j++) {
			dp[j] = (dp[j]+dp[j-v[i]])%DIV;
		}
	}
	cout<<dp[N]<<"\n";
	return 0;	
}