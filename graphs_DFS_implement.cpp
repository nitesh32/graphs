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
void func(int** ed,ll n,ll st,int* vi){
    cout<<st<<" ";
    vi[st]=1;
    for(i=0;i<n;i++){
        if(i==st){
            continue;
        }
        if(ed[st][i]==1){
            if(vi[i]==1){
                continue;
            }
            func(ed,n,i,vi);
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
    int** ed=new int*[n];
    for(i=0;i<n;i++){
        ed[i]=new int[n];
        for(ll j=0;j<n;j++){
            ed[i][j]=0;
        }
    }
    for(i=0;i<e;i++){
        ll a,b;
        cin>>a>>b;
        ed[a][b]=1;
        ed[b][a]=1;
    }
    int* visited = new int[n];
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    func(ed,n,0,visited);
return 0;
}