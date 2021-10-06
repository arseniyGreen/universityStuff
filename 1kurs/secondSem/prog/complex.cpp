//Arkadskov A.E. KTSO-02-20
#include <iostream>
#include <cmath>

class Complex
{
private:
    double real, unreal;

public:
    Complex() : real(1), unreal(1) {};
    Complex(const Complex &c) : real(c.real), unreal(c.unreal) {};
    Complex(double real_, double unreal_) : real(real_), unreal(unreal_) {};

    double getReal() const { return real; }
    double getUnreal() const { return unreal; }
    Complex getConjugate() const{ return Complex(real, -unreal); } //сопряжённое

    Complex operator+(const Complex &other) { return Complex(real + other.real, unreal + other.unreal); }

    Complex operator-(const Complex &other) { return Complex(real - other.real, unreal - other.unreal); }

    Complex operator*(const Complex &other) { return Complex(real * other.real - unreal * other.unreal, real * other.unreal + unreal * other.real); }

    Complex operator/(const Complex &other) { return Complex((real * other.real + unreal * other.unreal)/(pow(other.real, 2) + pow(other.unreal, 2)), (other.real * unreal - real * other.unreal)/(pow(other.real, 2) + pow(other.unreal, 2))); }

};

std::ostream& operator <<(std::ostream &out, const Complex &c){
    double real = c.getReal(), unreal = c.getUnreal();

    if(unreal >= 0) return out << real << " + " << unreal << "i";
    else return out << real << " - " << -unreal << "i";
};

Complex arraySum(Complex* cArray, size_t size)
{
    Complex result;
    for(int i = 0; i < size; ++i)
    {
        result = result + cArray[i];
    }
    return result;
};

Complex arrayDif(Complex* cArray, size_t size)
{
    Complex result;
    for(int i = 0; i < size; ++i)
    {
        result = result - cArray[i];
    }
    return result;
};

Complex arrayMul(Complex* cArray, size_t size)
{
    Complex result;
    for(int i = 0; i < size; ++i)
    {
        result = result * cArray[i];
    }
    return result;
};

Complex arrayDiv(Complex* cArray, size_t size)
{
    Complex result;
    for(int i = 0; i < size; ++i)
    {
        result = result / cArray[i];
    }
    return result;
};

int main()
{   
    Complex c1(12, 24), c2(-7, 42), c3(37, 25);
    Complex sum = c1 + c2;
    Complex dif = c1 - c2;
    Complex mul = c1 * c2;
    Complex div = c1 / c2;

    std::cout << "\tResults : " << std::endl;
    std::cout << "Sum : " << sum << std::endl;
    std::cout << "Dif : " << dif << std::endl;
    std::cout << "Mul : " << mul << std::endl;
    std::cout << "Div : " << div << std::endl;

    //Arrays task

    std::cout << "\tArrays task : " << std::endl;
    Complex* cArray = new Complex[3];
    Complex arrRes;
    cArray[0] = c1;
    cArray[1] = c2;
    cArray[2] = c3;
    
    arrRes = arraySum(cArray, 3);
    std::cout << "Sum : " << arrRes << std::endl;

    arrRes = arrayDif(cArray, 3);
    std::cout << "Dif : " << arrRes << std::endl;

    arrRes = arrayMul(cArray, 3);
    std::cout << "Mul : " << arrRes << std::endl;

    arrRes = arrayDiv(cArray, 3);
    std::cout << "Div : " << arrRes << std::endl;

    delete[] cArray;
    return 0;
}