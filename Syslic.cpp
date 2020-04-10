#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

struct suslic
{
    int weight = rand() % 100 + 80;
    int h = rand() % 10 + 10;
};

void sortH(vector<suslic> &vec, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (vec[j].h > vec[j + 1].h)
                swap(vec[j], vec[j + 1]);
}

void sortWeight(vector<suslic>& vec, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (vec[j].weight > vec[j + 1].weight)
                swap(vec[j], vec[j + 1]);
}

double averageWeight(vector<suslic>& vec, int n)
{
    double average = vec[0].weight;
    for (int i = 1; i < n; i++)
    {
        average += vec[i].weight;
    }
    return average / n;
}

void swap_BW_LW(vector<suslic>& vec, int n)
{
    int max = vec[0].weight, min = vec[0].weight, maxi = 0, mini = 0;
    for (int i = 1; i < n; i++)
    {
        if (vec[i].weight > max)
        {
            max = vec[i].weight;
            maxi = i;
        }
        if (vec[i].weight < min)
        {
            min = vec[i].weight;
            mini = i;
        }
        
    }
    swap(vec[maxi], vec[mini]);
}

int main()
{

    int n = 8;
    vector<suslic> vec(n);
    sortWeight(vec, n);
    swap_BW_LW(vec, n);
    for (int i = 0; i < n; i++)
    {
        cout << vec[i].weight << ' ';
    }
}