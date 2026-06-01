cmake_minimum_required(VERSION 3.10)

project(nlp_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Main demo app
add_executable(app
    src/main.cpp
    src/tokenizer.cpp
    src/stopwords.cpp
    src/freqdist.cpp
    src/stemmer.cpp
    src/lemmatizer.cpp
    src/pos_tagger.cpp
    src/ner.cpp
)

# Tests
add_executable(test_app
    tests/nlp_cpp_test.cpp
    src/tokenizer.cpp
    src/stopwords.cpp
    src/freqdist.cpp
    src/stemmer.cpp
    src/lemmatizer.cpp
    src/pos_tagger.cpp
    src/ner.cpp
)

# Benchmark
add_executable(benchmark_tokenizer
    benchmarks/benchmark_tokenizer.cpp
    src/tokenizer.cpp
)

set(PYBIND11_FINDPYTHON ON)

find_package(Python REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

pybind11_add_module(nlp_cpp
    src/bindings.cpp
    src/tokenizer.cpp
    src/stopwords.cpp
    src/freqdist.cpp
    src/stemmer.cpp
    src/lemmatizer.cpp
    src/pos_tagger.cpp
    src/ner.cpp
)