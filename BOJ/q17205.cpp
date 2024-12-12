#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll arr[10];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>str;
    for(int i=0;i<str.size();i++) {
        arr[i] = str[i]-'a'+1;
    }
    ll tmp,sum;
    ans = 0;
    for(int i=0;i<N;i++) {
        if(!arr[i]) break;
        tmp = 1;
        sum = 0;
        for(int j=i;j<N;j++) {
            sum+=tmp;
            tmp*=26;
        }
        ans+=(arr[i]-1)*sum+1;
    }
    cout<<ans<<"\n";
    return 0;
}