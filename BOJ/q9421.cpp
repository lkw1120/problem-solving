#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
bool arr[MAX] = {false};
int N,ans;
void preload() {
	fill(arr,arr+MAX,true);
	arr[0] = arr[1] = false;
	for(int i=2;i<=sqrt(MAX);i++) {
		if(arr[i]) {
			for(int j=i*i;j<MAX;j+=i) {
				arr[j] = false;
			}
		}
	}
}
bool solve(int n) {
	map<int,bool> mp;
	int a,b;
	a = n;
	b = 0;
	while(true) {
		b = 0;
		while(a) {
			b+=pow(a%10,2);
			a/=10;
		}
		if(b == 1) {
            return true;
		}
		if(!mp[b]) {
			mp[b] = true;
		}
		else {
			return false;	
		}
		a = b;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>N;
	for(int i=2;i<=N;i++) {
		if(arr[i]) {
			if(solve(i)) {
				cout<<i<<"\n";
			}
		}
	}
	return 0;
}