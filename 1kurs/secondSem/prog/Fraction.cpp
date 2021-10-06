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

    void signChange() 
    {
        if (numerator < 0) numerator = -numerator;
        if (denominator < 0) denominator = -denominator;
    }

    void shorten()
    {
        if (findNod(numerator, denominator) != 1)
        {
            int nod = findNod(numerator, denominator);
            numerator /= nod;
            denominator /= nod;
        }
    }

    void fractionChange()
    {
        signChange();
        shorten();
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
        res.fractionChange();
        return res;
    }

    Fraction operator-(Fraction F)
    {
        Fraction res;
        res.numerator = numerator * F.denominator - denominator * F.numerator;
        res.denominator = denominator * F.denominator;

        nullCheck(res.denominator);
        res.fractionChange();
        return res;
    }

    Fraction operator*(Fraction F)
    {
        Fraction res;
        res.numerator = numerator * F.numerator;
        res.denominator = denominator * F.denominator;

        nullCheck(res.denominator);
        res.fractionChange();
        return res;
    }

    Fraction operator/(Fraction F)
    {
        Fraction res;
        res.numerator = numerator * F.denominator;
        res.denominator = denominator * F.numerator;

        nullCheck(res.denominator);
        res.fractionChange();
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
    res.denominator = F.denominator;

    res.fractionChange();
    return res;
}

Fraction* arrayMult(Fraction* farr, size_t size, int num)
{
    for (int i = 0; i < size; i++)
    {
        farr[i] = farr[i] * num;
        farr[i].print();
    }
    return farr;
};


int main()
{
    Fraction f1, f2, f3;
    Fraction sum, dif, mult, div;
    f1.setNum(8);
    f1.setDenum(16);
    f2.setNum(9);
    f2.setDenum(16);

    sum = f1 + f2;
    dif = f1 - f2;
    mult = f1 * f2;
    div = f1 / f2;

    std::cout << '\t' << "First task" << std::endl;
    std::cout << "Results:" << std::endl;
    std::cout << "Sum : "; sum.print();
    std::cout << "Dif : "; dif.print();
    std::cout << "Mult : "; mult.print();
    std::cout << "Div : "; div.print();

    //Array task
    std::cout << "\t" << "Array task" << std::endl;

    f3.setNum(6);
    f3.setDenum(17);

    Fraction* fracArray = new Fraction[3];
    fracArray[0] = f1;
    fracArray[1] = f2;
    fracArray[2] = f3;

    arrayMult(fracArray, 3, 4);

    delete[] fracArray;
    return 0;
}