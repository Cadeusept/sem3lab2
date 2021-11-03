#include <investigation.hpp>

int main() {
  int* cache_size = new int[2];
  cache_size[0]=96;cache_size[1]=2048; //kBytes

  std::ofstream report_file=open_file(REPORT_FILE_NAME);
  straight_investigation(96,2048,report_file);
  return 0;
}