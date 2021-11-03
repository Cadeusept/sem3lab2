#include <investigation.hpp>

int main() {
  int* cache_size = new int[2];
  cache_size[0]=96; cache_size[1]=2048; //kBytes

  int* mem_test_sizes = new int[4];
  mem_test_sizes[0] = cache_size[0]/2;
  mem_test_sizes[1] = cache_size[1]/2;
  mem_test_sizes[2] = cache_size[1]-48;
  mem_test_sizes[3] = (cache_size[1]/2)*3;


  std::ofstream report_file;
  report_file.open(REPORT_FILE_NAME, std::ofstream::out);
  test_cpu(mem_test_sizes,report_file);
  report_file.close();
  return 0;
}