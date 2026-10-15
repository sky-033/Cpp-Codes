#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<pair<lli,lli>>>
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
        vll a(n);
        f(i,n) cin>>a[i];
        bool flag2=false,flag_2=false;
        lli ct=0;
        vvll container;
        f(i,n){
            if(a[i]==2) flag2=true;
            if(a[i]==-2) flag_2=true;
            if(a[i]==0) ct++;
        }
        if(!flag2 && !flag_2) cout<<n<<" "<<0<<"\n";
        else{
            lli i1=-1,i2=-1;
            container.resize(ct+1);
            lli s=0;
            ff(0,n,1){
                if(a[i]!=0) container[s].push_back({a[i],i});
                else s++;
            }
            lli maxi=-1;
            fa(container){
                if(it.size()>0){
                    lli prod=0;
                    lli c=0;
                    for(auto val : it){
                        if(val.first<0) c++;
                        if(val.first==2 || val.first==-2) prod++;
                    }
                    if(c&1){
                        if(it.size()==1) continue;
                        else{
                            lli i11=-1,i22=-1,i12=-1,i21=-1;
                            lli p1=0,p2=0;
                            for(auto val : it){
                                if(val.first==2 || val.first==-2) p1++;
                                if(val.first<0){
                                    i11=val.second+1;
                                    break;
                                }
                            }
                            i22=it[it.size()-1].second;
                            for(auto itt=it.end();itt!=it.begin();){
                                --itt;
                                if(itt->first==2 || itt->first==-2) p2++;
                                if(itt->first<0){
                                    i21=itt->second-1;
                                    break;
                                }
                            }
                            i12=it[0].second;
                            if((p1)>(p2)){
                                if((prod)-(p2) > maxi){
                                    i1=i12,i2=i21;
                                    maxi=prod-p2;
                                }

                            }
                            else{
                                if((prod)-(p1) > maxi){
                                    i1=i11,i2=i22;
                                    maxi=prod-p1;
                                }
                            }
                        }
                    }
                    else{
                        if(prod>maxi){
                            maxi=prod;
                            i1=it[0].second,i2=it[it.size()-1].second;
                        }
                    }
                }

            }
            if(maxi<=0) cout<<n<<" "<<0<<"\n";
            else cout<<i1<<" "<<n-i2-1<<"\n";
            
        }
    }
    return 0;
}