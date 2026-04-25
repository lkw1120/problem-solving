#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[27];
ll N;
string str,ans;
int toIdx(char ch) {
    if(ch == '_') return 26;
    return ch-'A';
}
char toChar(int x) {
    if(x == 26) return '_';
    return char('A'+x);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<27;i++) {
        char ch;
        cin>>ch;
        arr[i] = toIdx(ch);
    }
    cin>>N;
    cin>>str;
    ans = "";
    for(char ch: str) {
        int cur = toIdx(ch);
        vector<int> v;
        int x = cur;
        do {
            v.push_back(x);
            x = arr[x];
        } while(x != cur);
        ll move = N%v.size();
        ans+=toChar(v[move]);
    }
    cout<<ans<<"\n";
    return 0;
}