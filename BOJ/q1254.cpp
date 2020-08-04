#include<bits/stdc++.h>
using namespace std;
string str1,str2;
int ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>str1;
    str2 = str1;
    reverse(str2.begin(),str2.end());
    int size = str1.size();
    ans = 0;
    for(int i=0;i<size;i++) {
        if(str1.substr(i) == str2.substr(0,size-i)) {
            ans = i*2+(size-i);
            break;
        }
    }
	cout<<ans<<"\n";
	return 0;
}