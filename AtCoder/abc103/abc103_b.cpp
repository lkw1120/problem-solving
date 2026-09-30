#include<bits/stdc++.h>
using namespace std;
string str1,str2,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str1;
    cin>>str2;
    int size = str1.size();
    ans = "No";
    for(int i=0;i<size;i++) {
        if(str1.substr(i)+str1.substr(0,i) == str2) {
            ans = "Yes";
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}