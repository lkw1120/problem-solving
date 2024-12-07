#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
	if(N%2 == 0 || N%5 == 0) {
	    ans = -1;
	}
	else {
        int tmp = 1;
        ans = 1;
    	while(tmp%N) {
    		ans++;
    		tmp = (tmp%N)*10+1;
    	}
	}
	cout<<ans<<"\n";
	return 0;
}