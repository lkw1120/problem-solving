#include<bits/stdc++.h>
using namespace std;
string str;
int T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    cin.ignore();
    while(T--) {
	    getline(cin,str);
        int size = str.size();
        int depth,tmp;
        depth = tmp = 0;
        for(int i=0;i<size;i++) {
            if(str[i] == '[') {
                tmp++;
            }
            else {
                depth = max(tmp,depth);
                tmp--;
            }
        }
        ans = 1<<depth;
        cout<<ans<<"\n";
    }
    return 0;
}