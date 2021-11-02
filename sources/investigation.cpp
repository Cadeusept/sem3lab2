// Copyright 2021 Your Name <your_email>

#include <investigation.hpp>
#include <stdexcept>

// auto example() -> void {
//  throw std::runtime_error("not implemented");
//}

size_t kbytes_to_elems(size_t size){
  return size*1024/4; //kB
}

unsigned int straight_experiment(size_t size){
  [[maybe_unused]] int k = 0;
  [[maybe_unused]] int* arr1 = new int[size];
  for (int i = 0; (size_t)i < size; i += 16) // прогрев
    k = arr1[i];
  unsigned int start_time=clock();
  for (int i = 0; (size_t)i < size; i += 16) // чтение
    k = arr1[i];
  unsigned int end_time=clock();
  return end_time-start_time;
}

unsigned int reverse_experiment(size_t size){
  [[maybe_unused]] int k = 0;
  [[maybe_unused]] int* arr1 = new int[size];
  for (int i = (int)size; i > 0; i -= 16) // прогрев
    k = arr1[i];
  unsigned int start_time=clock();
  for (int i = (int)size; i > 0; i -= 16) // чтение
    k = arr1[i];
  unsigned int end_time=clock();
  return end_time-start_time;
}

unsigned int random_experiment(size_t size){
  [[maybe_unused]] int k = 0;
  [[maybe_unused]] int* arr1 = new int[size];

  srand(time(0));
  [[maybe_unused]] int* num_array=new int[size/16];
  int j=0;
  for (int i = 0; (size_t)i < size; i += 16) {  // создание случайного прохода
    num_array[j] = i;
    j++;
  }
  std::random_shuffle(num_array,num_array+j);

  for (int i = 0; i <= j; ++i) // прогрев
    k = arr1[num_array[i]];
  unsigned int start_time=clock();
  for (int i = 0; i <= j; ++i) // чтение
    k = arr1[num_array[i]];
  unsigned int end_time=clock();
  return end_time-start_time;
}

auto single_investigation(size_t size) -> void {
  unsigned int straight_time = straight_experiment(size);
  unsigned int reverse_time = reverse_experiment(size);
  unsigned int random_time = random_experiment(size);

}
