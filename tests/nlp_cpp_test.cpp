#include <iostream>
#include <vector>
#include <unordered_map>

#include "../include/nlp_cpp/tokenizer.hpp"
#include "../include/nlp_cpp/stopwords.hpp"
#include "../include/nlp_cpp/freqdist.hpp"
#include "../include/nlp_cpp/stemmer.hpp"
#include "../include/nlp_cpp/lemmatizer.hpp"
#include "../include/nlp_cpp/pos_tagger.hpp"
#include "../include/nlp_cpp/ner.hpp"

bool test_word_tokenize()
{

    std::string text =
        "Hello, world!";

    std::vector<std::string> expected = {
        "Hello",
        "world"};

    auto result =
        nlp_cpp::word_tokenize(text);

    return result == expected;
}

bool test_sent_tokenize()
{

    std::string text =
        "Hello world. I love NLP!";

    std::vector<std::string> expected = {
        "Hello world",
        "I love NLP"};

    auto result =
        nlp_cpp::sent_tokenize(text);

    return result == expected;
}

bool test_remove_stopwords()
{

    std::vector<std::string> tokens = {
        "I",
        "love",
        "NLP",
        "and",
        "machine",
        "learning"};

    std::vector<std::string> expected = {
        "love",
        "NLP",
        "machine",
        "learning"};

    auto result =
        nlp_cpp::remove_stopwords(tokens);

    return result == expected;
}

bool test_freq_dist()
{

    std::vector<std::string> tokens = {
        "nlp",
        "cpp",
        "nlp",
        "ai",
        "cpp",
        "nlp"};

    auto result =
        nlp_cpp::freq_dist(tokens);

    return result["nlp"] == 3 && result["cpp"] == 2 && result["ai"] == 1;
}

bool test_stemmer()
{

    return

        nlp_cpp::stem("caresses") == "caress"

        &&

        nlp_cpp::stem("ponies") == "poni"

        &&

        nlp_cpp::stem("cats") == "cat"

        &&

        nlp_cpp::stem("class") == "class"

        &&

        nlp_cpp::stem("running") == "run"

        &&

        nlp_cpp::stem("played") == "play"

        &&

        nlp_cpp::stem("hopping") == "hop"

        &&

        nlp_cpp::stem("filing") == "file";
}

bool test_lemmatizer()
{

    return nlp_cpp::lemmatize("studies") == "study"

           &&

           nlp_cpp::lemmatize("running") == "run"

           &&

           nlp_cpp::lemmatize("mice") == "mouse"

           &&

           nlp_cpp::lemmatize("children") == "child"

           &&

           nlp_cpp::lemmatize("better") == "good"

           &&

           nlp_cpp::lemmatize("cars") == "car";
}

bool test_pos_tagger()
{

    std::vector<std::string> words = {
        "I",
        "love",
        "coding",
        "quickly",
        "beautiful",
        "computer"};

    auto result =
        nlp_cpp::pos_tag(words);

    return

        result[0].second == "PRON"

        &&

        result[1].second == "VERB"

        &&

        result[2].second == "VERB"

        &&

        result[3].second == "ADV"

        &&

        result[4].second == "ADJ"

        &&

        result[5].second == "NOUN";
}

bool test_ner()
{

    std::vector<std::string> words = {
        "Elon",
        "Musk",
        "works",
        "at",
        "Tesla",
        "India",
        "coding"};

    auto result =
        nlp_cpp::ner(words);

    return

        result[0].second == "PERSON"

        &&

        result[1].second == "PERSON"

        &&

        result[2].second == "O"

        &&

        result[3].second == "O"

        &&

        result[4].second == "ORG"

        &&

        result[5].second == "LOCATION"

        &&

        result[6].second == "O";
}

int main()
{

    if (test_word_tokenize())
    {
        std::cout
            << "word_tokenize PASSED\n";
    }
    else
    {
        std::cout
            << "word_tokenize FAILED\n";
    }

    if (test_sent_tokenize())
    {
        std::cout
            << "sent_tokenize PASSED\n";
    }
    else
    {
        std::cout
            << "sent_tokenize FAILED\n";
    }

    if (test_remove_stopwords())
    {
        std::cout
            << "remove_stopwords PASSED\n";
    }
    else
    {
        std::cout
            << "remove_stopwords FAILED\n";
    }

    if (test_freq_dist())
    {
        std::cout
            << "freq_dist PASSED\n";
    }
    else
    {
        std::cout
            << "freq_dist FAILED\n";
    }

    if (test_stemmer())
    {
        std::cout
            << "stemmer PASSED\n";
    }
    else
    {
        std::cout
            << "stemmer FAILED\n";
    }

    if (test_lemmatizer())
    {
        std::cout
            << "lemmatizer PASSED\n";
    }
    else
    {
        std::cout
            << "lemmatizer FAILED\n";
    }

    if (test_pos_tagger())
    {
        std::cout
            << "pos_tagger PASSED\n";
    }
    else
    {
        std::cout
            << "pos_tagger FAILED\n";
    }

    if (test_ner())
    {
        std::cout
            << "ner PASSED\n";
    }
    else
    {
        std::cout
            << "ner FAILED\n";
    }

    return 0;
}