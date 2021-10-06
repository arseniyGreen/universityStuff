#include <iostream>
#include <exception>
#include <string.h>
#include <cstdint>
#include <array> //dlya statich mass

template<class T, bool AUTORESIZE = false, class SIZE = size_t> //shablonni class

class Array
{	//copy
	class ArrayData
	{
	public:
		ArrayData(SIZE size_): size(size_), capacity(size_), refcnt(1) {p = new int[size];}
		~ArrayData() { delete[] p; }
		T *p;
		SIZE size, capacity, refcnt;
		
	};

	ArrayData *d;
public:

	Array(SIZE size_ = 0): d(new ArrayData(size_)){}
	Array(const Array &other): d(other.d){d->refcnt++;}
	~Array() {if(--d->refcnt == 0) delete d;}

	SIZE getSize() const {return d->size;}
	const T *getData() const {return d->p;}
	T *getData() {return d->p;}
	
	T operator[](SIZE idx)const
	{
		if(idx >= d->size)
		{
			if(AUTORESIZE) resize(idx + 1);
			else throw std::invalid_argument("Invalid index!");
		}
		return d->p[idx];
	}

	T& operator[](SIZE idx)
	{
		if(idx >= d->size)
		{
			if(AUTORESIZE) resize(idx + 1);
			else throw std::invalid_argument("Invalid index!");
		}
		return d->p[idx];
	}

	bool getAutoresize() const { return AUTORESIZE; }
	void setAutoresize(bool autoresize_) { AUTORESIZE = autoresize_; }

	void resize(SIZE newSize)
	{
		if(newSize <= d->capacity && d->refcnt == 1 ){d->size = newSize; return;}

		
		if(d->refcnt == 1)
		{
			int *newp = new int[newSize];
			memcpy(newp, d->p, ((newSize < d->size)? newSize : d->size) * sizeof(int));//only not conflict blocks
			delete[] d->p;
			d->p = newp;
			d->capacity = d->size = newSize;
		}
		else
		{
			ArrayData *tmp = new ArrayData(newSize);
			memcpy(tmp->p, d->p, ((newSize < d->size)? newSize : d->size) * sizeof(int));
			d->refcnt--;
			d = tmp;
		}
	}


};

int main(int argc, char* argv[])
{
	char exit;
	/*Array<int> arr(5), *parr = &arr;
	//Array<long, unsigned int> longarr;
	//longarr[5] = 123;
	//std::cout << "Array of long has " << longarr.getSize() << " size\n";
	Array<Array<int>> aa(22);
	aa[2][18] = 52454;
	std::array<long,228> stdarr;// equals to int mas[12]
	try
	{
		arr[6] = 2228; //not const
		std::cout << arr.getSize() << " elements, " << arr[0] << " - f element\n";
	}
	catch (std::invalid_argument ex)
	{
		std::cerr << ex.what() << "\n";
	}
	
	//parr->getData()[0] = 228;
	 */
	Array<int> mas[12];
	return 0;
}