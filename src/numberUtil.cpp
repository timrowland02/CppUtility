#include "numberUtil.h"

namespace cppUtility
{

bool numberUtil::isEven(const std::size_t num) const noexcept
{
	if(num % 2 == 0)
		return true;
	
	return false;
}
	
bool numberUtil::isOdd(const std::size_t num) const noexcept
{
	if(num % 2 == 0)
		return false;
	
	return true;
}

bool numberUtil::isPalindrome(const std::size_t num) const noexcept
{
	if(reverseNum(num) == num)
		return true;
	
	return false;
}
	
bool numberUtil::isPrime(const std::size_t num) const noexcept // THIS IS SLOW AF, IMPLEMENT AN ALGORITHM THAT ISN'T BRUTEFORCE!!!
{
	for(unsigned int x = 2; x < num / 2 + 1; x++)
	{
		if(num % x == 0)
			return false;
	}
	
	return true;
}

std::size_t numberUtil::length(std::size_t num) const noexcept
{
	int x = 0; // needs to be declared outside of for loop as it is being returned (scope would be wrong otherwise)
        
	for(; num > 0; x++)
	{
		num /= 10;
	}
    
	return x;
}

std::size_t numberUtil::reverse(std::size_t num) const noexcept
{
	std::size_t reversed = 0;

	for(unsigned int x = getLength(num); num > 0; x--)
	{
		reversed += num % 10 * std::pow(10, x - 1);
		num /= 10;
	}
	
	return reversed;
}

} // cppUtility namespace
