#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
//97 ascii code
int main()
{
    int n;

    cin>>n;

    string naziv;

    int A[26];

    for (int i=0;i<26;i++) A[i]=0;

    while (n--)
    {
        cin>>naziv;

        for (int i=0;i<26;i++)
        {
            char e=i+97;

            if (e==naziv[0])
            {
                A[i]+=1;
                break;
            }
        }
    }

    bool flag=true;

    for (int i=0;i<26;i++)
    {
        if (A[i]>=5)
        {
            flag=false;

            char e=i+97;

            cout<<e;
        }
    }

    if (flag==true) cout<<"PREDAJA"<<endl;
    return 0;
}
