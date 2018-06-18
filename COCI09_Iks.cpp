#include <vector>
#include <iostream>

using namespace std;

int n;
int A[101];
int maks_prost=0;
vector <int> prost;

void sieve()
{
    vector <bool> prime(maks_prost,true);

    for (int i=2;i*i<=maks_prost;i++)
        if ( prime[i] ) for (int j=i*2;j<=maks_prost;j+=i) prime[j]=false;

    for (int i=2;i<=maks_prost;i++)
        if ( prime[i] ) prost.push_back(i);
}

int factor(int a, int b)
{
    int br=0;
    int pov=a;
    while (a<=b && b%a==0)
    {
        br++;
        a*=pov;
    }

    return br;
}

int power(int a, int b)
{
    int pov=a;

    for (int i=1;i<b;i++) a*=pov;

    return a;
}

bool najmanji(vector <int> brn, int b)
{
    int najm=brn[0];

    for (int i=1;i<brn.size();i++) najm=min(najm,brn[i]);

    if ( najm == b ) return false;
    else return true;
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>A[i];

        maks_prost=max(maks_prost,A[i]);
    }

    sieve();

    int result=1;
    int br=0;

    for (int j=0;j<prost.size();j++)
    {
        int brf=0;

        vector <int> brn;

        for (int i=0;i<n;i++)
        {
            int p=factor(prost[j],A[i]);

            brn.push_back(p);

            brf+=p;
        }

        while ( najmanji(brn,brf/n) && brf/n>=1)
        {
            int najm=brn[0];
            int najv=brn[0];
            int pozm=0;
            int pozv=0;

            for (int i=0;i<brn.size();i++)
            {
                if ( najm > brn[i] ) najm=brn[i],pozm=i;
                if ( najv < brn[i] ) najv=brn[i],pozv=i;
            }

            brn[pozm]++;
            brn[pozv]--;
            br++;
        }

        if ( brf/n==1 ) result*=prost[j];
        else if ( brf/n > 1 ) result*=power(prost[j],brf/n);
    }

    cout<<result<<" "<<br<<endl;
    return 0;
}
