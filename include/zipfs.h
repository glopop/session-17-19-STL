#ifndef ZIPFS_H
#define ZIPFS_H

#include <vector>
#include <string>
#include <utility>

namespace ZipfsContainers {
    std::vector<std::pair<int, std::string>> computeWordFrequency(const std::vector<char>& book);
    void displayTopWords(const std::vector<std::pair<int, std::string>>& frequencies, int topN = 10);
}

namespace ZipfsAlgorithms {
    std::vector<std::pair<int, std::string>> computeWordFrequencyUsingAlgorithms(const std::vector<char>& book);
    void displayTopWords(const std::vector<std::pair<int, std::string>>& frequencies, int topN = 10);
}

#endif 
