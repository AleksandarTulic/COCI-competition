#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int a;int br1=0,br2=0,br3=0;
int A[10001];
int B[10001];
int C[10001];

int main()
{
    cin>>n;

    for (int i=0;i<n;i++)
    {
        cin>>a;

        if (a%3==0)
        {
            A[br1]=a;
            br1++;
        }
        else if (a%3==1)
        {
            B[br2]=a;
            br2++;
        }
        else
        {
            C[br3]=a;
            br3++;
        }
    }

    if (br1==n || (br1-(br2+br3))>=2 || (br1==0 && br2!=0 && br3!=0)) {cout<<"impossible"<<endl;return 0;} //(br1==0 && br2==br3) ||
    else if (br2==n) for (int i=0;i<n;i++) cout<<B[i]<<" ";
    else if (br3==n) for (int i=0;i<n;i++) cout<<C[i]<<" ";
    else
    {
        if (br1==1 && br2!=0 && br3!=0)
        {
            for (int i=0;i<br2;i++) cout<<B[i]<<" ";
            cout<<A[0]<<" ";
            for (int i=0;i<br3;i++) cout<<C[i]<<" ";
            return 0;
        }
        else if (br1==2 && br2!=0 && br3!=0)
        {
            cout<<A[0]<<" ";
            for (int i=0;i<br2;i++) cout<<B[i]<<" ";
            cout<<A[1]<<" ";
            for (int i=0;i<br3;i++) cout<<C[i]<<" ";
        }
        else if (br1>(br2+br3))
        {
            int prov=false;

            while (n--)
            {
                prov=false;

                if (br1!=0)
                {
                    cout<<A[br1-1]<<" ";
                    br1--;
                }
                if (br2!=0)
                {
                    cout<<B[br2-1]<<" ";
                    br2--;
                    prov=true;
                }
                if (prov==false && br3!=0)
                {
                    cout<<C[br3-1]<<" ";
                    br3--;
                }
            }
        }
        else if (br1==(br2+br3))
        {
            while (br2!=0)
            {
                if (br1!=0)
                {
                    cout<<A[br1-1]<<" ";
                    br1--;
                }
                if (br2!=0)
                {
                    cout<<B[br2-1]<<" ";
                    br2--;
                }
            }
            while (br3!=0)
            {
                if (br1!=0)
                {
                    cout<<A[br1-1]<<" ";
                    br1--;
                }
                if (br3!=0)
                {
                    cout<<C[br3-1]<<" ";
                    br3--;
                }
            }
        }
        else if (br1<(br2+br3))
        {
            if (br2>br1 && br2>br3)
            {
                int rj[br1+br2+br3];

                for (int i=0;i<(br1+br2+br3);i++) rj[i]=-1;

                int bb=br1+br2-1;
                int bbb=br1+br2+br3;

                for (int i=bb;i>=0;i-=2)
                {
                    if (br1!=0)
                    {
                        rj[i]=A[br1-1];
                        br1--;
                    }
                    else break;
                }

                for (int i=bb-1;i>=0;i--)
                {
                    if (rj[i]==-1)
                    {
                        rj[i]=B[br2-1];
                        br2--;
                    }
                }

                for (int i=(bb+1);i<bbb;i++)
                {
                    rj[i]=C[br3-1];
                    br3--;
                }

                for (int i=0;i<bbb;i++) cout<<rj[i]<<" ";
            }
            else if ((br3>br1 && br3>br2)||(br1==br2 && br1==br3))
            {
                int rj[br1+br2+br3];

                for (int i=0;i<(br1+br2+br3);i++) rj[i]=-1;

                int bb=br1+br3-1;
                int bbb=br1+br2+br3;

                for (int i=bb;i>=0;i-=2)
                {
                    if (br1!=0)
                    {
                        rj[i]=A[br1-1];
                        br1--;
                    }
                    else break;
                }

                for (int i=bb-1;i>=0;i--)
                {
                    if (rj[i]==-1)
                    {
                        rj[i]=C[br3-1];
                        br3--;
                    }
                }

                for (int i=(bb+1);i<bbb;i++)
                {
                    rj[i]=B[br2-1];
                    br2--;
                }

                for (int i=0;i<bbb;i++) cout<<rj[i]<<" ";
            }
        }
    }
    return 0;
}
