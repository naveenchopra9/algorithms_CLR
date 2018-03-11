#include <cstdio>
#include <cstdlib>
#include <cmath>
#include<iomanip>
#include<fstream>
#include<cctype>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <limits.h>
#include <map>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;
//const int INF = 0x3f3f3f3f;
#define MAXV 2147483647
#define MINV -2147483647
//typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;
//typedef set<int> si;
typedef map<int, int> msi;
#define f first
#define s second
#define pb push_back
#define p push
#define SIZE 100001;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define IN ({int n; scanf("%d", &n);    n;})
#define CN ({char _char; scanf(" %c",&_char); _char;})
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define FR freopen("/Users/naveen/Desktop/uva/uva/input.txt","r",stdin)
#define FW freopen("/Users/naveen/Desktop/uva/uva/output.txt","w",stdout)
#define NIL -1
#define Set(a, s) memset(a, s, sizeof (a))
vector<int>* factorize(int N){
    
    vector<int>* primes=new vector<int>();
    bool prime[N+1];
    Set(prime, true);
     prime[0]=false;
     prime[1]=false;
    for(int i =2 ; i*i<N; i++)
    {
        if(prime[i]==true)
        {
            for(int j =i*i ; j<N ; j+=i)
            {
                 if(prime[j]==true)
                        prime[j]=false;
            }
        }
    }
    primes->push_back(2);
    for(int i =3 ; i<N ; i++)
    {
    if(prime[i]==true)
        primes->push_back(i);
    }
    return primes;
}

vector<int>* segment_seive( int N)
{
    int  limit=floor(sqrt(N));
    vector<int>* res=new vector<int>();;
    vector<int >* primes=factorize(limit);
    for(int i=0 ; i<primes->size(); i++)
            res->push_back(primes->at(i));
    int low=limit;
    int hight=limit*2;
    while(low<N)
    {
        bool isprime[limit+1];
        Set(isprime, true);
        for(int i=0 ; i<primes->size(); i++)
        {
            int lowestlimit=(low/primes->at(i))*primes->at(i);
            if(lowestlimit<low)
                lowestlimit+=primes->at(i);

            for(int j=lowestlimit ;  j< hight ;  j+=primes->at(i))
            {
                isprime[j-low]=false;
            }
        }
            for(int p=low ; p<hight ; p++)
                if(isprime[p-low])
                    res->push_back(p);
                low+=limit;
            hight+=limit;
            if(hight>=N)
                hight=N;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long  N=2147483649;
    vector<int>* vec=segment_seive(sqrt(N));
//    cout<<"gfd";
//
    REP(i, 0, vec->size())
        cout<<vec->at(i)<<endl;
    cout<<"dfg";
    long long n;
    cin>>n;
//    while(cin>>n)
    {
//        if(n==0)
//            break;
        if(n<0)
        {
            cout<<n<<" = -1 x ";
        }
        else
         {
             cout<<n<<" = ";
         }
        vector<int>arr;
        
        for(int i= 0 ; i<= sqrt(n) ; i++)
        {
            while()
                {
                    arr.push_back(vec->at(i));
                    n/=vec->at(i);
                    cout<<vec->at(i)<<" "<<n<<" "<<vec->at(i)<<endl;
                }
        }
        for(int i= 0 ; i<arr.size(); i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    return 0;
}

