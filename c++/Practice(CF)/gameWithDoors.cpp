#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int L,R;
        cin>>L>>R;
        if((l<L && r<L) || (L<l && R<l)) cout<<1<<endl;
        else if((l<L && r==R) || (l==L && R<r)) cout<<R-L+1<<endl;
        else if((L<l && r==R) || (l==L && r<R)) cout<<r-l+1<<endl;
        else if(l==L && r==R) cout<<R-L<<endl;
        else cout<<min(r,R)-max(l,L)+2<<endl;
    }
    return 0;
}