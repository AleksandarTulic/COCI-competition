#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int r,c;
char m[51][51];
int m1[51][51];
int m2[51][51];

void flood(int x, int y, int korak, int vrsta)
{
    if ( x>=r || x<0 || y>=c || y<0 ) return;
    if ( m[x][y] == 'X' ) return;

    if ( vrsta == 1 )
    {
        if ( korak >= m1[x][y] ) return;

        m1[x][y]=korak;
    }
    else if ( vrsta == 2 )
    {
        if ( korak >= m2[x][y] ) return;
        if ( m[x][y] == 'D' ) return;

        m2[x][y]=korak;
    }

    flood(x+1,y,korak+1,vrsta);
    flood(x-1,y,korak+1,vrsta);
    flood(x,y+1,korak+1,vrsta);
    flood(x,y-1,korak+1,vrsta);
}

int main()
{
    cin>>r>>c;

    int x1,y1,x2,y2;

    vector <pair<int, int> > ko;

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        {
            cin>>m[i][j];

            if ( m[i][j] == '*' ) ko.push_back({i,j});
            else if ( m[i][j] == 'S' ) { x1=i;y1=j; }
            else if ( m[i][j] == 'D' ) { x2=i;y2=j; }

            m1[i][j]=m2[i][j]=2000000;
        }

    flood(x1,y1,0,1);

    if ( m1[x2][y2] ==  2000000 ) { cout<<"KAKTUS"<<endl;return 0; }

    for (int i=0;i<ko.size();i++)
        flood(ko[i].first,ko[i].second,0,2);

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            if ( m2[i][j] <= m1[i][j] ) m[i][j]='X';

    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++) m1[i][j]=2000000;

    flood(x1,y1,0,1);

    if ( m1[x2][y2] ==  2000000 ) cout<<"KAKTUS"<<endl;
    else cout<<m1[x2][y2]<<endl;
    return 0;
}
