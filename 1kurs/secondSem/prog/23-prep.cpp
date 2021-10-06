#include <array>
#include <exception>
#include <iostream>
#include <cstdint>
#include <string.h>

// AUTORESIZE как...
// 1. Параметр шаблона
// 2. Изменение поведения при наследовании
// 3. Переменная в самом классе Array

// AUTORESIZE == true  ->  при обращении за пределами size() дополнительное место выделяется
// AUTORESIZE == false ->  при обращении за пределами size() кидается исключение
template<class T, bool AUTORESIZE = false, class SIZE = size_t>
class Array {
	class ArrayData {
	public:
		ArrayData(SIZE size_) : size(size_), capacity(size_), refcnt(1) { p = new T[size]; }
		~ArrayData() { delete[] p; }

		T *p;
		SIZE size, capacity, refcnt;
	};
	ArrayData *d;

public:
	Array(SIZE size_ = 0) : d(new ArrayData(size_)) {  }
	Array(const Array &other) : d(other.d) {
		d->refcnt++;
	}
	~Array() {
		d->refcnt -= 1;
		if (d->refcnt == 0)
			delete d;
	}

	SIZE getSize() const { return d->size; }
	const T *getData() const { return d->p; }
	T *getData() { return d->p; }
	T operator[](SIZE idx) const {
		if (idx >= d->size) {
			if (AUTORESIZE)
				resize(idx + 1);
			else
				throw std::invalid_argument("invalid index");
		}
		return d->p[idx];
	}
	T& operator[](SIZE idx) {
		if (idx >= d->size) {
			if (AUTORESIZE)
				resize(idx + 1);
			else
				throw std::invalid_argument("invalid index");
		}
		return d->p[idx];
	}

	void resize(SIZE newSize) {
		if (newSize <= d->capacity && d->refcnt == 1) {
			d->size = newSize;
			return;
		}
		if (d->refcnt == 1) {
			T *newp = new T[newSize];
			memcpy(newp, d->p, ((newSize < d->size) ? newSize : d->size) * sizeof(T));
			delete[] d->p;
			d->p = newp;
			d->capacity = d->size = newSize;
		} else {
			ArrayData *tmp = new ArrayData(newSize);
			memcpy(tmp->p, d->p, ((newSize < d->size) ? newSize : d->size) * sizeof(T));
			d->refcnt--;
			d = tmp;
		}
	}
};



template<class T, class SIZE = size_t>
class Array2 {
protected:
	class ArrayData {
	public:
		ArrayData(SIZE size_) : size(size_), capacity(size_), refcnt(1) { p = new T[size]; }
		~ArrayData() { delete[] p; }

		T *p;
		SIZE size, capacity, refcnt;
	};
	ArrayData *d;

public:
	Array2(SIZE size_ = 0) : d(new ArrayData(size_)) {  }
	Array2(const Array2 &other) : d(other.d) {
		d->refcnt++;
	}
	~Array2() {
		d->refcnt -= 1;
		if (d->refcnt == 0)
			delete d;
	}

	SIZE getSize() const { return d->size; }
	const T *getData() const { return d->p; }
	T *getData() { return d->p; }
	virtual T operator[](SIZE idx) const {
		if (idx >= d->size)
			throw std::invalid_argument("invalid index");
		return d->p[idx];
	}
	virtual T& operator[](SIZE idx) {
		if (idx >= d->size)
			throw std::invalid_argument("invalid index");
		return d->p[idx];
	}

	void resize(SIZE newSize) {
		if (newSize <= d->capacity && d->refcnt == 1) {
			d->size = newSize;
			return;
		}
		if (d->refcnt == 1) {
			T *newp = new T[newSize];
			memcpy(newp, d->p, ((newSize < d->size) ? newSize : d->size) * sizeof(T));
			delete[] d->p;
			d->p = newp;
			d->capacity = d->size = newSize;
		} else {
			ArrayData *tmp = new ArrayData(newSize);
			memcpy(tmp->p, d->p, ((newSize < d->size) ? newSize : d->size) * sizeof(T));
			d->refcnt--;
			d = tmp;
		}
	}
};

template<class T, class SIZE = size_t>
class Array2AutoResize : public Array2<T, SIZE> {
public:
	Array2AutoResize(SIZE size_ = 0) : Array2(size_) {  }
	Array2AutoResize(const Array2AutoResize &other) : Array2(other) { }

	virtual T operator[](SIZE idx) const {
		if (idx >= d->size)
			const_cast<Array2AutoResize<T, SIZE>*>(this)->resize(idx + 1);
		return d->p[idx];
	}
	virtual T& operator[](SIZE idx) {
		if (idx >= d->size)
			resize(idx + 1);
		return d->p[idx];
	}
};



template<class T, class SIZE = size_t>
class Array3 {
	class ArrayData {
	public:
		ArrayData(SIZE size_) : size(size_), capacity(size_), refcnt(1) { p = new T[size]; }
		~ArrayData() { delete[] p; }

		T *p;
		SIZE size, capacity, refcnt;
	};
	ArrayData *d;
	bool autoresize;

public:
	Array3(SIZE size_ = 0, bool autoresize_ = false) : d(new ArrayData(size_)), autoresize(autoresize_) {  }
	Array3(const Array3 &other) : d(other.d), autoresize(other.autoresize) {
		d->refcnt++;
	}
	~Array3() {
		d->refcnt -= 1;
		if (d->refcnt == 0)
			delete d;
	}

	SIZE getSize() const { return d->size; }
	const T *getData() const { return d->p; }
	T *getData() { return d->p; }

	bool getAutoresize() const { return autoresize; }
	void setAutoresize(bool newAutoresize = true) { autoresize = newAutoresize; }

	T operator[](SIZE idx) const {
		if (idx >= d->size) {
			if (autoresize)
				resize(idx + 1);
			else
				throw std::invalid_argument("invalid index");
		}
		return d->p[idx];
	}
	T& operator[](SIZE idx) {
		if (idx >= d->size) {
			if (autoresize)
				resize(idx + 1);
			else
				throw std::invalid_argument("invalid index");
		}
		return d->p[idx];
	}

	void resize(SIZE newSize) {
		if (newSize <= d->capacity && d->refcnt == 1) {
			d->size = newSize;
			return;
		}
		if (d->refcnt == 1) {
			T *newp = new T[newSize];
			memcpy(newp, d->p, ((newSize < d->size) ? newSize : d->size) * sizeof(T));
			delete[] d->p;
			d->p = newp;
			d->capacity = d->size = newSize;
		} else {
			ArrayData *tmp = new ArrayData(newSize);
			memcpy(tmp->p, d->p, ((newSize < d->size) ? newSize : d->size) * sizeof(T));
			d->refcnt--;
			d = tmp;
		}
	}
};

template<typename T>
class Matrix
{
public:
	Matrix(size_t nrows, size_t ncols) {	}
	~Matrix() { 	}

	size_t rows() const { 	}
	size_t cols() const {	}

	Array<T> operator[](int row) const{ 	}
	Array<T>& operator[](int row) { 	}
	Matrix<T> transponded() const { 	}
};


int main(int argc, char* argv[])
{
	try {
		Array2AutoResize<int> arr;
		Array2<int> &arrref = arr;
		arrref[3] = 123;
		std::cout << "size: " << arr.getSize() << std::endl;
	}
	catch (std::invalid_argument ex) {
		std::cerr << ex.what() << std::endl;
	}
	{ char ch; std::cin >> ch; }
	return 0;
}
