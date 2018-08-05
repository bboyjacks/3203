#include "WordInfo.h"
#include <iterator>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>

WordInfo::WordInfo()
{
}

void WordInfo::ReadWordsFromFile(const char* filename)
{
  std::ifstream infile(filename);
  std::string line;
  while (getline(infile, line))
  {
    //std::cout << line << std::endl;
    std::vector<char> striped_line;
    for (char character : line)
    {
      const int char_int = int(character);
      if ((65 <= char_int && char_int < 91) || (97 <= char_int && char_int < 123) || char_int == 32 || char_int == 45 || char_int == 39)
      {
        striped_line.push_back(char_int);
      }
    }

    std::string line_str(striped_line.begin(), striped_line.end());
    std::transform(line_str.begin(), line_str.end(), line_str.begin(), ::tolower);

    std::istringstream iss(line_str);
    std::vector<std::string> result{
      std::istream_iterator<std::string>(iss),{}
    };

    for (std::string word : result)
    {
      if (!word.empty() && word.front() == '\'')
        word.erase(word.begin());

      if (!word.empty() && word.back() == '\'')
        word.pop_back();

      if (word != "--")
      {
        m_total_words += 1;
        if (m_words_to_count.find(word) != m_words_to_count.end())
        {
          m_words_to_count[word] += 1;
        }
        else
          m_words_to_count[word] = 1;
      }
    }
  }
}

void WordInfo::DisplayStats() const
{
  std::cout << "Total number of words: " << m_total_words << std::endl;
  std::cout << "Number of unique words: " << m_words_to_count.size() << std::endl;
  std::cout << "Average word length: " << GetAvgWordSize() << std::endl;
  std::cout << "Longest word: " << GetLongestWord() << std::endl;
  //Total number of words : 2364
  //  Number of unique words : 620
  //  Average word length : 3
  //  Longest word : pocket - handkerchief
  //  3 most frequent words :
  //the 96
  //  and 86
  //  a 74
  //  3 most frequent words(ignoring most commonly used) :
  //  his 48
  //  said 27
  //  my 26
  //  Longest word(s) :
  //  pocket - handkerchief
  //  Enter a word for an exact search :
  //'penny' was found 2 times in the list.
  //  Enter a word for a partial search :
  //Words containing 'easy'
  //  easy
  //  uneasy
}

void WordInfo::MostCommonWords(int _count, bool _ignore_common_file) const
{
  std::vector<std::pair<std::string, int>> map_sorted_by_value;

  for (auto item = m_words_to_count.begin(); item != m_words_to_count.end(); ++item)
  {
    map_sorted_by_value.push_back(std::make_pair(item->first, item->second));
  }

  std::sort(map_sorted_by_value.begin(), map_sorted_by_value.end(),
    [](std::pair<std::string, int>& first, std::pair<std::string, int>& second)
    {
      return first.second > second.second;
    });

  if (_ignore_common_file)
  {
    std::cout << _count << " most frequent words (ignoring most commonly used): " << std::endl;
    int counter = 0;
    for (auto item : map_sorted_by_value)
    {
      if (counter < _count)
      {
        if (m_words_to_ignore.find(item.first) == m_words_to_ignore.end())
        {
          std::cout << "   " << item.first << " " << item.second << std::endl;
          counter += 1;
        }
      }
      else
        break;
    }
  }
  else
  {
    std::cout << _count << " most frequent words:" << std::endl;
    for (int i = 0; i < _count; ++i)
    {
      std::cout << "   " << map_sorted_by_value[i].first << " " << map_sorted_by_value[i].second << std::endl;
    }
  }
}

void WordInfo::LongestWords(std::vector<std::string>& _words) const
{
  std::vector<std::pair<std::string, int>> map_sorted_by_value;

  for (auto item = m_words_to_count.begin(); item != m_words_to_count.end(); ++item)
  {
    map_sorted_by_value.push_back(std::make_pair(item->first, item->second));
  }

  std::sort(map_sorted_by_value.begin(), map_sorted_by_value.end(),
    [](std::pair<std::string, int>& first, std::pair<std::string, int>& second)
  {
    return first.first.size() > second.first.size();
  });

  _words.clear();

  _words.push_back(map_sorted_by_value.front().first);
  unsigned cur_max = map_sorted_by_value.front().first.size();
  for (size_t i = 1; i < map_sorted_by_value.size(); ++i)
  {
    if (map_sorted_by_value[i].first.size() == cur_max)
    {
      _words.push_back(map_sorted_by_value[i].first);
    }
    else
      break;
  }
}

void WordInfo::SetIgnoreWords(std::vector<std::string>& _ignore)
{
  for (const std::string& word : _ignore)
  {
    m_words_to_ignore[word] = word;
  }
}

int WordInfo::SearchForWord(const char* _word)
{
  return m_words_to_count[_word];
}

std::vector<std::string> WordInfo::SearchPartial(const char * _word)
{
  std::vector<std::string> partial_matches;
  for (auto item = m_words_to_count.begin(); item != m_words_to_count.end(); ++item)
  {
    if (item->first.find(_word) != std::string::npos)
    {
      partial_matches.push_back(item->first);
    }
  }
  return partial_matches;
}

unsigned WordInfo::GetTotalNumWords() const
{
  return m_total_words;
}

unsigned WordInfo::GetNumUniqueWords() const
{
  return m_words_to_count.size();
}

std::string WordInfo::GetLongestWord() const
{
  std::vector<std::string> longest_words;
  LongestWords(longest_words);
  return longest_words.front();
}

unsigned WordInfo::GetAvgWordSize() const
{
  unsigned total_char_count{ 0 };
  for (auto item = m_words_to_count.begin(); item != m_words_to_count.end(); ++item)
  {
    total_char_count += item->first.size() * item->second;
  }
  return total_char_count / m_total_words;
}

WordInfo::~WordInfo()
{
}
