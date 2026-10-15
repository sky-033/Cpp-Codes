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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    vector<pair<pair<lli,lli>,lli>> pairs;
    map<lli,lli> op;
    f(i,n){
        lli a,b;
        cin>>a>>b;
        op[a]++;
        pairs.push_back({{a,b},i});
    }
    lli l=-1;
    fa(op){
        if(it.second>1) l=it.first;
    }
    if(l!=-1){
        lli a1=-1e9,a2,i1,i2;
        fa(pairs){
            if(l==it.first.first && a1==-1e9){
                a1=it.first.second;
                i1=it.second;
            }
            if(l==it.first.first && a1!=-1e9){
                a2=it.first.second;
                i2=it.second;
            }
        }
        if(a1>a2) cout<<i2+1<<" "<<i1+1<<"\n";
        else cout<<i1+1<<" "<<i2+1<<"\n";
    }
    else{
        sor(pairs);
        bool flag=true;
        lli maxi=-1,indx=-1;
        fa(pairs){
            if(maxi==-1){
                maxi=it.first.second;
                indx=it.second;
            }
            else{
                if(maxi>=it.first.second){
                    cout<<it.second+1<<" "<<indx+1<<"\n";
                    flag=false;
                    break;
                }
                else{
                    maxi=it.first.second;
                    indx=it.second;
                }
            }
        }
        if(flag) cout<<-1<<" "<<-1<<"\n";
    }
    return 0;
}