#include<bits/stdc++.h>
using namespace std;
string str;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    int size = str.size();
    if(size%2 != 0) {
        ans = 0;
    }
    else {
        int half = size/2;
        vector<int> v(half,0);
        for(int i=0;i<half;i++) {
            char ch1 = str[2*i];
            char ch2 = str[2*i+1];
            if(ch1 == '+' && ch2 == '-') v[i] = 0;
            if(ch1 == '-' && ch2 == '+') v[i] = 1;
        }
        int a,b;
        a = b = 0;
        for(int i=0;i<half;i++) {
            if(i == 0 || v[i] != v[i-1]) {
                if(v[i] == 0) {
                    a++;
                }
                else {
                    b++;
                }
            }
        }
        ans = min(a,b);
    }
    cout<<ans<<"\n";
    return 0;
}