#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int r,c;
char m[101][101];

int strana(int poz1, int poz2, int vrsta)
{
    int br1=0;
    int br2=0;

    if (vrsta==1)
    {
        for (int i=poz1;i<r;i++)
           if (m[i][poz2]=='x') br1++;
           else break;
        for (int i=poz2;i<c;i++)
           if (m[poz1][i]=='x') br2++;
           else break;
    }
    else
    {
        for (int i=poz1;i>=0;i--)
           if (m[i][poz2]=='x') br1++;
           else break;
        for (int i=poz2;i>=0;i--)
           if (m[poz1][i]=='x') br2++;
           else break;
    }

    return min(br1,br2);
}

int main()
{
    cin>>r>>c;

    int br=0;

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        {
            cin>>m[i][j];

            if (m[i][j]=='x') br++;
        }
    if (br==r*c)
    {
        cout<<1<<" "<<1<<" "<<min(r,c)<<endl;
        cout<<1<<" "<<1<<" "<<1<<endl;
        return 0;
    }

    vector <pair<pair<int, int>, int> > sq;

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            if ( m[i][j]=='x' && m[i-1][j]!='x' && m[i][j-1]!='x' )
                sq.push_back(make_pair(make_pair(i,j),strana(i,j,1)));

    for (int i=r-1;i>=0;i--)
        for (int j=c-1;j>=0;j--)
            if ( m[i][j]=='x' && m[i+1][j]!='x' && m[i][j+1]!='x' )
            {
                int x=i;
                int y=j;
                int str=strana(x,y,2);

                x=x-(str-1);
                y=y-(str-1);

                bool prov=true;
                for (int q=0;q<sq.size();q++)
                    if ( sq[q].first.first==x && sq[q].first.second==y ) {prov=false;break;}

                if (prov) sq.push_back(make_pair(make_pair(x,y),str));
            }

    for (int i=0;i<sq.size();i++)
        cout<<sq[i].first.first+1<<" "<<sq[i].first.second+1<<" "<<sq[i].second<<endl;
    return 0;
}
