#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Lego
{
  int m_number;
  string m_theme;
  string m_name;
  int m_minifigs;
  int m_pieces;
  double m_usprice;

  Lego(const int _number,
       string _theme,
       string _name,
       const int _minifigs,
       const int _pieces,
       const double _usprice)
    : m_number(_number),
      m_theme(std::move(_theme)),
      m_name(std::move(_name)),
      m_minifigs(_minifigs),
      m_pieces(_pieces),
      m_usprice(_usprice)
  {}

  Lego(const Lego& _other)
  {
    m_number = _other.m_number;
    m_theme = _other.m_theme;
    m_name = _other.m_name;
    m_minifigs = _other.m_minifigs;
    m_pieces = _other.m_pieces;
    m_usprice = _other.m_usprice;
  }

  Lego(Lego&& _other) noexcept
  {
    m_number = _other.m_number;
    m_theme = _other.m_theme;
    m_name = _other.m_name;
    m_minifigs = _other.m_minifigs;
    m_pieces = _other.m_pieces;
    m_usprice = _other.m_usprice;
  }

  Lego& operator=(const Lego& _other)
  {
    Lego tmp(_other);
    *this = std::move(tmp);
    return *this;
  }

  Lego& operator=(Lego&& _other) noexcept
  {
    if (this == &_other)
    {
      return *this;
    }
    m_number = _other.m_number;
    m_theme = _other.m_theme;
    m_name = _other.m_name;
    m_minifigs = _other.m_minifigs;
    m_pieces = _other.m_pieces;
    m_usprice = _other.m_usprice;
    return *this;
  }

  void Print()
  {
    std::cout << "Number: " << m_number << std::endl;
    std::cout << "Theme: " << m_theme << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Minifigs: " << m_minifigs << std::endl;
    std::cout << "Pieces: " << m_pieces << std::endl;
    std::cout << "Price: " << m_usprice << std::endl;

  }

  ~Lego() = default;
};

void LoadFromOneFile(vector<Lego*>& _legos, const string& _file)
{
  ifstream file(_file);
  string line;
  // Iterate through each line and split the content using delimeter
  while (getline(file, line))
  {
    vector<string> lego_params;
    vector<char> token;
    for (size_t i = 0; i < line.size(); ++i)
    {
      if (line[i] == ',')
      {
        const string token_str(token.begin(), token.end());
        lego_params.push_back(token_str);
        token.clear();
      }
      else
      {
        token.push_back(line[i]);
      }
    }
  }
  // Close the File
  file.close();
}

void LoadFromMultiFile(vector<Lego*>& _legos, const vector<string&> _files)
{

}

int main()
{
  cout << std::fixed << setprecision(2);
  cout << "Which file(s) to open?\n";
  cout << "1. lego1.csv" << endl;
  cout << "2. lego2.csv" << endl;
  cout << "3. lego3.csv" << endl;
  cout << "4. All 3 files" << endl;
  int option;
  std::cin >> option;

  /*======= Load data from file(s) =======*/
  /*======= Print out how many sets were loaded =======*/

  /* Imagine your program had a menu like this:
  cout << "1. Most Expensive set" << endl;
  cout << "2. Largest piece count" << endl;
  cout << "3. Search for set name containing..." << endl;
  cout << "4. Search themes..." << endl;
  cout << "5. Part count information" << endl;
  cout << "6. Price information" << endl;
  cout << "7. Minifigure information" << endl;
  cout << "8. If you bought one of everything..." << endl;
  cout << "0. Exit" << endl;
  */
  int choice;
  cin >> choice;
  cin.get();  // Clear newline character for any later input

              /*======= Based on the choice, execute the appropriate task and show the results =======*/

  return 0;
}


