cmake_minimum_required(VERSION 3.10)

project(nlp_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(app
    src/main.cpp
    src/tokenizer.cpp
    src/stopwords.cpp
    src/freqdist.cpp
    src/stemmer.cpp
)

add_executable(test_app
    tests/nlp_cpp_test.cpp
    src/tokenizer.cpp
    src/stopwords.cpp
    src/freqdist.cpp
    src/stemmer.cpp
)