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
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
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
        map<lli,lli> mpp;
        f(i,n){
            cin>>a[i];
            mpp[a[i]]++;
        }
        vll single;
        lli maxi=0;
        lli sides=0;
        if(mpp.size()==n) cout<<0<<"\n";
        else{
            bool flag=false;
            lli peri=0;
            lli ct=0;
            fa(mpp){
                lli ev=it.second/2;
                if(ev>=1){
                    if(ev>=2) flag=true;
                    ct++;
                    // flag=true;
                    peri+=ev*2*it.first;
                    maxi=max(maxi,it.first);
                    sides++;
                }
                if(it.second%2) single.push_back(it.first);
            }
            // cout<<maxi<<" ";
            if(ct>=2) flag=true;
            lli perimeter=peri;
            // fa(single) cout<<it<<" ";
            fa(single){
                lli temp=perimeter+it;
                lli newMaxi=max(maxi,it);
                if(newMaxi*2<temp){
                    peri=max(perimeter,temp);
                    flag=true;
                }
            }
            // cout<<maxi<<" ";
            // cout<<peri<<" ";
            sor(single);
            if(single.size()>=2){
            f(i,single.size()){
                lli newMaxi=max(maxi,single[i]);
                lli a1=single[i];
                lli temp=perimeter;
                temp+=a1;
                lli l=i+1,h=single.size()-1,ans=-1;
                while(l<=h){
                    lli mid=(l+h)/2;
                    lli newMaxi1=max(newMaxi,single[mid]);
                    lli p=temp+single[mid];
                    if(p>2*newMaxi1){
                        ans=mid;
                        l=mid+1;
                    }
                    else h=mid-1;
                }
                if(ans!=-1){
                    peri=max(perimeter,temp+single[ans]);
                    flag=true;
                }
            }
        }
        perimeter=max(perimeter,peri);
        // cout<<maxi<<" ";
        if(flag) cout<<perimeter<<"\n";
        else cout<<0<<"\n";
        }
    }
    return 0;
}