#include <iostream>
#include <string>

void execQuadraticRoot()
{
  std::string a;
  std::string b;
  std::string c;
  std::cout << "Enter a, b, c: " << std::endl;
  std::cin >> a >> b >> c;
  std::cout << a << " " << b << " " << c << std::endl;
}

void execGradeCalculator()
{
  std::cout << "Grade Calculator" << std::endl;
}

void execCreditCardValidator()
{
  std::cout << "Credit card validator" << std::endl;
}

int main()
{
  bool validLastInput{ true };
  bool runChar{ true };
  std::string input;
  while (true)
  {
    if (validLastInput)
    {
      std::cout << "1. Quadratic Root" << std::endl;
      std::cout << "2. Grade Calculator" << std::endl;
      std::cout << "3. Credit Card Validator" << std::endl;
      std::cout << "Enter a number: " << std::endl;
    }
    std::cin >> input;
    if (!input.empty())
    {
      const int choice = std::stoi(input);
      if (choice == 1)
      {
        validLastInput = true;
        execQuadraticRoot();
      }
      else if (choice == 2)
      {
        validLastInput = true;
        execGradeCalculator();
      }
      else if (choice == 3)
      {
        validLastInput = true;
        execCreditCardValidator();
      }
      else
      {
        validLastInput = false;
      }
    }
  }
  return 0;
}