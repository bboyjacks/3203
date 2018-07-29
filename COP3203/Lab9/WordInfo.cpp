#include "WordInfo.h"
#include <iterator>
#include <sstream>

WordInfo::WordInfo()
{
}

WordInfo::WordInfo(std::vector<std::string>& _words_to_ignore)
{
  for (const std::string& word : _words_to_ignore)
  {
    m_words_to_ignore[word] = word;
  }
}

void WordInfo::AddWords(const std::string& _line_str)
{
  std::istringstream iss(_line_str);
  std::vector<std::string> result{
    std::istream_iterator<std::string>(iss),{}
  };

  for (const std::string& word : result)
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
  std::string longest_word;
  unsigned longest_word_count{0};
  for (auto item = m_words_to_count.begin(); item != m_words_to_count.end(); ++item) 
  {
    if (longest_word_count < item->first.size())
    {
      longest_word_count = item->first.size();
      longest_word = item->first;
    }
  }
  return longest_word;
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
