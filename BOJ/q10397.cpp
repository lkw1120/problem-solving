#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    int size = str.size();
    ll cnt = 0;
    int l = 0, r = 0;
    while(l < size) {
        if (!isdigit(str[l])) {
            l++;
        }
        else {
            r = l;
            while(r < size && isdigit(str[r])) {
                r++;
            }
            ll freq[3] = {0, 0, 0};
            int prefix = 0;
            freq[prefix]++;
            for(int i=l;i<r;i++) {
                prefix = (prefix+(str[i]-'0'))%3;
                freq[prefix]++;
            }
            for(int i=0;i<3;i++) {
                cnt+=freq[i]*(freq[i]-1LL)/2;
            }
            l = r;
        }
    }
    ans = cnt;
    cout<<cnt<<"\n";
    return 0;
}