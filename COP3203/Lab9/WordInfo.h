#pragma once
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class WordInfo
{
public:
  WordInfo();
  void ReadWordsFromFile(const char* filename);
  void DisplayStats() const;
  void MostCommonWords(int _count, bool _ignore_common_file = false) const;
  void LongestWords(std::vector<std::string>& _words) const;
  void SetIgnoreWords(std::vector<std::string>& _ignore);
  int SearchForWord(const char* _word) const;
  virtual ~WordInfo();
private:
  unsigned GetTotalNumWords() const;
  unsigned GetNumUniqueWords() const;
  std::string GetLongestWord() const;
  unsigned GetAvgWordSize() const;
  std::map<std::string, std::string> m_words_to_ignore;
  std::unordered_map<std::string, int> m_words_to_count;
  unsigned m_total_words{0};
};