#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <multimap>
#include <functional>

// milestone 1: reading the text
// reads the file and returns a vector of characters, where characters are replaced by spaces
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

// milestone 2: counting the words
// take a vector of characters and returns a map with word frequencies
std::map<std::string, int> computeWordFrequency(const std::vector<char>& book) {
    std::map<std::string, int> wordFrequency;
    std::string word;
    for (char ch : book) {
        if (ch == ' ') {
            if (!word.empty()) {
                wordFrequency[word]++;
                word.clear();
            }
        } else {
            word += ch;
        }
    }
    return wordFrequency;
}

// milestone 3: counting unique words
// counts the number of unique words in the book using an std::set
int countUniqueWords(const std::vector<char>& book) {
    std::set<std::string> uniqueWords;
    std::string word;
    for (char ch : book) {
        if (ch == ' ') {
            if (!word.empty()) {
                uniqueWords.insert(word);
                word.clear();
            }
        } else {
            word += ch;
        }
    }
    return uniqueWords.size();
}

// milestone 4: sorting the frequencies
// sorts the word frequencies in descending order using std::multimap
std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies) {
    std::multimap<int, std::string, std::greater<>> sortedFrequencies;
    for (const auto& entry : frequencies) {
        sortedFrequencies.insert({entry.second, entry.first});
    }
    return sortedFrequencies;
}

// milestone 5: plotting the results
// outputs the contents of the sorted multimap to a file in "rank freq word" format
void outputFrequenciesToFile(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies, const std::string& outputFile) {
    std::ofstream outFile(outputFile);

    int rank = 1;
    for (const auto& entry : sortedFrequencies) {
        outFile << rank << " " << entry.first << " " << entry.second << std::endl;
        rank++;
    }

    outFile.close();
    std::cout << "frequency data written to " << outputFile << std::endl;
}

// milestone 6: using structured binding to iterate
// demonstrating structured binding with the sorted frequencies output
void printTopFrequencies(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies, int topN = 10) {
    int count = 0;
    for (const auto& [frequency, word] : sortedFrequencies) {
        std::cout << "word: " << word << ", frequency: " << frequency << std::endl;
        if (++count == topN) break;
    }
}

// milestone 8: finding hápax legómenon
// counts and displays words that occur only once (hapax legomena)
void printHapaxLegomena(const std::multimap<int, std::string, std::greater<>>& sortedFrequencies) {
    int hapaxCount = 0;
    std::cout << "hapax legomena (words that occur only once):" << std::endl;

    for (const auto& [frequency, word] : sortedFrequencies) {
        if (frequency == 1) {
            if (hapaxCount < 10) { // print only the first few for illustration
                std::cout << word << std::endl;
            }
            hapaxCount++;
        }
    }

    std::cout << "total number of hapax legomena: " << hapaxCount << std::endl;
}

int main() {
    std::string fileName = "../assets/pg2701.txt"; 
    std::vector<char> bookText = readBook(fileName);
    // milestone 2
    auto wordFrequencies = computeWordFrequency(bookText);
    // milestone 3
    int uniqueWordCount = countUniqueWords(bookText);
    std::cout << "number of unique words: " << uniqueWordCount << std::endl;
    // milestone 4
    auto sortedFrequencies = sortFrequencies(wordFrequencies);
    // milestone 5
    outputFrequenciesToFile(sortedFrequencies, "word_frequencies.txt");
    // milestone
    printTopFrequencies(sortedFrequencies);
    // milestone 8
    printHapaxLegomena(sortedFrequencies);

    return 0;
}
