#include <iostream>
#include <vector>
#include <unordered_map>

#include "../include/nlp_cpp/tokenizer.hpp"
#include "../include/nlp_cpp/stopwords.hpp"
#include "../include/nlp_cpp/freqdist.hpp"
#include "../include/nlp_cpp/stemmer.hpp"

bool test_word_tokenize() {

    std::string text =
        "Hello, world!";

    std::vector<std::string> expected = {
        "Hello",
        "world"
    };

    auto result =
        nlp_cpp::word_tokenize(text);

    return result == expected;
}

bool test_sent_tokenize() {

    std::string text =
        "Hello world. I love NLP!";

    std::vector<std::string> expected = {
        "Hello world",
        "I love NLP"
    };

    auto result =
        nlp_cpp::sent_tokenize(text);

    return result == expected;
}

bool test_remove_stopwords() {

    std::vector<std::string> tokens = {
        "I",
        "love",
        "NLP",
        "and",
        "machine",
        "learning"
    };

    std::vector<std::string> expected = {
        "love",
        "NLP",
        "machine",
        "learning"
    };

    auto result =
        nlp_cpp::remove_stopwords(tokens);

    return result == expected;
}

bool test_freq_dist() {

    std::vector<std::string> tokens = {
        "nlp",
        "cpp",
        "nlp",
        "ai",
        "cpp",
        "nlp"
    };

    auto result =
        nlp_cpp::freq_dist(tokens);

    return result["nlp"] == 3
        && result["cpp"] == 2
        && result["ai"] == 1;
}

bool test_stemmer() {

    return
        nlp_cpp::stem("running")
            == "run"

        &&

        nlp_cpp::stem("played")
            == "play"

        &&

        nlp_cpp::stem("cats")
            == "cat"

        &&

        nlp_cpp::stem("working")
            == "work";
}

int main() {

    if (test_word_tokenize()) {
        std::cout
            << "word_tokenize PASSED\n";
    } else {
        std::cout
            << "word_tokenize FAILED\n";
    }

    if (test_sent_tokenize()) {
        std::cout
            << "sent_tokenize PASSED\n";
    } else {
        std::cout
            << "sent_tokenize FAILED\n";
    }

    if (test_remove_stopwords()) {
        std::cout
            << "remove_stopwords PASSED\n";
    } else {
        std::cout
            << "remove_stopwords FAILED\n";
    }

    if (test_freq_dist()) {
        std::cout
            << "freq_dist PASSED\n";
    } else {
        std::cout
            << "freq_dist FAILED\n";
    }

    if (test_stemmer()) {
        std::cout
        << "stemmer PASSED\n";
    } else {
        std::cout
        << "stemmer FAILED\n";
    }

    return 0;
}