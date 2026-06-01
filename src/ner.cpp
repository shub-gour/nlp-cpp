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
        {"New", "LOCATION"},
        {"York", "LOCATION"},
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
    > temp_result;

    // -------------------
    // First pass
    // -------------------

    for (const auto& token :
         tokens) {

        std::string tag = "O";

        auto it =
            dictionary.find(token);

        if (it != dictionary.end()) {

            tag = it->second;
        }

        else if (
            !token.empty()
            &&
            std::isupper(
                token[0]
            )
        ) {

            tag = "PERSON";
        }

        temp_result.push_back(
            {
                token,
                tag
            }
        );
    }

    // -------------------
    // Merge entities
    // -------------------

    std::vector<
        std::pair<
            std::string,
            std::string
        >
    > result;

    for (size_t i = 0;
         i < temp_result.size();
         ++i) {

        std::string entity =
            temp_result[i].first;

        std::string tag =
            temp_result[i].second;

        while (
            i + 1 <
            temp_result.size()

            &&

            temp_result[i + 1]
                .second
            ==
            tag

            &&

            tag != "O"
        ) {

            entity +=
                " "
                +
                temp_result[i + 1]
                    .first;

            ++i;
        }

        result.push_back(
            {
                entity,
                tag
            }
        );
    }

    return result;
}

}