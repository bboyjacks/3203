#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits.h>
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
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Number: " << m_number << std::endl;
    std::cout << "Theme: " << m_theme << std::endl;
    std::cout << "Price: $" << m_usprice << std::endl;
    std::cout << "Minifigures: " << m_minifigs << std::endl;
    std::cout << "Piece count: " << m_pieces << std::endl << std::endl;
  }

  void Print2()
  {
    // set id, name, and price
    std::cout << m_number << " " << m_name << " $" << m_usprice << " " << std::endl;
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
    float price = 0.0f;
    try
    {
      price = stof(lego_params[5]);
    }
    catch (exception e) {}

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

void GetMostExpensiveSet(vector<Lego*> _legos)
{
  Lego *max_lego = _legos.front();
  int max_price = 0;
  for (Lego* lego : _legos)
  {
    if (max_price < lego->m_usprice)
    {
      max_price = lego->m_usprice;
      max_lego = lego;
    }
  }

  std::cout << "Total number of sets: " << _legos.size() << std::endl << std::endl;
  std::cout << "The most expensive set is:" << std::endl;
  max_lego->Print();
}

void GetLargestPieceCount(vector<Lego*> _legos)
{
  Lego *max_lego = _legos.front();
  int max_price = 0;
  for (Lego* lego : _legos)
  {
    if (max_price < lego->m_pieces)
    {
      max_price = lego->m_pieces;
      max_lego = lego;
    }
  }

  std::cout << "Total number of sets: " << _legos.size() << std::endl << std::endl;
  std::cout << "The set with the highest parts count:" << std::endl;
  max_lego->Print();
}

void SearchForNameContaining(vector<Lego*> _legos, const string& _substring)
{
  vector<Lego*> search_results;
  for (Lego* lego : _legos)
  {
    if (lego->m_name.find(_substring) != string::npos)
    {
      search_results.push_back(lego);
    }
  }
  std::cout << "Total number of sets: " << _legos.size() << std::endl << std::endl;
  if (search_results.size() != 0)
  {
    std::cout << "Sets matching \"" << _substring << "\":" << std::endl;
    for (Lego* lego : search_results)
      lego->Print2();
    std::cout << std::endl;
  }
  else
  {
    std::cout << "No sets found matching that search term" << std::endl;
  }
}

void SearchForThemeContaining(vector<Lego*> _legos, const string& _substring)
{
  vector<Lego*> search_results;
  for (Lego* lego : _legos)
  {
    if (lego->m_theme.find(_substring) != string::npos)
    {
      search_results.push_back(lego);
    }
  }

  std::cout << "Total number of sets: " << _legos.size() << std::endl << std::endl;
  if (search_results.size() != 0)
  {
    std::cout << "Sets matching \"" << _substring << "\":" << std::endl;
    for (Lego* lego : search_results)
      lego->Print2();
    std::cout << std::endl;
  }
  else
  {
    std::cout << "No sets found matching that search term" << std::endl;
  }
}

void GetPartCountInfo(vector<Lego*> _legos)
{
  int max_part_count = 0;
  int min_part_count = INT_MAX;
  int total_part_count = 0;
  Lego *max_lego = _legos.front();
  Lego *min_lego = _legos.front();
  int total_nonzero_part_count = 0;

  for (Lego* lego : _legos)
  {
    if (lego->m_pieces > 0)
    {
      if (max_part_count < lego->m_pieces)
      {
        max_part_count = lego->m_pieces;
        max_lego = lego;
      }

      if (min_part_count > lego->m_pieces)
      {
        min_part_count = lego->m_pieces;
        min_lego = lego;
      }

      total_part_count += lego->m_pieces;
      total_nonzero_part_count += 1;
    }
  }

  std::cout << "Total number of sets: " << _legos.size() << std::endl << std::endl;

  std::cout << "Average part count for "<< total_nonzero_part_count << " sets: " << total_part_count / total_nonzero_part_count << std::endl << std::endl;
  std::cout << "Set with the smallest part count:" << std::endl;
  min_lego->Print();
  std::cout << "Set with the largest part count:" << std::endl;
  max_lego->Print();
}

void GetPriceInfo(vector<Lego*> _legos)
{
  int max_price = 0;
  int min_price = INT_MAX;
  float total_price = 0;
  Lego *max_lego = _legos.front();
  Lego *min_lego = _legos.front();
  int total_non_zero_set = 0;

  for (Lego* lego : _legos)
  {
    if (lego->m_usprice > 0)
    {
      if (max_price < lego->m_usprice)
      {
        max_price = lego->m_usprice;
        max_lego = lego;
      }

      if (min_price > lego->m_usprice)
      {
        min_price = lego->m_usprice;
        min_lego = lego;
      }

      total_price += lego->m_usprice;
      total_non_zero_set += 1;
    }
  }

  std::cout << "Total number of sets: " << _legos.size() << std::endl << std::endl;

  if (total_non_zero_set != 0)
  {
    std::cout << "Average price for " << total_non_zero_set << " sets: $" << total_price / total_non_zero_set << std::endl << std::endl;
    std::cout << "Least expensive set:" << std::endl;
    min_lego->Print();
    std::cout << "Most expensive set:" << std::endl;
    max_lego->Print();
  }
  else
    cout << "Error in price" << endl;
}

void GetMinifigureInfo(vector<Lego*> _legos)
{
  int max_minifig_count = 0;
  int min_minifig_count = INT_MAX;
  int total_minifig_count = 0;
  Lego *max_lego = _legos.front();
  Lego *min_lego = _legos.front();
  int total_non_zero_minifig = 0;

  for (Lego* lego : _legos)
  {
    if (lego->m_minifigs > 0)
    {

      if (max_minifig_count < lego->m_minifigs)
      {
        max_minifig_count = lego->m_minifigs;
        max_lego = lego;
      }

      if (min_minifig_count > lego->m_minifigs)
      {
        min_minifig_count = lego->m_minifigs;
        min_lego = lego;
      }

      total_minifig_count += lego->m_minifigs;
      total_non_zero_minifig += 1;
    }
  }

  std::cout << "Total number of sets: " << _legos.size() << std::endl << std::endl;

  std::cout << "Average number of minifigures: " << total_minifig_count / total_non_zero_minifig << std::endl << std::endl;
  std::cout << "Set with the most minifigures:" << std::endl;
  max_lego->Print();
  std::cout << "Set with the fewest minifigures:" << std::endl;
  min_lego->Print();

}

void GetTotalInfo(vector<Lego*> _legos)
{
  float total_price = 0;
  int total_pieces_count = 0;
  int total_minifig_count = 0;

  for (Lego* lego : _legos)
  {
    total_price += lego->m_usprice;
    total_pieces_count += lego->m_pieces;
    total_minifig_count += lego->m_minifigs;
  }


  std::cout << "Total number of sets: " << _legos.size() << std::endl << std::endl;
  cout << "If you bought one of everything..." << endl;
  cout << "It would cost: $" << total_price << endl;
  cout << "You would have " << total_pieces_count << " pieces in your collection" << endl;
  cout << "You would have an army of " << total_minifig_count << " minifigures!" << std::endl;
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
  vector<string> files = { "lego1.csv", "lego2.csv", "lego3.csv" };

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

  /* Imagine your program had a menu like this: */
  //cout << "1. Most Expensive set" << endl;
  //cout << "2. Largest piece count" << endl;
  //cout << "3. Search for set name containing..." << endl;
  //cout << "4. Search themes..." << endl;
  //cout << "5. Part count information" << endl;
  //cout << "6. Price information" << endl;
  //cout << "7. Minifigure information" << endl;
  //cout << "8. If you bought one of everything..." << endl;
  //cout << "0. Exit" << endl;

  int choice;
  cin >> choice;
  cin.get();  // Clear newline character for any later input

              /*======= Based on the choice, execute the appropriate task and show the results =======*/
  switch (choice)
  {
  case 1:
    GetMostExpensiveSet(legos);
    break;
  case 2:
    GetLargestPieceCount(legos);
    break;
  case 3:
  {
    string substring;
    getline(cin, substring);
    SearchForNameContaining(legos, substring);
    break;
  }

  case 4:
  {
    string substring;
    getline(cin, substring);
    SearchForThemeContaining(legos, substring);
    break;
  }

  case 5:
    GetPartCountInfo(legos);
    break;

  case 6:
    GetPriceInfo(legos);
    break;

  case 7:
    GetMinifigureInfo(legos);
    break;

  case 8:
    GetTotalInfo(legos);
    break;

  case 0:
    break;

  }

  getchar();
  return 0;
}


