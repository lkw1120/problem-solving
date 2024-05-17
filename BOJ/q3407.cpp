#include<bits/stdc++.h>
using namespace std;
string elements[114] = {
    "h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p","s","cl","ar",
    "k","ca","sc","ti","v","cr","mn","fe","co","ni","cu","zn","ga","ge","as","se","br","kr",
    "rb","sr","y","zr","nb","mo","tc","ru","rh","pd","ag","cd","in","sn","sb","te","i","xe",
    "cs","ba","hf","ta","w","re","os","ir","pt","au","hg","tl","pb","bi","po","at","rn",
    "fr","ra","rf","db","sg","bh","hs","mt","ds","rg","cn","fl","lv",
    "la","ce","pr","nd","pm","sm","eu","gd","tb","dy","ho","er","tm","yb","lu",
    "ac","th","pa","u","np","pu","am","cm","bk","cf","es","fm","md","no","lr"
};
unordered_map<string,bool> mp;
bool visited[50001];
int T;
void init() {
    for(auto item: elements) {
        mp[item] = true;
    }
}
bool bfs(string str) {
    int size = str.size();
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int idx = q.front();
        q.pop();
        if(idx == size) {
            return true;
        }
        string str1,str2;
        str1 = str.substr(idx,1);
        str2 = str.substr(idx,2);
        if(!visited[idx+1] && mp[str1]) {
            visited[idx] = true;
            q.push(idx+1);
        }
        if(!visited[idx+2] && mp[str2]) {
            visited[idx+1] = true;
            q.push(idx+2);
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>T;
    while(T--) {
        fill(visited,visited+50001,false);
        string str;
        cin>>str;
        transform(str.begin(),str.end(),str.begin(),::tolower);
        if(bfs(str)) {
            cout<<"YES"<<"\n";
        }
        else {
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}