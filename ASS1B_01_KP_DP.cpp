#include <iostream>
#include <algorithm>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int w[], int v[], int N)
{

    // base case
    if (N == 0 || W == 0)
    {
        return 0;
    }

    if (w[N - 1] > W) // cannot be included in optimal solution
    {
        return knapsack(W, w, v, N - 1);
    }

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
    {
        return max(v[N - 1] + knapsack(W - w[N - 1], w, v, N - 1), knapsack(W, w, v, N - 1));
    }
}

int main()
{
    int W = 50;
    int w[] = {30, 50, 20, 40};
    int v[] = {40, 70, 30, 60};

    int N = sizeof(w) / sizeof(w[0]);

    cout << knapsack(W, w, v, N);
    return 0;
}
