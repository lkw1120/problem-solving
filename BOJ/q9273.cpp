#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>str;
        if(cin.eof()) break;
        int p = str.find('/');
        int n = stoi(str.substr(p+1));
        ll d = 1;
        int tmp = n;
        for (int i=2;i*i<=tmp;i++){
            int cnt = 0;
            while(tmp%i == 0){
                cnt++;
                tmp/=i;
            }
            if(0 < cnt){
                d*=(2*cnt+1);
            }
        }
        if(1 < tmp) {
            d*=3;
        }
        ans = (d+1)/2;
        cout<<ans<<"\n";
    }
    return 0;
}