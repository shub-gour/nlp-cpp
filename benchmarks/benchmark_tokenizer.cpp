#include <iostream>
#include <chrono>
#include <string>

#include "../include/nlp_cpp/tokenizer.hpp"

int main() {

    std::string text;

    for (int i = 0; i < 100000; i++) {
        text +=
            "Hello world I love NLP ";
    }

    auto start =
        std::chrono::high_resolution_clock::now();

    auto tokens =
        nlp_cpp::word_tokenize(text);

    auto end =
        std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<
            std::chrono::milliseconds
        >(end - start);

    std::cout
        << "Tokenization time: "
        << duration.count()
        << " ms"
        << std::endl;

    std::cout
        << "Total tokens: "
        << tokens.size()
        << std::endl;

    return 0;
}