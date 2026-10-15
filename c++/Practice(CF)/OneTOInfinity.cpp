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

lli binExpItr(lli a,lli b){
    lli ans=1;
    while(b>0){
        if(b&1) ans=(ans*a);
        a=(a*a);
        b>>=1;
    }
    return ans;
}

vll digitSum(16),NoOfDigits(16);

void precompute(){
    digitSum[1]=45;
    ff(2,16,1){
        digitSum[i]=i*45*binExpItr(10,i-1);
    }
    NoOfDigits[1]=9;
    ff(2,16,1){
        NoOfDigits[i]=9*binExpItr(10,i-1)*i;
    }
}
lli summ(lli n){
    if(n<=0) return 0;
    if(n<10) return n*(n+1)/2;
    lli d=to_string(n).size();
    lli power=binExpItr(10,d-1);
    lli digit=n/power;
    lli res=n%power;
    return ((res+1)*digit + power*(digit-1)*digit/2 + digit*digitSum[d-1] + summ(res));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    precompute();
    while(t--){
        lli n;
        cin>>n;
        lli sum=0;
        lli d=0;
        ff(1,16,1){
            if(sum+NoOfDigits[i]<n){
                sum+=NoOfDigits[i];
                d=i;
            }
        }
        lli left=n-sum,rem=0;
        if(d==0) cout<<n*(n+1)/2<<"\n";
        else{
            if(d!=15) d++;
            if(left%d!=0){
                rem=left%d;
                left-=rem;
            }
            // cout<<d<<" ";
            left/=d;
            lli num=binExpItr(10,d-1)+left-1;
            lli ans=summ(num);
            lli next=0;
            if(rem!=0) next=num+1;
            stack<lli> st;
            while(next>0){
                st.push(next%10);
                next/=10;
            }
            while(!st.empty() && rem>0){
                ans+=st.top();
                st.pop();
                rem--;
            }
            cout<<ans<<"\n";
        }
        // ff(1,16,1) cout<<NoOfDigits[i]<<" "<<digitSum[i]<<endl;
    }
    return 0;
}