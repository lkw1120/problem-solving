#include<bits/stdc++.h>
using namespace std;
static const int MAX_N = 10000;
bool prime[MAX_N];
int arr[MAX_N];
int ans;
void eratosthenes() {
    fill(prime,prime+MAX_N,true);
    prime[0] = prime[1] = false;
    for(int i=2;i*i<MAX_N;i++) {
        if(prime[i]) {
            for(int j=2;i*j<MAX_N;j++) {
                prime[i*j] = false;
            }
        }
    }
}
int toIndex(const string str) {
    return (str[0]-'A')*26*26+(str[1]-'A')*26+(str[2]-'A');
}
string toLetter(int idx) {
    string str = "AAA";
    str[0] = 'A'+idx/(26*26);
    idx%=(26*26);
    str[1] = 'A'+idx/26;
    str[2] = 'A'+idx%26;
    return str;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes();
    int next = -1;
    for(int i=MAX_N-1;i>=0;i--) {
        if(prime[i]) next = i;
        arr[i] = next;
    }
    while(1) {
        string str;
        int num;
        cin>>str>>num;
        if (str == "END" && num == 0) break;
        int idx = toIndex(str);
        int cur = num;
        while(1) {
            int p = cur < MAX_N? arr[cur]: -1;
            if(p != -1) {
                ans = p;
                break;
            } 
            else {
                idx++;
                cur = 2;
            }
        }
        cout<<toLetter(idx)<<" "<<setw(4)<<setfill('0')<<ans<<"\n";
    }
    return 0;
}