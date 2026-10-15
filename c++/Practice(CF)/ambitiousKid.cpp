#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    int N;
    cin>>N;
    vll A(N);
    lli mini=1e18;
    f(i,N){
        cin>>A[i];
        if(A[i]<0) A[i]=-1*A[i];
        mini=min(mini,A[i]);
    }
    cout<<mini<<endl;
    return 0;
}