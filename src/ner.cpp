#include "../include/nlp_cpp/ner.hpp"

#include <unordered_map>
#include <cctype>

namespace nlp_cpp {

std::vector<
    std::pair<
        std::string,
        std::string
    >
> ner(
    const std::vector<
        std::string
    >& tokens
) {

    std::unordered_map<
        std::string,
        std::string
    > dictionary = {

        {"Tesla", "ORG"},
        {"Google", "ORG"},
        {"Microsoft", "ORG"},

        {"India", "LOCATION"},
        {"USA", "LOCATION"},
        {"London", "LOCATION"},

        {"Elon", "PERSON"},
        {"Musk", "PERSON"}
    };

    std::vector<
        std::pair<
            std::string,
            std::string
        >
    > result;

    for (const auto& token :
         tokens) {

        std::string tag = "O";

        auto it =
            dictionary.find(token);

        if (it != dictionary.end()) {

            tag = it->second;
        }

        // Capitalized unknown
        else if (
            !token.empty()
            &&
            std::isupper(
                token[0]
            )
        ) {

            tag = "PERSON";
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