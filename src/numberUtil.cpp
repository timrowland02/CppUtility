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
	
std::size_t numberUtil::concatenate(std::size_t num1, const std::size_t num2) const noexcept // use variadic templates to allow for numerous parameters
{
	num1 *= std::pow(10, length(num2));
    	return num1 + num2;
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
	
std::size_t numberUtil::removeFromBack(std::size_t& num, const short amount) const noexcept // maybe remove reference?
{
	if(amount >= length(num))
		return 0; // returning 0 as if the amount being removed is longer than the number, the whole number should get erased.
	
	for(int x = 0; x < amount; x++)
	{
		num /= 10;
	}
	
	return num;
}
	
std::size_t numberUtil::removeFromFront(std::size_t& num, const short amount) const noexcept // maybe remove reference?, also try to find a way other than reversing twice
	reverse(num);
	
	for(int x = 0; x < amount; x++)
	{
		num /= 10;
	}
	
	return reverse(num);
}

std::size_t numberUtil::reverse(std::size_t& num) const noexcept // maybe remove reference?
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
