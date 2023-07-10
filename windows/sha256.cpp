/*
Usage: .\sha256.exe abc
Kompilieren mit MSYS2 MinGW64: g++ .\sha256.cpp -o .\sha256.exe -lcrypto
openssl ist in mingw dabei, habe libSLL nicht gebraucht zum kompilieren...
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

std::string sha256(const std::string str)
{
  unsigned char hash[SHA256_DIGEST_LENGTH];

  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, str.c_str(), str.size());
  SHA256_Final(hash, &sha256);

  std::stringstream ss;

  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
  {
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
  }
  return ss.str();
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Du musst deinen String angeben, den du hashen moechtest." << std::endl;
    std::cerr << "Beispiel: .\\sha256.exe abc" << std::endl;
    std::cerr << "Fuehrt zur Ausgabe: ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
    return 1;
  }
  std::cout << sha256(argv[1]) << '\n';
  return 0;
}