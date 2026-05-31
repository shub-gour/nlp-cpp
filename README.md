# NLP-CPP

A high-performance NLP library built in C++ inspired by core Natural Language Toolkit (NLTK) functionality.

## Overview

NLP-CPP is a modular NLP library designed to provide fast and efficient classical NLP operations in modern C++.

The project focuses on:

* High-performance text processing
* Modular C++ architecture
* Clean and testable code
* Future Python interoperability using pybind11
* Benchmarking against NLTK

## Features Implemented

### Tokenizer

* Word Tokenization
* Sentence Tokenization

Examples:

Input:

```text
Hello, world! I love NLP.
```

Word Tokenization:

```text
Hello
world
I
love
NLP
```

Sentence Tokenization:

```text
Hello world
I love NLP
```

### Stopword Removal

Input:

```text
I love NLP and machine learning
```

Output:

```text
love
NLP
machine
learning
```

### Frequency Distribution

Counts word occurrences.

Example:

```text
nlp -> 3
cpp -> 2
ai -> 1
```

### Stemmer

Basic stemming support:

```text
running -> run
played -> play
cats -> cat
working -> work
```

## Project Structure

```text
nlp-cpp/
│
├── include/
├── src/
├── tests/
├── benchmarks/
├── docs/
├── CMakeLists.txt
└── README.md
```

## Build Instructions

Clone repository:

```bash
git clone <repo-url>
cd nlp-cpp
```

Build:

```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

Run:

```bash
.\app.exe
```

Run tests:

```bash
.\test_app.exe
```

## Tech Stack

* C++17
* CMake
* MinGW g++
* Regex
* STL (`vector`, `unordered_map`, `unordered_set`)

## Current Modules

* Tokenizer
* Stopword Removal
* Frequency Distribution
* Stemmer

## Future Roadmap

* Porter Stemmer (advanced)
* Lemmatizer
* POS Tagger
* Named Entity Recognition
* Python bindings with pybind11
* Benchmarks vs NLTK
* Packaging and open-source release

## Status

Currently under active development.
