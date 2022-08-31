#include <iostream>

void draw_line(int n, char even_char='*', char odd_char='@');


int main()
{
    int n;
    std::cin >> n;
    draw_line(n);
    draw_line(n, '@', '#');
    
    return 0;
}


void draw_line(int n, char even_char, char odd_char)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << (i % 2 == 0 ? even_char : odd_char); 
    }
    std::cout << '\n';
    return;
}
