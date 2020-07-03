#include<bits/stdc++.h>
using namespace std;
string str,sub;
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>str>>sub;
	ans = 0;
	if(strstr(str.c_str(),sub.c_str()) != NULL) {
		ans = 1;
    }
	cout<<ans<<"\n";
    return 0;
}