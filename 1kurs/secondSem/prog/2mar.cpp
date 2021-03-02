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

    Complex sum(const Complex *nums, size_t count)
    {
    Complex result = 0;
    for(size_t i = 0; i < count; i++)
        result = result + nums[i];
    return result;
    }
};



std::ostream& operator <<(std::ostream &os, const Complex &c){
    return os << c.getReal() << '+' << c.getUnreal() << 'i';
};


int main()
{   
    Complex nums[5]; nums[0] = Complex(1,1); nums[1] = Complex(-2,-2); nums[3] = Complex(-3,3); nums[4] = Complex(4,-4);
    Complex num(1, 2), n1(123), n2, *pn = nums;
    std::cout << "Sum: " << Complex::sum(nums, sizeof(nums)/sizeof(nums[0])) << std::endl;
    std::cin.read(NULL, 1);
    return 0;
