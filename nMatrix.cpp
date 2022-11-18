#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
{
    // Read/write n value.
    int n = 0;
    cin >> n;
    cout << n << endl;

    // Adjacency matrix.
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < n; e++)
        {
            if (e == n-1)
            {
                if( e == i)
                {
                    cout << 0;
                } else
                {
                    cout << rand()%50;
                }
            } else if ( i == e)
            {
                cout << 0 << " ";
            } else 
            {
                cout << rand()%50 << " ";    
            }
        }
        cout << endl;
    }
    // Max flux.
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < n; e++)
        {
            if (e == n-1)
            {
                if( e == i)
                {
                    cout << 0;
                } else
                {
                    cout << rand()%100 + rand()%100;
                }
            } else if ( i == e)
            {
                cout << 0 << " ";
            } else 
            {
                cout << rand()%100 + rand()%100 << " ";
            }
        }
        cout << endl;
    }
    // Centrales
    // Maybe implement and array?
    for (int i = 0; i < n; i++)
    {
        cout << "(" << rand()%1000 << "," << rand()%1000 << ")" << endl;
    }
    return 0;
}