#include <iostream>
#include <list>
#include <algorithm>

bool charCompare(char a, char b)
{
    return std::toupper(a) < std::toupper(b);
}

int main()
{
    std::list<char> l;
    for (int i = 0; i < 10; ++i) {
        l.push_back('p' - i);
    }
    for (int i = 0; i < 15; ++i) {
        l.push_back('Z' - i);
    }

    l.sort(charCompare);

    std::list<char>::iterator it = l.begin();
    while(it != l.end()){
        std::cout << *it << " ";
        *it++;
    }

    return 0;
}
