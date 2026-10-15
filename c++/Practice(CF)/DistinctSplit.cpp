#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(i,a,b) for(lli i=a;i<b;i++)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin >> n;
        string s;
        cin >> s;
        vll prefix(n),suffix(n);
        unordered_set<char> left,right;
        f(i,n){
            left.insert(s[i]);
            prefix[i]=left.size();
        }
        for(lli i=n-1;i>=0;i--) {
            right.insert(s[i]);
            suffix[i]=right.size();
        }
        lli maxi=0;
        for(lli i=0;i<n-1;i++) {
            maxi=max(maxi,prefix[i]+suffix[i+1]);
        }
    }
    return 0;
}