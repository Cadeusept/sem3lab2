// Copyright 2021 Your Name <your_email>

#include <investigation.hpp>

size_t kbytes_to_elems(size_t size){
  return size*1024/4; //kB
}

unsigned int straight_experiment(size_t size){
  [[maybe_unused]] int k = 0;
  [[maybe_unused]] int* arr1 = new int[size];
  unsigned int sum=0;
  for (int i = 0; (size_t)i < size; i += 16) // прогрев
    k = arr1[i];

  for (int j=0; j<NUMBER_OF_TESTS; ++j) {
    unsigned int start_time = clock();
    for (int i = 0; (size_t)i < size; i += 16)  // чтение
      k = arr1[i];
    unsigned int end_time = clock();
    sum += end_time - start_time;
  }

  return std::round(sum/NUMBER_OF_TESTS);
}

unsigned int reverse_experiment(size_t size){
  [[maybe_unused]] int k = 0;
  [[maybe_unused]] int* arr1 = new int[size];
  unsigned int sum=0;
  for (int i = (int)size; i > 0; i -= 16) // прогрев
    k = arr1[i];

  for (int j=0; j<NUMBER_OF_TESTS; ++j) {
    unsigned int start_time = clock();
    for (int i = (int)size; i > 0; i -= 16)  // чтение
      k = arr1[i];
    unsigned int end_time = clock();
    sum += end_time - start_time;
  }

  return std::round(sum/NUMBER_OF_TESTS);
}

unsigned int random_experiment(size_t size){
  [[maybe_unused]] int k = 0;
  [[maybe_unused]] int* arr1 = new int[size];
  unsigned int sum=0;

  srand(time(0));
  [[maybe_unused]] int* num_array=new int[size/16];
  int kol=0;
  for (int i = 0; (size_t)i < size; i += 16) {  // создание случайного прохода
    num_array[kol] = i;
    kol++;
  }
  std::random_shuffle(num_array,num_array+kol);

  for (int i = 0; i <= kol; ++i) // прогрев
    k = arr1[num_array[i]];
  for (int j=0; j<NUMBER_OF_TESTS; ++j) {
    unsigned int start_time = clock();
    for (int i = 0; i <= kol; ++i)  // чтение
      k = arr1[num_array[i]];
    unsigned int end_time = clock();
    sum += end_time - start_time;
  }

  return std::round(sum/NUMBER_OF_TESTS);
}


auto straight_investigation(int* sizes,  std::ofstream &fout) -> void {
  unsigned int time;
  print_header("straight", fout);

  for (int i = 1; i <= 4; ++i) {
    time = straight_experiment(kbytes_to_elems(sizes[i-1]));
    print_experiment_data(i, sizes[i-1], time, fout);
  }

  print_footer(fout);
}

auto reverse_investigation(int* sizes,  std::ofstream &fout) -> void {
  unsigned int time;
  print_header("reverse", fout);

  for (int i = 1; i <= 4; ++i) {
    time = reverse_experiment(kbytes_to_elems(sizes[i-1]));
    print_experiment_data(i, sizes[i-1], time, fout);
  }

  print_footer(fout);
}

auto random_investigation(int* sizes,  std::ofstream &fout) -> void {
  unsigned int time;
  print_header("random", fout);

  for (int i = 1; i <= 4; ++i) {
    time = random_experiment(kbytes_to_elems(sizes[i-1]));
    print_experiment_data(i, sizes[i-1], time, fout);
  }

  print_footer(fout);
}

auto test_cpu(int* sizes,  std::ofstream &fout) -> void {
  straight_investigation(sizes, fout);
  reverse_investigation(sizes, fout);
  random_investigation(sizes, fout);
}

void print_header(std::string travel_var, std::ofstream &fout) {
  fout << "<span style=\"color: green;\">investigation:</span>  " << std::endl;
  fout << "&ensp;travel_variant: \"" << travel_var << "\"  " << std::endl <<
          "&ensp;experiments:  " <<std::endl;
}

void print_experiment_data(unsigned int number, size_t size,
                           unsigned int time, std::ostream &fout) {
  fout << "&ensp;- experiment:  " << std::endl <<
          "&ensp;&ensp;&ensp;number: " << number << "  " << std::endl <<
          "&ensp;&ensp;&ensp;input_data:  " << std::endl <<
          "&ensp;&ensp;&ensp;&ensp;buffer_size: \"" << size << "kB\"  " << std::endl <<
          "&ensp;&ensp;&ensp;results:  " << std::endl <<
          "&ensp;&ensp;&ensp;&ensp;duration: \"" << time << "ns\"  " << std::endl;
}

void print_footer(std::ofstream &fout) {
  fout << "  " << std::endl;
}
