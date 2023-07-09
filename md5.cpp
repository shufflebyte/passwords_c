#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/md5.h>

std::string md5(const std::string &str){
  unsigned char hash[MD5_DIGEST_LENGTH];

  MD5_CTX md5;
  MD5_Init(&md5);
  MD5_Update(&md5, str.c_str(), str.size());
  MD5_Final(hash, &md5);

  std::stringstream ss;

  for(int i = 0; i < MD5_DIGEST_LENGTH; i++){
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>( hash[i] );
  }
  return ss.str();
}

int main() {
  std::cout << md5("password") << '\n';
  return 0;
}
// a69f0efcca0116a76921947f135ccdac = 32 Buchstaben und Zahlen_basis 16 = 32*4 basis 2 = 128 bit
// a = 10 basis 10 = 1010 basis 2