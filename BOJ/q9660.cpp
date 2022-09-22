#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	if(N%7 == 0 || N%7 == 2)
		cout<<"CY"<<"\n";
	else
		cout<<"SK"<<"\n";
	return 0;	
}