#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n;
    cin>>n;
    if(n==2) cout<<-1<<endl;
    else if(n==3){
        cout<<"1 3"<<endl;
        cout<<"2 3"<<endl;
    }
    else if(n==4){
        cout<<"1 2"<<endl;
        cout<<"3 1"<<endl;
        cout<<"4 1"<<endl;
    }
    else if(n==5){
        cout<<"2 1"<<endl;
        cout<<"1 5"<<endl;
        cout<<"2 3"<<endl;
        cout<<"3 4"<<endl;
    }
    else{
        cout<<"2 1"<<endl;
        cout<<"2 3"<<endl;
        cout<<"3 4"<<endl;
        cout<<"1 "<<n<<endl;
        ff(5,n,1) cout<<"2 "<<i<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}