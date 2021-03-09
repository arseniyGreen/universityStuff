//Arrays
#include <iostream>
#include <cstring>
#include <ctime>

class Array
{
    class ArrayData
    {
    public:
        ArrayData(size_t size_) : size(size_), capacity(size_), refcnt(1) { p = new int[size]; }
        ~ArrayData() { delete[] p; }

        int *p;
        size_t size, capacity, refcnt;
    };
    ArrayData *d;
public:
    Array(size_t size_ = 0) : d(new ArrayData(size_)) { }
    Array(const Array &other) : d(other.d)
    {
        d->refcnt++;
    } 
    ~Array()
    {
        if(--d->refcnt == 0)
            delete d;
    }

    size_t getSize() const { return d->size; }

    const int *getData() const { return d->p; }

    int *getData() { return d->p; }

    int operator[](size_t idx) const
    {
        if(idx >= d->size) throw std::runtime_error("Invalid index");
        return d->p[idx];
    }

    int& operator[](size_t idx)
    {
        if(idx >= d->size) resize(idx + 1);
        return d->p[idx];
    }

    void resize(size_t newSize)
    {
        if(newSize <= d->capacity && d->refcnt == 1) //only one Array connected to ArrayData
        {
            d->size = newSize;
            return;
        }
        if(d->refcnt == 1) 
        {
            int *newp = new int[newSize];
            std::memcpy(newp, d->p, ((newSize < d->size) ? newSize : d->size) * sizeof(int));
            delete[] d->p;
            d->p = newp;
            d->capacity = d->size = newSize;
        }
        else //someone else connected to ArrayData
        {
            ArrayData *tmp = new ArrayData(newSize);
            std::memcpy(tmp->p, d->p, ((newSize < d->size) ? newSize : d->size) * sizeof(int));
            d->refcnt--;
            d = tmp;
        }
    }

};

int main()
{
    srand(time(NULL));
    Array myArray(12);
    //std::cout << "Array has " << myArray.getSize() << " elements, first one is " << myArray[0] << std::endl;
    myArray.resize(25);
    try
    {
        myArray[30] = 42;
    }
    catch(std::runtime_error ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << myArray[30] << std::endl;
    std::cout << myArray.getSize() << std::endl;
    return 0;
}