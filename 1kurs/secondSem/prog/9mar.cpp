//Arrays
#include <iostream>
#include <cstdlib>

class Array
{
private:
    int *p;
    size_t size;
public:
    Array(size_t size_ = 0) : size(size_) { p = new int[size]; }
    ~Array(){ delete[] p; }
    size_t getSize() const { return size; }
    const int *getData() const { return p; }
    int *getData() { return p; }
};

int main()
{
    Array myArray(12);

    myArray.getData()[0] = 42;
    std::cout << "Array has " << myArray.getSize() << " elements, first one is " << myArray.getData()[0] << std::endl;
    
    return 0;
}