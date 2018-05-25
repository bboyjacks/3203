#include "Functions.h"

bool Functions::isValid(long long number)
{
  unsigned int numSize = getSize(number);

  if (numSize > 16 || numSize < 13)
    return false;

  unsigned int sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
  
  if (sum % 10 != 0)
    return false;

  if (prefixMatched(number, 4))
    return true;

  if (prefixMatched(number, 5))
    return true;

  if (prefixMatched(number, 37))
    return true;

  if (prefixMatched(number, 6))
    return true;

  return false;
}

long long Functions::sumOfDoubleEvenPlace(long long number)
{
  unsigned int sum = 0;

  while (number > 0)
  {
    unsigned int digit = (int)((number % 100) / 10);
    number /= 100;
    sum += getDigit(2 * digit);
  }
  return sum;
}

long long Functions::getDigit(long long number)
{
  return (number / 10) + (number % 10);
}

long long Functions::sumOfOddPlace(long long number)
{
  int sum = 0;
 
  while (number > 0)
  {
    unsigned int digit = (int)(number % 10);
    number /= 100;

    sum += getDigit(digit);
  }
  return sum;
}

bool Functions::prefixMatched(long long number, long long digit)
{
  return getPrefix(number, getSize(digit)) == digit;
}

long long Functions::getSize(long long number)
{
  unsigned int digitCount = 0;

  while (number > 0)
  {
    number /= 10;
    digitCount++;
  }
  return digitCount;
}

long long Functions::getPrefix(long long number, long long numDigits)
{
  unsigned int numberSize = getSize(number);

  unsigned int decimalMovements = numberSize - numDigits;

  while (decimalMovements-- > 0)
  {
    number /= 10;
  }
  return number;
}
