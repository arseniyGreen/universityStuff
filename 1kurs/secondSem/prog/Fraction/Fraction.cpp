//Arkadskov A.E. KTSO-02-20
#include <iostream>

class Fraction 
{
private:
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

    int findNok(int x, int y) 
    {
        return x * y / findNod(x, y);
    }

    void nullCheck(int denum)
    {
        if (denum == 0) std::cerr << "Denominator can't be equal NULL!" << std::endl;
    }

public:
    int numerator, denominator;

    Fraction operator+ (Fraction& F)
    {
        nullCheck(this->denominator);
        nullCheck(F.denominator);

        Fraction result;
        if (this->denominator == F.denominator) //denominator check
        {
            result.numerator = this->numerator + F.numerator;
            result.denominator = this->denominator;
        }
        else 
        {
            int nok = findNok(this->denominator, F.denominator); //find nok for denums
            int mult1, mult2;
            mult1 = nok / this->denominator;
            mult2 = nok / F.denominator;

            result.numerator = this->numerator * mult1 + F.numerator * mult2;
            result.denominator = nok;
        }
        int resNod = findNod(result.numerator, result.denominator);
    
        result.numerator /= resNod;
        result.denominator /= resNod;
        return result;

    }

    Fraction operator- (Fraction& F)
    {
        nullCheck(this->denominator);
        nullCheck(F.denominator);

        Fraction result;
        if (this->denominator == F.denominator) //denominator check
        {
            result.numerator = this->numerator - F.numerator;
            result.denominator = this->denominator;
        }
        else
        {
            int nok = findNok(this->denominator, F.denominator); //find nok for denums
            int mult1, mult2;
            mult1 = nok / this->denominator;
            mult2 = nok / F.denominator;

            result.numerator = this->numerator * mult1 - F.numerator * mult2;
            result.denominator = nok;
        }
        int resNod = findNod(result.numerator, result.denominator);

        result.numerator /= resNod;
        result.denominator /= resNod;
        return result;
    }

    Fraction operator* (Fraction& F) 
    {
        nullCheck(this->denominator);
        nullCheck(F.denominator);

        Fraction result;
        result.numerator = this->numerator * F.numerator;
        result.denominator = this->denominator * F.denominator;

        int resNod = findNod(result.numerator, result.denominator);

        result.numerator /= resNod;
        result.denominator /= resNod;
        return result;

    }

    Fraction operator/ (Fraction& F)
    {
        nullCheck(this->denominator);
        nullCheck(F.denominator);

        Fraction result;
        result.numerator = this->numerator * F.denominator;
        result.denominator = this->denominator * F.numerator;

        int resNod = findNod(result.numerator, result.denominator);
  
        result.numerator /= resNod;
        result.denominator /= resNod;
        return result;

    }

    void print() 
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }

};

int main()
{
   Fraction f1, f2;
   Fraction sum, dif, mult, div;
   f1.numerator = 8;
   f1.denominator = 16;
   f2.numerator = 9;
   f2.denominator = 81;


    sum = f1 + f2;
    dif = f1 - f2;
    mult = f1 * f2;
    div = f1 / f2;

    std::cout << "Results:" << std::endl;
    std::cout << "Sum : "; sum.print(); 
    std::cout << "Dif : "; dif.print();
    std::cout << "Mult : "; mult.print();
    std::cout << "Div : "; div.print();
}
