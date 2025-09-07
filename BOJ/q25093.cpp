#include<bits/stdc++.h>
using namespace std;
string str;
int T;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>str;
        int size = str.size();
        string res = "";
        for(int i=0;i<size;) {
            int j = i;
            while(j < size && str[i] == str[j]) {
                j++;
            }
            bool flag = (j < size && str[i] < str[j]);
            int cnt = j-i;
            if(flag) {
                res+=string(cnt*2,str[i]);
            }
            else {
                res+=string(cnt,str[i]);
            }
            i = j;
        }
        cout<<"Case #"<<tc<<": "<<res<<"\n";
    }
    return 0;
}