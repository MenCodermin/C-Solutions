#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

void add_value(map<int,int> &m,int x,int y);
int find_value(map<int,int> &m,int x);
void print_contents(map<int,int> &m);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        map<int,int> m;
        int q;
        cin>>q;
        while(q--)
        {
            char c;
            cin>>c;
            if(c  == 'a')
            {
                int x,y;
                cin>>x>>y;
                add_value(m,x,y);
            }
            if ( c == 'b')
            {
                int y;
                cin>>y;
                cout<<find_value(m,y)<<" ";
            }
            if(c == 'c')
            {
                print_contents(m);
            }
        }
        cout<<endl;
    }
    return 0;
}


void add_value(map<int,int> &m,int x,int y)
{
    m[x] = y;
}

/* Returns the value of the key
 x if present else returns -1 */
int find_value(map<int,int> &m,int x)
{
  return (m.find(x) != m.end()) ? m[x] : -1;

}

/* Prints contents of the map ie keys and values*/
void print_contents(map<int,int> &m)
{
   for(auto its = m.begin(); its != m.end(); ++its)
        cout<<its->first<<" "<<its->second<<" ";
}