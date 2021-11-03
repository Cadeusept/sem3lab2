// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cmath>

#define REPORT_FILE_NAME "result.md"
#define NUMBER_OF_TESTS 1000

std::ofstream open_file(std::string filename);

size_t kbytes_to_elems(size_t size);

unsigned int straight_experiment(size_t size);

unsigned int reverse_experiment(size_t size);

unsigned int random_experiment(size_t size);

auto straight_investigation(
    size_t size_1, size_t size_2, std::ofstream &fout) -> void;

#endif // INCLUDE_EXAMPLE_HPP_
