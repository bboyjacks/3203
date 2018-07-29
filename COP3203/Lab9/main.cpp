// Lexer.cpp : Defines the entry point for the console application.
//
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
  // Read the words from the file
  // Show the stats
  // Show the most frequent words, NOT using the ignore list
  // Show the most frequent words, using the ignore list (to ignore the universally common words)

  // (Show a number of common words based on the selected file + 1. First file shows 2 common words, second shows 3, 4th shows 5, etc)

  // Get and then show the longest words
  vector<string> longestWords;

  // Get input for a word, and do an exact match search for that word. (Convert input to lowercase first!)
  cout << "Enter a word for an exact search: ";

  //cout << '\'' << searchTerm << "' was found " << count << " times in the list.\n";

  //// Ditto for partial search...
  //cout << "Enter a word for a partial search: ";

  //if (no matches found)
  //  cout << "\nNo entries match '" << searchTerm << '\'' << endl;
  //else
  //{
  //  cout << "\nWords containing '" << thesearchterm << '\'' << endl;

  //  // print list o' matches
  //}
  cin >> option;

  return 0;
}

