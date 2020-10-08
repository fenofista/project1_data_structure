#include <iostream>
#include "project1.h"
//using namespace std;
int map[20][45];
int n,m;
int main()
{
    cin >> n >> m;
    int place, direction;
    string form;
    while (cin >> form)
    {
        if (form == "End")
        {
            break;
        }
        cin >> place >> direction;
        
        block a(form,place,direction);
        if(place + direction >m || place+direction<=0){
            error();
        }
        a.falling(a);
        a.mov(a);
        a.falling(a);
        then();
        detect_error();
        for (int i = 5; i <= n+4; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << map[i][j];
            }
            cout << '\n';
        }
        cout<<'\n';
    }
    return 0;
}
