#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Functions.h"

void execQuadraticRoot()
{
  std::string a;
  std::string b;
  std::string c;
  std::cout << "Enter a, b, c: ";
  std::cin >> a >> b >> c;

  const double a_d = std::stof(a);
  const double b_d = std::stof(b);
  const double c_d = std::stof(c);

  const double discriminant = b_d * b_d - 4 * a_d * c_d;
  
  std::cout << std::endl;
  if (discriminant < 0)
    std::cout << "The equation has no real roots.";
  else if (discriminant > 0)
  {
    const double r1 = (-b_d + std::sqrt(discriminant)) / (2 * a_d);
    const double r2 = (-b_d - std::sqrt(discriminant)) / (2 * a_d);

    std::cout << "The equation has two roots: " << r1 << " and " << r2;
  }
  else
  {
    const double r = -b_d / (2 * a_d);

    std::cout << "The equation has one root: " << r;
  }
}

void execGradeCalculator()
{
  std::string input_str;
  std::cout << "Enter the number of students: ";
  std::cin >> input_str;
  const unsigned int input_int = std::stoi(input_str);
  std::vector<int> scores(input_int);
  std::vector<char> grades(5);

  int best_score = -1;

  std::cout << std::endl;
  for (unsigned int i = 0; i < input_int; i++)
  {
    std::string grade_str;
    std::cin >> grade_str;
    const int grade_int = std::stoi(grade_str);
    scores[i] = grade_int;
    if (best_score < scores[i])
      best_score = scores[i];
  }

  for (unsigned int i = 0; i < input_int; i++)
  {
    if (scores[i] >= best_score - 10)
    {
      grades[i] = 'A';
    }
    else if (scores[i] >= best_score - 20)
    {
      grades[i] = 'B';
    }
    else if (scores[i] >= best_score - 30)
    {
      grades[i] = 'C';
    }
    else if (scores[i] >= best_score - 40)
    {
      grades[i] = 'D';
    }
    else
      grades[i] = 'F';

    std::cout << "Student " << i + 1 << " - Score: " << scores[i] << ", Letter: " << grades[i] << std::endl;;
  }
}

void execCreditCardValidator()
{
  std::cout << "Enter a credit card number: " << std::endl;
  long long input;
  std::cin >> input;

  std::cout << input << " is ";
  if (Functions::isValid(input))
    std::cout << "valid.";
  else
    std::cout << "invalid.";
}

int main()
{
  int input;

  std::cout << "1. Quadratic Root" << std::endl;
  std::cout << "2. Grade Calculator" << std::endl;
  std::cout << "3. Credit Card Validator" << std::endl;
  std::cout << "Enter a number: " << std::endl;
  std::cin >> input;
  if (!std::cin.fail())
  {
    if (input == 1)
      execQuadraticRoot();
    else if (input == 2)
      execGradeCalculator();
    else if (input == 3)
      execCreditCardValidator();
    else if (input < 1 || input > 3)
      std::cout << "Input out of range!";
  }
  else
    std::cout << "Invalid input!";

  return 0;
}