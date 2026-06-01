#include "../include/nlp_cpp/pos_tagger.hpp"

#include <unordered_map>
#include <algorithm>
#include <cctype>

namespace nlp_cpp {

std::vector<
    std::pair<
        std::string,
        std::string
    >
> pos_tag(
    const std::vector<
        std::string
    >& tokens
) {

    std::unordered_map<
        std::string,
        std::string
    > dictionary = {

        {"i", "PRON"},
        {"you", "PRON"},
        {"he", "PRON"},
        {"she", "PRON"},
        {"they", "PRON"},
        {"we", "PRON"},

        {"is", "VERB"},
        {"are", "VERB"},
        {"was", "VERB"},
        {"love", "VERB"},
        {"run", "VERB"},
        {"eat", "VERB"},

        {"the", "DET"},
        {"a", "DET"},
        {"an", "DET"},

        {"in", "PREP"},
        {"on", "PREP"},
        {"at", "PREP"}
    };

    std::vector<
        std::pair<
            std::string,
            std::string
        >
    > result;

    for (const auto& token : tokens) {

        std::string tag;

        std::string lower_token =token;

        std::transform(
            lower_token.begin(),
            lower_token.end(),
            lower_token.begin(),
            ::tolower
        );

        auto it =
            dictionary.find(
                lower_token
            );

        if (it != dictionary.end()) {

            tag = it->second;
        }

        // suffix rules
        else if (
            token.length() >= 3 &&
            token.substr(
                token.length() - 3
            ) == "ing"
        ) {

            tag = "VERB";
        }

        else if (
            token.length() >= 2 &&
            token.substr(
                token.length() - 2
            ) == "ly"
        ) {

            tag = "ADV";
        }

        else if (
            token.length() >= 3 &&
            token.substr(
                token.length() - 3
            ) == "ful"
        ) {

            tag = "ADJ";
        }

        else {

            tag = "NOUN";
        }

        result.push_back(
            {
                token,
                tag
            }
        );
    }

    return result;
}

}