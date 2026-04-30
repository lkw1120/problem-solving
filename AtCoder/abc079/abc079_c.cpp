#include<bits/stdc++.h>
using namespace std;
string str,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    int arr[4];
    for(int i=0;i<4;i++) {
        arr[i] = str[i]-'0';
    }
    for(int n=0;n<8;n++) {
        int tmp = arr[0];
        string cur = "";
        cur+=str[0];
        for(int i=1;i<4;i++) {
            if(n & (1<<(i-1))) {
                tmp-=arr[i];
                cur+='-';
            }
            else {
                tmp+=arr[i];
                cur+='+';
            }
            cur+=str[i];
        }
        if(tmp == 7) {
            cur+="=7";
            ans = cur;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}