//stack
#include <iostream>
#include <cstdlib>

int* sum(int a, int b)
{
    int* result = new int;
    *result = a + b;
    return result; 
}

int* genrandom(size_t count)
{
    int* result = new int[count];
    for(size_t i = 0; i < count; i++)
    {
        result[i] = rand();
    }
    return result;
}

int main()
{
    size_t n1 = 42;
    int* result = genrandom(n1);
    for(size_t i = 0; i < n1; i++)
        std::cout << result[i] << std::endl;
    delete[] result;
    return 0;
}