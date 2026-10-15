#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

vp removeDuplicates(vll &input) {
    unordered_set<lli> seen;
    vp result;
    for (int i = input.size() - 1; i >= 0; --i) {
        int val = input[i];
        if (seen.insert(val).second) {
            result.push_back({val, i+1}); 
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        vp ans=removeDuplicates(a);
        lli size=ans.size();
        lli maxi=-1e18;
        f(i,size){
            for(lli j=i;j<size;j++){
                if(__gcd(ans[i].first,ans[j].first)==1){
                    maxi=max(maxi,ans[i].second+ans[j].second);
                }
            }
        }
        cout<<maxi<<endl;
    }
    return 0;
}