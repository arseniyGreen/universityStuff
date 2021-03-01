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

    int findNok(int x, int y) 
    {
        return x * y / findNod(x, y);
    }

    void nullCheck(int denum)
    {
        if (denum == 0) std::cerr << "Denominator can't be equal NULL!" << std::endl;
    }

public:
    
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

    //Friend functions section
    
    friend Fraction operator*(Fraction F, int num)
    {
        Fraction result;
        result.numerator = F.numerator * num;
        result.denominator = F.denominator;

        return result;
    }

    void print() 
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }
    void setNumerator(int num)
    {
        numerator = num;
    }
    void setDenominator(int num)
    {
        denominator = num;
    }
};



// Fraction arrayCount(Fraction* array[], size_t arraySize, int number)
// {
//     for(size_t i = 0; i < arraySize; i++)
//     {
//         array[i] *= number;
//     }
//     return *array[arraySize];
// }

int main()
{
    size_t size = 7;
    Fraction* array = new Fraction[size];

    delete[] array;

    Fraction Frac;
    Frac.setDenominator(14);
    Frac.setDenominator(20);

    Frac * 3;

    Frac.print();

    return 0;
}