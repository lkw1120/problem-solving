#include<bits/stdc++.h>
using namespace std;
int even[26];
int odd[26];
string str;
int T,N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        fill(even,even+26,0);
        fill(odd,odd+26,0);;
        cin>>N>>str;
        for(int i=0;i<N;i++) {
            int ch = str[i]-'a';
            if(i%2 == 0) {
                even[ch]++;
            }
            else {
                odd[ch]++;
            }
        }
        bool flag = true;
        if(N%2 == 0) {
            for(int i=0;i<26;i++) {
                if(even[i] != odd[i]) { 
                    flag = false;
                    break;
                }
            }
        }
        else {
            int e,o;
            e = o = 0;
            for(int i=0;i<26;i++) {
                if(even[i]%2) {
                    e++;
                }
                if(odd[i]%2) {
                    o++;
                }
            }
            if(e > 1 || o > 1) {
                flag = false;
            }
        }
        if(flag) {
            cout<<"YES"<<"\n";
        }
        else {
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}