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
  float m_usprice;

  Lego(const int _number,
	  string _theme,
	  string _name,
	  const int _minifigs,
	  const int _pieces,
	  const float _usprice)
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
  int first_line = 0;

  ifstream file(_file);
  string line;
  // Iterate through each line and split the content using delimeter
  while (getline(file, line))
  {
	  if (first_line == 0)
	  {
		  first_line++;
		  continue;
	  }
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

    const string token_str(token.begin(), token.end());
    lego_params.push_back(token_str);
    token.clear();

	  const int number = lego_params[0].empty() ? 0 : stoi(lego_params[0]);
	  const string theme = lego_params[1];
	  const string name = lego_params[2];
	  const int minifigs = lego_params[3].empty() ? 0 : stoi(lego_params[3]);
	  const int pieces = lego_params[4].empty() ? 0 : stoi(lego_params[4]);
	  const float price = lego_params[5].empty() ? 0 : stof(lego_params[5]);

	  Lego *new_lego = new Lego(number, theme, name, minifigs, pieces, price);
	  _legos.push_back(new_lego);
  }
  // Close the File
  file.close();
}

void LoadFromMultiFile(vector<Lego*>& _legos, const vector<string>& _files)
{
  for (const string& file : _files)
  {
    LoadFromOneFile(_legos, file);
  }
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
  vector<Lego*> legos;
  vector<string> files = { "SAMPLE_lego1.csv", "SAMPLE_lego2.csv", "SAMPLE_lego3.csv" };

  switch (option)
  {
  case 1:
    LoadFromOneFile(legos, files[0]);
    break;
  case 2:
    LoadFromOneFile(legos, files[1]);
    break; 
  case 3:
    LoadFromOneFile(legos, files[2]);
    break;
  case 4:
    LoadFromMultiFile(legos, files);
    break;
  }

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


