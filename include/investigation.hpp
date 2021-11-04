//Copyright 2021 Matthew abobus1488822@yandex.ru

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cmath>
#include <stdexcept>

#define REPORT_FILE_NAME OUTPT_DIR"result.md"
#define NUMBER_OF_TESTS 1000

size_t kbytes_to_elems(size_t size);

unsigned int straight_experiment(size_t size);

unsigned int reverse_experiment(size_t size);

unsigned int random_experiment(size_t size);

auto straight_investigation(int* sizes,  std::ofstream &fout) -> void;

auto reverse_investigation(int* sizes,  std::ofstream &fout) -> void;

auto random_investigation(int* sizes,  std::ofstream &fout) -> void;

auto test_cpu(int* sizes,  std::ofstream &fout) -> void;

void print_header(std::string travel_var, std::ofstream &fout);

void print_experiment_data(unsigned int number, size_t size, unsigned int time, std::ostream &fout);

void print_footer(std::ofstream &fout);

#endif // INCLUDE_EXAMPLE_HPP_
