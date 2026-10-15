// #include<bits/stdc++.h>
// using namespace std;
// #define lli long long
// #define vll vector<lli>
// #define vvll vector<vector<lli>>
// #define vp vector<pair<lli,lli>>
// #define f(i,n) for(lli i=0;i<n;i++)
// #define g(j,n) for(lli j=0;j<n;j++)
// #define h(k,n) for(lli k=0;k<n;k++)
// #define rf(i,n) for(lli i=n-1;i>=0;i--)
// #define ff(a,b,c) for(lli i=a;i<b;i+=c)
// #define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
// #define fa(v) for (auto &it : v) 
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sor(x) sort(all(x))
// #define rsor(x) sort(rall(x))
// #define setbits(x) __builtin_popcountll(x)
// const lli N=2e5+10;
// const lli M=1e9+7; 

// lli n;
// vp movement={{0,1},{1,0},{0,-1},{-1,0}};
// bool isValid(lli x,lli y){
//     return x>=0 && y>=0 && y<n && x<2;
// }
// vector<string> a;
// vector<vector<bool>> vis;

// void dfs(lli x, lli y){
//     vis[x][y]=true;
//     fa(movement){
//         lli n_x=x+it.first;
//         lli n_y=y+it.second;
//         if(isValid(n_x,n_y)){
//             if(a[n_x][n_y]=='>') n_y++;
//             else n_y--;
//             if(isValid(n_x,n_y) && !vis[n_x][n_y]) dfs(n_x,n_y);
//         }
//     }
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         string s1,s2;
//         cin>>s1>>s2;
//         a.resize(2);
//         a[0]=s1;
//         a[1]=s2;
//         vis.assign(2,vector<bool>(n,false));
//         dfs(0,0);
//         if(vis[1][n-1]) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
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
        string s1,s2;
        cin>>s1>>s2;
        bool flag=true;
        bool prev=true,current=true;
        f(i,n){
            prev=current;
            current=false;
            if(i%2==0 && s2[i]=='>') current=true;
            if(i%2==1 && s1[i]=='>') current=true;
            if(!prev && !current){
                flag=false;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}