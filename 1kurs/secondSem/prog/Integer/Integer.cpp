//Arkadskov A.E. KTSO-02-20
#include <iostream>

class Integer 
{
public:
	int value;

	const Integer operator+(const Integer& secInt) 
	{
		Integer result;
		result.value = this->value + secInt.value;
		return result;
	}
	const Integer operator-(const Integer& secInt)
	{
		Integer result;
		result.value = this->value - secInt.value;
		return result;
	}
	const Integer operator*(const Integer& secInt)
	{
		Integer result;
		result.value = this->value * secInt.value;
		return result;
	}
	const Integer operator/(const Integer& secInt)
	{
		if(secInt.value == 0)
		{
			std::cerr << "ERROR! Second integer can't be equal NULL while division!" << std::endl;
		}
		else
		{
		Integer result;
		result.value = this->value / secInt.value;
		return result;
		}
	}

};

int main() 
{
	Integer first, second;
	first.value = 15;
	second.value = 0;

	Integer ans;

	std::cout << "Results: " << std::endl;
	
	ans = first + second;
	std::cout << "Sum : " << ans.value << std::endl;

	ans = first - second;
	std::cout << "Dif : " << ans.value << std::endl;

	ans = first * second;
	std::cout << "Mult : " << ans.value << std::endl;

	ans = first / second;
	std::cout << "Div : " << ans.value << std::endl;

	return 0;
}