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
        vll a(2*n);
        f(i,2*n) cin>>a[i];
        vll starting(n),ending(n);
        starting[0]=a[0],ending[0]=a[2*n-1];
        ff(1,n,1) starting[i]=starting[i-1]+a[i];
        lli ct=1;
        for(lli i=2*n-2;i>=n;i--) ending[ct]=ending[ct-1]+a[i],ct++;
        lli sumEven=0,sumOdd=0;
        f(i,2*n){
            if(i&1) sumOdd+=a[i];
            else sumEven+=a[i];
        }
        // f(i,n) cout<<starting[i]<<" "<<ending[i]<<endl;
        cout<<sumOdd-sumEven<<' ';
        // cout<<sumEven<<" "<<sumOdd<<endl;
        f(i,n-1){
            lli indx=i;
            if(i&1){
                sumOdd-=a[i];
                sumEven-=a[2*n-1-i];
            }
            else{
                sumEven-=a[i];
                sumOdd-=a[2*n-1-i];
            }
            // cout<<sumEven<<" "<<sumOdd<<endl;
            if(i&1){
                cout<<ending[i]-starting[i]-sumEven+sumOdd<<' ';
            }
            else{
                cout<<ending[i]-starting[i]-sumOdd+sumEven<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}