#include <array> 
 #include <exception> 
 #include <iostream> 
 #include <cstdint> 
 #include <string.h> 

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
 	Array(const Array<T, AUTORESIZE, SIZE> &other) : d(other.d) { 
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
 	Array2(const Array2<T, SIZE> &other) : d(other.d) { 
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
 	Array2AutoResize(SIZE size_ = 0) : Array2<T, SIZE>(size_) {  } 
 	Array2AutoResize(const Array2AutoResize<T, SIZE> &other) : Array2<T, SIZE>(other) { } 
  
 	virtual T operator[](SIZE idx) const { 
 		if (idx >= this->d->size) 
 			const_cast<Array2AutoResize<T, SIZE>*>(this)->resize(idx + 1); 
 		return this->d->p[idx]; 
 	} 
 	virtual T& operator[](SIZE idx) { 
 		if (idx >= this->d->size) 
 			this->resize(idx + 1); 
 		return this->d->p[idx]; 
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
 	Array3(const Array3<T, SIZE> &other) : d(other.d), autoresize(other.autoresize) { 
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
 class Matrix { 
 public: 
 	class Row { 
 		T *p; 
 		size_t size; 
  
 		Row(T *p_, size_t size_) : size(size_), p(p_) { } 
 		friend Matrix<T>; 
  
 	public: 
 		size_t getSize() const { return size; } 
 		T operator[](int col) const { return p[col]; } 
 		T& operator[](int col) { return p[col]; } 
 	}; 
  
 private: 
 	T *data; 
 	size_t nrows, ncols; 
  
 public: 
 	Matrix(size_t nrows_, size_t ncols_) : nrows(nrows_), ncols(ncols_) 
	{	
		if(nrows == 0 || ncols == 0)
			throw std::invalid_argument("Creation of zero-sized matrix is prohibited");

		data = new T[nrows_ * ncols_];

	} 
 	Matrix(const Matrix<T> &other) : data(new T[other.nrows * other.ncols]), nrows(other.nrows), ncols(other.ncols) 
 	{ for (size_t i = 0; i < nrows * ncols; i++) data[i] = other.data[i]; } 
 	~Matrix() { delete[] data; } 
  
 	size_t rowCount() const { return nrows; } 
 	size_t columnCount() const { return ncols; } 
  
 	// [ 1, 2, 3, 4, 10, 20, 30, 40, 100, 200, 300, 400 ]
 	const Row operator[](int row) const { return Row(data + (row * ncols), ncols); } 
 	Row operator[](int row) { return Row(data + (row * ncols), ncols); } 
  
 	Matrix<T> transponded() const { 
 		 //Result = dist, *this = src
 	    Matrix<T> Result(ncols, nrows); 
        for (size_t i = 0; i < ncols; i++)
            for (size_t j = 0; j < nrows; j++)
                Result[i][j] = (*this)[j][i]; //data[Row(data + (j * ncols), ncols)];
                
 	    return Result;
 	}
 }; 
  
 template<typename T> 
 std::ostream& operator <<(std::ostream& os, Matrix<T> matrix) { 
 	for (size_t row = 0; row < matrix.rowCount(); row++) { 
 		for (size_t col = 0; col < matrix.columnCount(); col++) 
 			os << matrix[row][col] << '\t'; 
 		os << std::endl; 
 	} 
 	return os; 
 } 
  
 // https://clck.ru/TsNVM 
  
 int main(int argc, char* argv[]) 
 { 
 	try { 
 		Matrix<int> matrix(2, 3); 
 		matrix[0][0] = 1; 
 		matrix[0][1] = 2; 
 		matrix[0][2] = 3; 
 		matrix[1][0] = 4; 
 		matrix[1][1] = 5; 
 		matrix[1][2] = 6; 
 		std::cout << "Source:" << std::endl << matrix << std::endl; 
 		Matrix<int> t = matrix.transponded(); 
 		std::cout << "Transponded:" << std::endl << t << std::endl; 
 	} 
 	catch (std::invalid_argument ex) { 
 		std::cerr << ex.what() << std::endl; 
 	}
 	return 0; 
 } 
