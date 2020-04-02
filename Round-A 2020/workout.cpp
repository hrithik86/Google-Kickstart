/*
Workout
Hint:Binary search on answer.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool possible(ll *a,ll n,ll d, ll k){
    ll k_needed=0;
    for(ll i=0;i<n-1;i++){
        ll diff=a[i+1]-a[i];
        if(diff%d==0){
            k_needed+=diff/d-1;
        }
        else{
            k_needed+=diff/d;
        }
    }
    if(k_needed>k){
        return false;
    }
    return true;
}

int main()
{
    ll T;
    cin>>T;
    for(ll t=1;t<=T;t++){
        ll n,k;
        cin>>n>>k;
        ll *a=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll low=1,high=1000000000-1;
        ll mid=(low+high)/2;
        ll ans;
        while(low<=high){
            if(possible(a,n,mid,k)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;    
            }
            mid=(low+high)/2;
        }
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
    return 0;
}
