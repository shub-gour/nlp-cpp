#include "../include/nlp_cpp/tokenizer.hpp"

#include <regex>
#include <cctype>

namespace nlp_cpp {

    std::string trim(const std::string& str) {

        size_t first =
            str.find_first_not_of(" ");

        size_t last =
            str.find_last_not_of(" ");

        return str.substr(
            first,
            (last - first + 1)
        );
    }

    std::vector<std::string> word_tokenize(
        const std::string& text
    ) {

        std::vector<std::string> tokens;

        std::string current_word;

        for (char c : text) {

            if (std::isalnum(c)) {

                current_word += c;
            }

            else {

                if (!current_word.empty()) {

                    tokens.push_back(
                    current_word
                    );

                    current_word.clear();
                }
            }
        }

        if (!current_word.empty()) {

            tokens.push_back(
            current_word
            );
        }

        return tokens;
    }

    std::vector<std::string> sent_tokenize(
        const std::string& text
    ) {

        std::vector<std::string> sentences;

        std::regex sentence_regex("[^.!?]+");

        auto begin =
            std::sregex_iterator(
                text.begin(),
                text.end(),
                sentence_regex
            );

        auto end =
            std::sregex_iterator();

        for (auto it = begin;
             it != end;
             ++it) {

            sentences.push_back(
                trim(it->str())
            );
        }

        return sentences;
    }

}