#include<bits/stdc++.h>
using namespace std;
long long n,i;
string s;
typedef long long ll;
#define nit( i, n) for(i=0;i<n;i++)
int gcd(int a,int b){ if(b==0) return a; else return gcd(b,a%b);}
bool iseven(int n){return ((n&1)==0)?true:false;}
int pov(int n,int m){ int c=1;  while(m>0){  if(!iseven(m)){ c=c*n; } n=n*n; m=m>>1;  }  return c; }
unsigned int intlen(unsigned int n){return n ? intlen(n/10)+1 : 0;}
bool isprime(int x) { for (int d = 2; d * d <= x; d++) { if (x % d == 0) return false; }return true; }
void print(int** arr,ll n,ll st,int* vi){
    queue<ll> q;
    q.push(st);
    while(!q.empty()){
        ll ele=q.front();
        cout<<ele<<" ";
        vi[ele]=1;
        for(i=0;i<n;i++){
        if(i==ele){
            continue;
        }
        if(arr[ele][i]==1){
            if(vi[i]==1){
            continue;
            }
            q.push(i);
            vi[i]=1;
            q.pop();
        }
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("ipt.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    ll e;
    cin>>n>>e;
    int** arr=new int*[n];
    for(ll i=0;i<n;i++){
        arr[i]=new int[n];
        for(ll j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    for(ll i=0;i<e;i++){
        ll a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int* vi=new int[n];
    for(ll i=0;i<n;i++){
        vi[i]=0;
    }
    for(i=0;i<n;i++){
        if(vi[i]==0){
            print(arr,n,i,vi);
        }
    }
return 0;
}