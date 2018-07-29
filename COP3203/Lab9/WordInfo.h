#pragma once
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class WordInfo
{
public:
  WordInfo();
  WordInfo(std::vector<std::string>& _words_to_ignore);
  void AddWords(const std::string& _line_str);
  unsigned GetTotalNumWords() const;
  unsigned GetNumUniqueWords() const;
  std::string GetLongestWord() const;
  unsigned GetAvgWordSize() const;
  virtual ~WordInfo();
private:
  std::map<std::string, std::string> m_words_to_ignore;
  std::unordered_map<std::string, int> m_words_to_count;
  unsigned m_total_words{0};
};