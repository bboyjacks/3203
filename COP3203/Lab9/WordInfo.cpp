#include "WordInfo.h"



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

void WordInfo::AddWords(const std::string & _line_str)
{
}

WordInfo::~WordInfo()
{
}
