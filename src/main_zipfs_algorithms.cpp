#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <sstream>

// milestone 1: reading the text
// reads the file and returns a vector of characters
std::vector<char> readBook(const std::string& fileName) {
    std::vector<char> characters;
    std::ifstream file(fileName);

    char ch;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            characters.push_back(std::tolower(ch)); // alphabetic characters and convert to lowercase
        } else {
            characters.push_back(' '); // replace non-alphabetic characters with a space
        }
    }
    file.close();
    return characters;
}

// helper function to split text into words
std::vector<std::string> splitIntoWords(const std::vector<char>& book) {
    std::istringstream iss(std::string(book.begin(), book.end()));
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}
// milestone 2: compute word frequencies using only std::vector
std::vector<std::pair<std::string, int>> computeWordFrequency(const std::vector<std::string>& words) {
    std::vector<std::pair<std::string, int>> frequencies;

    for (const auto& word : words) {
        // check if the word already exists in frequencies
        auto it = std::find_if(frequencies.begin(), frequencies.end(),
                               [&word](const std::pair<std::string, int>& element) {
                                   return element.first == word;
                               });
        
        if (it != frequencies.end()) {
            // increment the count if the word is found
            it->second++;
        } else {
            // add new word with a count of 1
            frequencies.emplace_back(word, 1);
        }
    }
    return frequencies;
}
// milestone 3: count unique words using std::vector
int countUniqueWords(const std::vector<std::string>& words) {
    std::vector<std::string> uniqueWords = words;
    
    // sort and remove duplicates
    std::sort(uniqueWords.begin(), uniqueWords.end());
    auto last = std::unique(uniqueWords.begin(), uniqueWords.end());
    uniqueWords.erase(last, uniqueWords.end());
    
    return uniqueWords.size();
}
// milestone 4: sort the word frequencies in descending order
std::vector<std::pair<std::string, int>> sortFrequencies(const std::vector<std::pair<std::string, int>>& frequencies) {
    std::vector<std::pair<std::string, int>> sortedFrequencies = frequencies;
    
    // sort by frequency in descending order
    std::sort(sortedFrequencies.begin(), sortedFrequencies.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });
    
    return sortedFrequencies;
}

// milestone 5: output the frequencies to a file 
void outputFrequenciesToFile(const std::vector<std::pair<std::string, int>>& sortedFrequencies, const std::string& outputFile) {
    std::ofstream outFile(outputFile);
    int rank = 1;
    for (const auto& entry : sortedFrequencies) {
        outFile << rank << " " << entry.second << " " << entry.first << std::endl;
        rank++;
    }
    outFile.close();
    std::cout << "frequency data written to " << outputFile << std::endl;
}

int main() {
    std::string fileName = "../assets/pg2701.txt"; 
    std::vector<char> bookText = readBook(fileName);
    // split text into words
    auto words = splitIntoWords(bookText);
    // compute word frequencies
    auto wordFrequencies = computeWordFrequency(words);
    // count unique words
    int uniqueWordCount = countUniqueWords(words);
    std::cout << "number of unique words: " << uniqueWordCount << std::endl;
    // sort frequencies
    auto sortedFrequencies = sortFrequencies(wordFrequencies);
    // output to file
    outputFrequenciesToFile(sortedFrequencies, "word_frequencies.txt");

    return 0;
}
