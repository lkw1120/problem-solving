#include<bits/stdc++.h>
using namespace std;
string str;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    int size = str.size();
    int idx = 0;
    for(int n=1;;n++) {
        string tmp = to_string(n);
        for(char ch: tmp) {
            if(idx < size && ch == str[idx]) {
                idx++;
            }
        }
        if(idx == size) {
            ans = n;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}