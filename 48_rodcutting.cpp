#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

typedef long long int ll;
int N;

int recursiveCutRod(vector<int> &ar, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int q = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        q = max(q, ar[i - 1] + recursiveCutRod(ar, n - i));
        // cout<<q<<endl;
    }
    return q;
}
int TopDownCutRod(vector<int> &ar, int n, vector<int> &p)
{
    if (p[n] >= 0)
    {
        return p[n];
    }
    int q = INT_MIN;
    if (n == 0)
    {
        q = 0;
    }
    else
    {

        for (int i = 1; i <= n; i++)
        {
            q = max(q, ar[i - 1] + TopDownCutRod(ar, n - i, p));
            // cout<<q<<endl;
        }
    }
    return p[n] = q;
}
int bottomUpCutRod(vector<int> &ar, int n)
{
    vector<int> p(n + 1, 0);
    for (int j = 1; j <= n; j++)
    {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++)
        {
            q = max(q, ar[i - 1] + p[j - i]);
        }
        p[j] = q;
    }
    return p[n];
}
void generate(vector<int> &v)
{

    srand(time(nullptr));

    for (int i = 1; i <= N; i++)
    {
        int x = rand() % (2 * N + 1);
        v.push_back(x+3);
        // cout<<x<<" ";
    }
    // cout<<endl;
}

int main()
{
    auto st = high_resolution_clock::now();
    auto en = high_resolution_clock::now();
    auto duration = high_resolution_clock::now();
    freopen("output.txt","w",stdout);

    // cout<<"N       recursion(microsec)        Topdown(microsec)     Bottomup(microsecond)\n";
    for (N = 1; N <= 10000; N++)
    {

        vector<int> ar;
        generate(ar);
        int x = 0;
        if (N <= 30)
        {
            st = high_resolution_clock::now();
            x = recursiveCutRod(ar, N);
            en = high_resolution_clock::now();
            // duration
            cout << N << "        ";

            cout << setprecision(15);
            cout << duration_cast<microseconds>(en - st).count() << "                       ";
        }
        else cout<<0<<"                       ";
        vector<int> memo(N + 1, INT_MIN);
        st = high_resolution_clock::now();
        x = TopDownCutRod(ar, N, memo);
        en = high_resolution_clock::now();
        cout << duration_cast<microseconds>(en - st).count() << "                       ";
        st = high_resolution_clock::now();
        x = bottomUpCutRod(ar, N);
        en = high_resolution_clock::now();
        cout << duration_cast<microseconds>(en - st).count() << "                    ";
        cout << endl;
    }

    return 0;
}