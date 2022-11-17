#include <iostream>
#include <algorithm>

using namespace std;

struct Item
{
    int value, weight;

    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int N)
{

    // Sort objects on basis of value/weight ratio
    sort(arr, arr + N, cmp);

    double finalvalue = 0.0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }

        // If we can't add current Item,
        // add fractional part of it
        else
        {
            finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
        }
    }

    return finalvalue;
}

int main()
{
    int W = 50;
    struct Item arr[] = {{20, 10}, {30, 20}, {50, 30}, {40, 10}, {30, 15}};

    int N = sizeof(arr) / sizeof(arr[0]);
    cout << fractionalKnapsack(W, arr, N);

    return 0;
}