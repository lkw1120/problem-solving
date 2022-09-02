#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
map<string,int> mp;
int check[MAX] = {0};
string str;
int N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>str;
		mp[str] = i;
	}
	for(int i=0;i<N;i++) {
		cin>>str;
		check[i] = mp[str];
	}
	ans = 0;
	for(int i=0;i<N-1;i++) {
		for(int j=i+1;j<N;j++) {
			if(check[i] > check[j]) {
				ans++;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}