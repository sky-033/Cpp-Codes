#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 
bool isPrime(lli n) {
    if (n <= 1) return false;          
    if (n == 2 || n == 3) return true; 
    if (n % 2 == 0) return false;      
    for (int i = 3; i*i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli x,k;
        cin>>x>>k;
        if(k==1){
            if(isPrime(x)){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else if(k==2 && x==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}