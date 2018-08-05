// Lexer.cpp : Defines the entry point for the console application.
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "WordInfo.h"
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
  // TODO: Load words_to_ignore.txt, store those in a vector of strings to pass to your class objects
  ifstream infile("words_to_ignore.txt");
  string line;
  vector<string> words_to_ignore;
  while (getline(infile, line))
  {
    words_to_ignore.push_back(line);
  }

  cout << "1-4: Which file to open?" << endl;
  int option;
  cin >> option;

  // TODO: Create a WordList object and set the list of words to ignore
  WordInfo word_info;

  vector<string> files = {"file1.txt", "file2.txt", "file3.txt", "file4.txt" };
  string file = files[option - 1];

  word_info.ReadWordsFromFile(file.c_str());
  word_info.DisplayStats();
  word_info.MostCommonWords(option + 1);
  word_info.SetIgnoreWords(words_to_ignore);
  word_info.MostCommonWords(option + 1, true);
  // Read the words from the file
  // Show the stats
  // Show the most frequent words, NOT using the ignore list
  // Show the most frequent words, using the ignore list (to ignore the universally common words)

  // (Show a number of common words based on the selected file + 1. First file shows 2 common words, second shows 3, 4th shows 5, etc)

  // Get and then show the longest words
  vector<string> longestWords;
  word_info.LongestWords(longestWords);
  std::cout << "Longest word(s): " << std::endl;
  for (auto item : longestWords)
  {
    std::cout << "   " << item << std::endl;
  }

  // Get input for a word, and do an exact match search for that word. (Convert input to lowercdase first!)
  cout << "Enter a word for an exact search: ";
  std::string searchTerm;
  cin >> searchTerm;

  std::transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
  int count = word_info.SearchForWord(searchTerm.c_str());
  cout << "\n   " << '\'' << searchTerm << "' was found " << count << " times in the list.\n";

  // Ditto for partial search...
  cout << "Enter a word for a partial search: ";
  std::string searchTerm2;
  cin >> searchTerm2;
  std::vector<std::string> partial_matches = word_info.SearchPartial(searchTerm2.c_str());
  if (partial_matches.empty())
    cout << "\n   No entries match '" << searchTerm2 << '\'' << endl;
  else
  {
    cout << "\nWords containing '" << searchTerm2 << '\'' << endl;
    std::sort(partial_matches.begin(), partial_matches.end());
    // print list o' matches
    for (std::string& item : partial_matches)
      std::cout << "   " << item << std::endl;
  }
  cin >> option;

  return 0;
}

