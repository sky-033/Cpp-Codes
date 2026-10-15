#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define vll vector<char>
#define vvll vector<vector<char>>
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
        lli n,k;
        cin>>n>>k;
        vvll v(n,vll(n));
        f(i,n){
            f(j,n) v[i][j]='X';
        }
        if((n*n-k)==1) cout<<"NO"<<'\n';
        else{
            cout<<"YES"<<"\n";
            lli maze=(n*n-k);
            lli rows=maze/n;
            if(rows>0){
                f(i,rows) v[i][0]='R';
            }
            f(i,rows){
                for(lli j=1;j<n;j++) v[i][j]='L';
            }
            if(maze-rows*n>0){
                if(maze-rows*n==1 && rows!=0) v[rows][0]='U';
                else{
                    v[rows][0]='R';
                    for(lli i=1;i<maze-rows*n;i++) v[rows][i]='L';
                }
            }
            f(i,n){
                f(j,n) if(v[i][j]=='X') v[i][j]='R';
                
            }
            f(i,n){
                f(j,n) cout<<v[i][j];
                cout<<endl;
            }
        }
    }
    return 0;
}