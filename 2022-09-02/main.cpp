#include <iostream>
#include <cmath>

int num_digits(int n);
bool isprime(int n);


int main()
{
    // int n;
    // std::cin >> n;
    // std::cout << num_digits(n) << '\n';

    for (int i = 1; i < 100; ++i)
    {
        std::cout << i << ' ' << isprime(i) << '\n';
    }
    return 0;
}


int num_digits(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int count = 0;
        while (n != 0)
        {
            int digit = n % 10;
            n /= 10;
            ++count;
            std::cout << digit << ' ' << count << '\n';
        }
        return count;
    }
}

bool isprime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    else
    {
        for (int d = 2; d <= sqrt(n); ++d)
        {
            if (n % d == 0)
            {
                return false;
            }
        }
        return true;
    }
}
