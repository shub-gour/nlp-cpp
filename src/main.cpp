#include <iostream>
#include <vector>

#include "../include/nlp_cpp/stemmer.hpp"

int main() {

    std::vector<std::string> words = {
        "running",
        "played",
        "cats",
        "working"
    };

    for (const auto& word : words) {

        std::cout
            << word
            << " -> "
            << nlp_cpp::stem(word)
            << std::endl;
    }

    return 0;
}