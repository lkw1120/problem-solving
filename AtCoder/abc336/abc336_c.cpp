#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    N--;
    if(N == 0) {
        ans = "0";
    }
    else {
        ans = "";
        string digit = "02468";
        while(0 < N) {
            ans.push_back(digit[N%5]);
            N/=5;
        }
        reverse(ans.begin(),ans.end());
    }
    cout<<ans<<"\n";
    return 0;
}