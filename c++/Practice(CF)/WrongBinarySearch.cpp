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
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        string s;
        cin>>s;
        lli l=0,h=0;
        bool flag=true;
        fa(s){
            if(it=='1'){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<"\n";
            for(lli i=n;i>=1;i--) cout<<i<<" ";
            cout<<"\n";
        }
        else{
            bool check=true;
            vll p(n,0);
            f(i,n){
                if(s[i]=='1') p[i]=i+1;
            }
            lli l=0,h=0;
            
                while(h<n){
                    if(s[h]=='1'){
                        if(h-l==1){
                            check=false;
                            break;
                        }
                        lli ct=0;
                        for(lli i=l;i<h;i++){
                            p[i]=h-ct;
                            ct++;
                        }
                        h++;
                        l=h;
                    }
                    else{
                        h++;
                    }
                }
                if(h-l==1) check=false;
                lli ct=0;
                for(lli i=l;i<h;i++){
                    p[i]=h-ct;
                    ct++;
                }
            
            if(check){
                cout<<"YES"<<"\n";
                f(i,n) cout<<p[i]<<" ";
                cout<<"\n";
            }
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}