#include <iostream>
#include <vector>

#include "../include/nlp_cpp/tokenizer.hpp"
#include "../include/nlp_cpp/stopwords.hpp"
#include "../include/nlp_cpp/freqdist.hpp"
#include "../include/nlp_cpp/stemmer.hpp"
#include "../include/nlp_cpp/lemmatizer.hpp"
#include "../include/nlp_cpp/pos_tagger.hpp"
#include "../include/nlp_cpp/ner.hpp"

int main()
{

    std::cout
        << "=== TOKENIZER ===\n";

    std::string text =
        "Hello, world! I love NLP.";

    auto tokens =
        nlp_cpp::word_tokenize(text);

    for (const auto &token : tokens)
    {
        std::cout
            << token
            << std::endl;
    }

    std::cout
        << "\n=== STOPWORDS ===\n";

    std::string sentence =
        "I love NLP and machine learning";

    auto sentence_tokens =
        nlp_cpp::word_tokenize(sentence);

    auto filtered_tokens =
        nlp_cpp::remove_stopwords(
            sentence_tokens);

    for (const auto &word :
         filtered_tokens)
    {

        std::cout
            << word
            << std::endl;
    }

    std::cout
        << "\n=== STEMMER ===\n";

    std::vector<std::string> words = {
        "running",
        "played",
        "cats",
        "working"};

    for (const auto &word : words)
    {

        std::cout
            << word
            << " -> "
            << nlp_cpp::stem(word)
            << std::endl;
    }

    std::cout
        << "\n=== FREQUENCY ===\n";

    std::string freq_text =
        "NLP cpp NLP AI cpp NLP";

    auto freq_tokens =
        nlp_cpp::word_tokenize(freq_text);

    auto frequencies =
        nlp_cpp::freq_dist(
            freq_tokens);

    for (const auto &pair :
         frequencies)
    {

        std::cout
            << pair.first
            << " -> "
            << pair.second
            << std::endl;
    }

    std::cout
        << "\n=== LEMMATIZER ===\n";

    std::vector<std::string> lemma_words = {
        "studies",
        "running",
        "mice",
        "children",
        "better",
        "cars"};

    for (const auto &word : lemma_words)
    {

        std::cout
            << word
            << " -> "
            << nlp_cpp::lemmatize(word)
            << std::endl;
    }

    std::cout
        << "\n=== POS TAGGER ===\n";

    std::vector<std::string> pos_words = {
        "I",
        "love",
        "coding",
        "quickly",
        "beautiful",
        "computer"};

    auto tagged =
        nlp_cpp::pos_tag(pos_words);

    for (const auto &pair :
         tagged)
    {

        std::cout
            << pair.first
            << " -> "
            << pair.second
            << std::endl;
    }

    std::cout
        << "\n=== NER ===\n";

    std::vector<std::string> ner_words = {
        "Elon",
        "Musk",
        "works",
        "at",
        "Tesla",
        "India"};

    auto ner_result =
        nlp_cpp::ner(ner_words);

    for (const auto &pair :
         ner_result)
    {

        std::cout
            << pair.first
            << " -> "
            << pair.second
            << std::endl;
    }

    return 0;
}