#include <gtest/gtest.h>
#include "zipfs.h"

TEST(ZipfsContainersTest, BasicTest) {
    std::vector<char> bookText = {'t', 'h', 'e', ' ', 'w', 'h', 'a', 'l', 'e'};
    auto frequencies = ZipfsContainers::computeWordFrequency(bookText);
    EXPECT_EQ(frequencies.size(), 2);
}

TEST(ZipfsAlgorithmsTest, BasicTest) {
    std::vector<char> bookText = {'t', 'h', 'e', ' ', 'w', 'h', 'a', 'l', 'e'};
    auto frequencies = ZipfsAlgorithms::computeWordFrequencyUsingAlgorithms(bookText);
    EXPECT_EQ(frequencies.size(), 2);
}

TEST(ZipfsAlgorithmsTest, UniqueWordCountTest) {
    std::vector<char> bookText = {'c', 'a', 't', ' ', 'c', 'a', 't', ' ', 'd', 'o', 'g'};
    int uniqueCount = ZipfsAlgorithms::countUniqueWords(bookText);
    EXPECT_EQ(uniqueCount, 2); 
}