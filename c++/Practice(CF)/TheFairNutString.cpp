#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=1e9+7; 

string compressB(string &s) {
    string res;
    for(char c:s){
        if(c!='b' || res.empty() || res.back()!='b') res.push_back(c); 
    }
    return res;
}
string removeOther(string &s){
    lli n=s.size();
    string temp;
    f(i,n){
        if(s[i]=='a' || s[i]=='b') temp.push_back(s[i]);
    }
    return temp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    s=removeOther(s);
    lli start=0;
    while(start<s.size() && s[start]=='b') start++;
    lli end=s.size()-1;
    while(end>=0 && s[end]=='b') end--;
    string result="";
    if (start<=end) result=s.substr(start,end-start+1);
    s=result;
    s=compressB(s);
    // cout<<s<<" ";
    lli n=s.size();
    lli l=0,ct=0;
    vll act,ans;
    while(l<n){
        if(s[l]=='a'){
            ct++;
        }
        else if(s[l]=='b'){
            act.push_back(ct);
            ct=0;
        }
        l++;
    }
    if(act.size()==0) ans.push_back(1);
    else{
        fa(act){
            if(ans.size()==0) ans.push_back(it);
            else{
                lli val=(((ans.back()+1)*(it+1))-1)%M;
                ans.push_back(val);
            }
        }
    }
    ct=0;
    lli anss=0;
    f(i,n){
        if(s[i]=='b') ct++;
        else if(s[i]=='a'){
            if(ct==0) anss=(anss+1)%M;
            else anss=(anss+ans[ct-1]+1)%M;
        }
    }
    cout<<anss<<endl;
    return 0;
}