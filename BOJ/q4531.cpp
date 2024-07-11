#include<bits/stdc++.h>
using namespace std;
map<char,int> mp = {
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000}
};
string str;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>str;
        int size = str.size();
        int tmp = 0;
        ans = 0;
        for(int i=0;i<size;i++) {
            if(tmp < mp[str[i]]) {
                ans-=2*tmp;
            }
            tmp = mp[str[i]];
            ans+=tmp;
        }
        cout<<ans<<"\n";
    }
    return 0;
}