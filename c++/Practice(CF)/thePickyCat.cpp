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
        if(n==1 || n==2){
            cout<<"YES"<<endl;
        }
        else{
            lli check=abs(a[0]);
            vll b(n);
            f(i,n){
                b[i]=abs(a[i]);
            }
            sort(b.begin(),b.end());
            lli ct=0;
            f(i,n){
                if(b[i]>check) ct++;
            }
            if(n%2==0){
                if(ct>=n/2-1) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else{
                if(ct>=n/2) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}