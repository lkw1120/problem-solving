#include<bits/stdc++.h>
using namespace std;
string str;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        cin>>str;
        if(cin.eof()) break;
        ans = 0;
        int size = str.size();
        for(int i=0;i<size;i++) {
            int k = i;
            for(int j=i+1;j<size;j++) {
                if(str[j] < str[k]) k = j;
            }
            if(k != i) {
                swap(str[i],str[k]);
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}