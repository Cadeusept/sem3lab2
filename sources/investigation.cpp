// Copyright 2021 Your Name <your_email>

#include <investigation.hpp>
#include <stdexcept>

std::ofstream open_file(std::string filename) {
  std::ofstream fout;
  fout.open(filename,std::ofstream::out);
  return fout;
}

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


auto straight_investigation(
    size_t size_1, size_t size_2, std::ofstream &fout) -> void {
  unsigned int straight_time;
  fout << "<font color=\"green\">investigation:</font>" << std::endl;
  fout << "\ttravel_variant: \"straight\"\n"
          "\texperiments:" <<std::endl;

  straight_time = straight_experiment(size_1);
  fout << "\t- experiment:\n"
          "\t\tnumber: 1\n"
          "\t\tinput_data:\n"
          "\t\t\tbuffer_size: \"" << size_1 << "kB\"\n"
          "\t\tresults:\n"
          "\t\t\tduration: \"" << straight_time << "ns\"" <<std::endl;

  straight_time = straight_experiment(size_2);
  fout << "\t- experiment:\n"
          "\t\tnumber: 1\n"
          "\t\tinput_data:\n"
          "\t\t\tbuffer_size: \"" << size_2 << "kB\"\n"
          "\t\tresults:\n"
          "\t\t\tduration: \"" << straight_time << "ns\"" <<std::endl;


  //unsigned int reverse_time = reverse_experiment(size);
  //unsigned int random_time = random_experiment(size);

}
