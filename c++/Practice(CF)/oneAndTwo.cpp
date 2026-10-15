#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,ct2=0,indx=0;
        cin>>n;
        vll a(n);
        f(i,n){
            cin>>a[i];
            if(a[i]==2) ct2++;
        }
        if(ct2%2!=0){
            cout<<-1<<endl;
        }
        else{
            ct2/=2;
            f(i,n){
                if(a[i]==2) ct2--;
                if(ct2==0){
                    indx=i;
                    break;
                }
            }
            cout<<indx+1<<endl;
        }
        

    }
    return 0;
}