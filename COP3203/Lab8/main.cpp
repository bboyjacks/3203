#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Inventory
{
  string m_name;
  int m_value;
  float m_weight;
  Inventory(string&& _name, int _value, float _weight)
    : m_name(std::move(_name)),
    m_value(_value),
    m_weight(_weight)
  {

  }
};

struct Hero
{
  string m_name;
  int m_strength;
  int m_intelligence;
  int m_agility;
  int m_cur_hit_points;
  int m_max_hit_points;
  float m_armor;
  float m_magic_armor;
  vector<Inventory*> m_inventories;

  Hero(string&& _name,
    int _strength,
    int _intelligence,
    int _agility,
    int _cur_hit_points,
    int _max_hit_points,
    float _armor,
    float _magic_armor,
    vector<Inventory*>& _inventories)

    : m_name(std::move(_name)),
    m_strength(_strength),
    m_intelligence(_intelligence),
    m_agility(_agility),
    m_cur_hit_points(_cur_hit_points),
    m_max_hit_points(_max_hit_points),
    m_armor(_armor),
    m_magic_armor(_magic_armor),
    m_inventories(std::move(_inventories))
  {

  }
};

void PrintHero(const Hero& _hero)
{
  cout << "Name: " << _hero.m_name << endl;
  cout << "Str: " << _hero.m_strength << endl;
  cout << "Int: " << _hero.m_intelligence << endl;
  cout << "Agi: " << _hero.m_agility << endl;
  cout << "HP: " << _hero.m_cur_hit_points << " / " << _hero.m_max_hit_points << endl;
  cout << "Armor: " << _hero.m_armor << endl;
  cout << "Magic armor: " << _hero.m_magic_armor << endl;
  cout << "Inventory:" << endl;

  for (const Inventory const* inventory : _hero.m_inventories)
  {
    cout << "    ";
    cout << inventory->m_name << ", ";
    cout << inventory->m_value << ", ";
    cout << inventory->m_weight << endl;
  }
  cout << endl;
}

void LoadHeroes(vector<Hero*>& _heroes, const string& _file)
{
  /* Load hero files here */
  ifstream is(_file, std::ifstream::binary);
  if (is)
  {
    int num_characters;
    is.read((char *)&num_characters, 4);

    for (int i = 0; i < num_characters; ++i)
    {
      int name_len;
      is.read((char *)&name_len, 4);

      char *name = new char[name_len];
      is.read(name, name_len);

      short strength;
      is.read((char *)&strength, 2);

      short intelligence;
      is.read((char *)&intelligence, 2);

      short agility;
      is.read((char *)&agility, 2);

      int cur_hit_points;
      is.read((char *)&cur_hit_points, 4);
      int max_hit_points;
      is.read((char *)&max_hit_points, 4);

      float armor;
      is.read((char *)&armor, 4);

      float magic_armor;
      is.read((char *)&magic_armor, 4);

      int inventory_num;
      is.read((char *)&inventory_num, 4);


      vector<Inventory*> inventory;
      for (int j = 0; j < inventory_num; ++j)
      {
        int inventory_name_len;
        is.read((char *)&inventory_name_len, 4);

        char *inventory_name = new char[inventory_name_len];
        is.read(inventory_name, inventory_name_len);

        int inventory_value;
        is.read((char *)&inventory_value, 4);

        float inventory_weight;
        is.read((char *)&inventory_weight, 4);

        inventory.push_back(new Inventory(inventory_name, inventory_value, inventory_weight));
      }
      _heroes.push_back(new Hero(name,
        strength,
        intelligence,
        agility,
        cur_hit_points,
        max_hit_points,
        armor,
        magic_armor,
        inventory));

    }
    is.close();

  }
}

void PrintAll(vector<Hero*> _heroes)
{
  for (const Hero const* hero : _heroes)
  {
    PrintHero(*hero);
  }
}

int main()
{
  cout << "Which file(s) to open?\n";
  cout << "1. fantasyheroes.dat" << endl;
  cout << "2. superheroes.dat" << endl;
  cout << "3. Both files" << endl;
  int option;
  cin >> option;

  vector<Hero*> heroes;
  LoadHeroes(heroes, "heroes.dat");

  cout << "1. Print all heroes" << endl;
  cout << "2. Hero with the most items" << endl;
  cout << "3. Strongest hero" << endl;
  cout << "4. Heroes with greater than 18 intelligence" << endl;
  cout << "5. 2 clumsiest heroes" << endl;
  cout << "6. Hero with the most valuable stuff" << endl << endl;

  std::cin >> option;
  cin.get();

  /* Work your magic here */
  switch (option)
  {
  case 1:
    PrintAll(heroes);
    break;
  }
  getchar();
  return 0;
}
