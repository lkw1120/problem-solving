#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll T,N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N;
		if(N%9 == 0 || N%3 == 2) {
			cout<<"TAK"<<"\n";
		}
		else {
			cout<<"NIE"<<"\n";	
		}
	}
	return 0;
}