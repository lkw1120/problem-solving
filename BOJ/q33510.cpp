#include <bits/stdc++.h>
using namespace std;
string str;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>str;
    int cnt,carry,tmp;
    cnt = carry = tmp = 0;
    for(int i=N-1;i>=0;i--) {
        int bit = str[i] == '1';
        int sum = bit+carry;
        tmp+=bit;
        if(sum%2) {
            cnt++;
            carry = 1;
        }
        else {
            carry = sum/2;
        }
    }
    ans = 0;
    if(1 < tmp) {
        ans = cnt;
    }
    cout<<ans<<"\n";
    return 0;
}