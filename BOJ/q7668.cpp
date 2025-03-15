#include<bits/stdc++.h>
using namespace std;
string str;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>str;
        if(str == "end") break;
        ans = 0;
        for(char c: str) {
            int num = 0;
            if(c >= '0' && c <= '9') {
                num = c - '0';
            } 
            else if (c >= 'A' && c <= 'Z') {
                num = c - 'A' + 10;
            } 
            else if (c >= 'a' && c <= 'z') {
                num = c - 'a' + 36;
            }
            ans+=num;
            ans%=61;
        }
        cout<<(ans == 0? "yes": "no")<<"\n";
    }
    return 0;
}