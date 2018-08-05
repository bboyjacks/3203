#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void CreateVec(int arr_size, std::vector<std::string>& vec, std::string* arr)
{
  for (int i = 0; i < arr_size; ++i)
  {
    vec.push_back(arr[i]);
  }
}


std::map<std::string, std::string> MapAnswersWithName(std::string names[], std::string answers[], int name_size, int answer_size)
{
  std::vector<std::string> names_vec;
  std::vector<std::string> answers_vec;

  CreateVec(name_size, names_vec, names);
  CreateVec(answer_size, answers_vec, answers);

  std::sort(names_vec.begin(), names_vec.end(), [](std::string first, std::string second) {return first.size() < second.size(); });
  std::sort(answers_vec.begin(), answers_vec.end(), [](std::string first, std::string second) {return first.size() < second.size(); });

  std::map<std::string, std::string> result;
  for (int i = 0; i < name_size; ++i)
  {
    result[names_vec[i]] = answers_vec[i];
  }
  return result;
}


int main()
{
  std::string names[] = { "Abc", "ab", "a" };
  std::string answers[] = { "adbd", "aad", "ad" };
  std::map<std::string, std::string> result = MapAnswersWithName(names, answers, 3, 3);

  int input;
  std::cin >> input;
  return 0;
}