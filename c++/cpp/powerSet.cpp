#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> subsequences(vector<int> &sub, int noOfSubsets){
    vector<vector<int>> subsets;
    int n=sub.size();
    for(int num=0;num<noOfSubsets;num++){
        vector<int> list;
        for(int i=0;i<n;i++){
            if((num&(1<<i))!=0) list.push_back(sub[i]);
        }
        subsets.push_back(list);
    }
    return subsets;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int noOfSubsets=1<<n;
    vector<vector<int>> subsets=subsequences(arr,noOfSubsets);
    for(auto set:subsets){
        for(auto it:set){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}