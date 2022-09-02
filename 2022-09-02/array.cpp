// Exercise. write max_index to return index where max occurs
// Exercise. write min and min_index.

#include <iostream>
#include <ctime>
#include <cstdlib>


void randarray(int x[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        x[i] = rand() % 20;
    }
}


void print(int x[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << x[i] << ' ';
    }
    std::cout << '\n';
}


int max(int x[], int n)
{
    int m = x[0];
    for (int i = 1; i < n; ++i)
    {
        if (x[i] > m)
        {
            m = x[i];
        }
    }
    return m;
}


int linearsearch(int x[], int n, int target)
{
    for (int i = 0; i < n; ++i)
    {
        if (x[i] == target)
        {
            return i;
        }
    }
    return -1;
}


void bubblesort(int x[], int n)
{
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (x[j] > x[j + 1])
            {
                int t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
            std::cout << "bubblesorting ... "; print(x, n);
        }
    }
}

int binarysearch(int x[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (x[mid] == target)
        {
            return mid;
        }
        else if (x[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    srand((unsigned int) time(NULL));
    const int N = 1024;
    int x[N];
    randarray(x, 10);
    print(x, 10);

    std::cout << max(x, 1) << '\n';
    std::cout << max(x, 5) << '\n';
    std::cout << max(x, 10) << '\n';

    int target;
    std::cin >> target;
    std::cout << linearsearch(x, 1, target)  << '\n';
    std::cout << linearsearch(x, 5, target)  << '\n';
    std::cout << linearsearch(x, 10, target) << '\n';

    bubblesort(x, 1);
    print(x, 10);
    bubblesort(x, 5);
    print(x, 10);
    bubblesort(x, 10);
    print(x, 10);

    for (int target = 0; target < 10; ++target)
    {
        std::cout << target << ' ' << binarysearch(x, 5, target) << '\n';
    }
    
    return 0;
}
