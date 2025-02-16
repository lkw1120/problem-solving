#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll dksh[4];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>str;
    for(int i=0;i<N;i++) {
        if(str[i] == 'D') dksh[0]++;
        if(str[i] == 'K') dksh[1]+=dksh[0];
        if(str[i] == 'S') dksh[2]+=dksh[1];
        if(str[i] == 'H') dksh[3]+=dksh[2];
    }
    ans = dksh[3];
    cout<<ans<<"\n";
    return 0;
}