#include<bits/stdc++.h>
using namespace std;
string str,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    ans = "";
    for(int i=str.size()-1;i>=0;) {
        char ch = str[i];
        int j = i;
        while(j >= 0 && str[j] == ch) j--;
        int cnt = i-j;
        if(ch == 'l' || ch == 'r') {
            int add = (6-(cnt%6))%6;
            while(add--) ans+=ch;
        } 
        else {
            if(cnt%2 == 1) ans+="b";
        }
        i = j;
    }
    cout<<ans<<"\n";
    return 0;
}