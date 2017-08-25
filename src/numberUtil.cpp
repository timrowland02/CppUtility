#include "numberUtil.h"

namespace cppUtility
{
	
bool numberUtil::isPalindrome(const std::size_t num) const noexcept
{
	if(reverseNum(num) == num)
		return true;
	
	return false;
}

std::size_t numberUtil::getLength(std::size_t num) const noexcept
{
	int x = 0; // needs to be declared outside of for loop as it is being returned (scope would be wrong otherwise)
        
	for(; num > 0; x++)
	{
		num /= 10;
	}
    
	return x;
}

std::size_t numberUtil::reverseNum(std::size_t num) const noexcept
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
