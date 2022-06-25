#include<bits/stdc++.h>
using namespace std;
string input;
bool flag;
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>input;
	ans = 0;
    sort(input.begin(), input.end());
    do {
		flag = true;
		for(int i=1;i<input.size();i++) {
			if(input[i] == input[i-1]) {
				flag = false;
				break;
			}
		}
		if(flag) ans++;
    } while(next_permutation(input.begin(), input.end()));
	cout<<ans<<"\n";
	return 0;
}