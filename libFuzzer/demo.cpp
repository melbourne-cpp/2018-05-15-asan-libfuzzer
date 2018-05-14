#include <iostream>
#include <vector>

bool decode(const std::vector<uint8_t> &data) {
  return data.size() >= 3 &&
      data[0] == 'F' &&
      data[1] == 'U' &&
      data[2] == 'Z' &&
      data[3] == 'Z';
}

int main()
{
    std::cout << (decode({ 'F', 'U', 'Z', 'Z', 1, 2, 3 })   ? "true" : "false") << std::endl;
    std::cout << (decode({ 'F', 'U', 'Z', 'Z', 4, 5, 6 })   ? "true" : "false") << std::endl;
    std::cout << (decode({ 'F', 'V', '2', '2', 7, 8, 9 })   ? "true" : "false") << std::endl;
    return 0;
}


extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  decode(std::vector<uint8_t>(Data, Data+Size));
  return 0;
}
