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
        lli maxi=0,nodeM;
        map<lli,vll> depth;
        ff(1,n+1,1){
            cout<<"? "<<i<<" "<<n<<" ";
            for(lli j=1;j<=n;j++) cout<<j<<" ";
            cout<<endl;
            cout.flush();
            lli ans;
            cin>>ans;
            if(ans>maxi){
                maxi=ans;
                nodeM=i;
            }
            depth[ans].push_back(i);
        }
        vll path;
        path.push_back(nodeM);
        for(lli i=maxi-1;i>=1;i--){
            fa(depth[i]){
                cout<<"? "<<path.back()<<" "<<2<<" "<<path.back()<<" "<<it<<endl;
                cout.flush();
                lli ans;
                cin>>ans;
                if(ans==2){
                    path.push_back(it);
                    break;
                }
            }
        }
        cout<<"! "<<maxi<<" ";
        fa(path) cout<<it<<" ";
        cout<<endl;
        cout.flush();

    }
    return 0;
}