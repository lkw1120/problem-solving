#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N,ans;
void hanoi(int n, int from, int by, int to) {
	if(n == 1) {
		cout<<from<<" "<<to<<"\n";
	}
	else {
		hanoi(n-1,from,to,by);
		cout<<from<<" "<<to<<"\n";
		hanoi(n-1,by,from,to);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	ans = pow(2,N)-1;
	cout<<ans<<"\n";
	hanoi(N,1,2,3);
	return 0;
}