#include <investigation.hpp>

int main() {
  int* cache_size = new int[2];
  cache_size[0]=96;cache_size[1]=2048; //mb
  single_investigation(kbytes_to_elems(48));


  return 0;
}