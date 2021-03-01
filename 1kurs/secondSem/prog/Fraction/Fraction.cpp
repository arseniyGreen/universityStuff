//Arkadskov A.E. KTSO-02-20
#include <iostream>

class Fraction 
{
private:
    int numerator, denominator;

    int findNod(int x, int y) 
    {
        while (x != y) 
        {
            if (x > y) 
            {
                int temp = x;
                x = y;
                y = temp;
            }
            y -= x;
        }
        return x;
    }

    void nullCheck(int denum)
    {
        if (denum == 0) std::cerr << "Denominator can't be equal NULL!" << std::endl;
    }

    void shorten() 
    {
        numerator /= findNod(numerator, denominator);
        denominator /= findNod(numerator, denominator);
    }
    bool isPrime(int num, int denum)
    {
        if(findNod(num, denum) == 1) return true;
        else return false;
    }

public:
    Fraction(int num, int denum) 
    {
        this->numerator = num;
        this->denominator = denum;
    }
    Fraction() : Fraction(0, 1) {}

    Fraction(int num) : Fraction(num, 1) {}

    ~Fraction() {}

    friend Fraction operator*(Fraction F, int n);

    Fraction operator+(Fraction F)
    {
        Fraction res;
        res.numerator = numerator * F.denominator + denominator * F.numerator;
        res.denominator = denominator * F.denominator;

        nullCheck(res.denominator);
        //res.shorten();
        return res;
    }

    Fraction operator-(Fraction F)
    {
        Fraction res;
        res.numerator = numerator * F.denominator - denominator * F.numerator;
        res.denominator = denominator * F.denominator;

        nullCheck(res.denominator);
        //res.shorten();
        return res;
    }

    Fraction operator*(Fraction F)
    {
        Fraction res;
        res.numerator = numerator * F.numerator;
        res.denominator = denominator * F.denominator;

        nullCheck(res.denominator);
        //res.shorten();
        return res;
    }

    Fraction operator/(Fraction F)
    {
        Fraction res;
        res.numerator = numerator * F.denominator;
        res.denominator = denominator * F.numerator;

        nullCheck(res.denominator);
        //res.shorten();
        return res;
    }

    void print() 
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    void setNum(int n)
    {
        numerator = n;
    }
    void setDenum(int n)
    {
        denominator = n;
    }

};

Fraction operator*(Fraction F, int num)
{
    Fraction res;
    res.numerator = F.numerator * num;

    res.shorten();
    return res;
}

Fraction* arrayMult(Fraction* farr, size_t size, int num)
{
    for (int i = 0; i < size; i++)
    {
        farr[i] = farr[i] * num;
    }
    return farr;
};


int main()
{
   Fraction f1, f2;
   Fraction sum, dif, mult, div;
   f1.setNum(8);
   f1.setDenum(16);
   f2.setNum(9);
   f2.setDenum(16);

    sum = f1 + f2;
    dif = f1 - f2;
    mult = f1 * f2;
    div = f1 / f2;

    std::cout << "Results:" << std::endl;
    std::cout << "Sum : "; sum.print(); 
    std::cout << "Dif : "; dif.print();
    std::cout << "Mult : "; mult.print();
    std::cout << "Div : "; div.print();

    return 0;
}