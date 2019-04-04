#include <iostream>
#include <fstream>
#include <cstring>
#include "PathReader.h"
#include "FileComparator.h"
int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << "need path" << std::endl;
    exit(0);
  }
  char *sourceDirectory = argv[1];
  char *destinationDirectory = argv[2];
  char *resultDirectory = argv[3];
  char *rFileName = "/result.txt";
  //std::remove(std::strcat(resultDirectory, rFileName));
  auto fileComparator = FileComparator(sourceDirectory, destinationDirectory);
  auto resultDirList = fileComparator.Compare();
  std::ofstream results(std::strcat(resultDirectory, rFileName));
  for (auto &dir : resultDirList) {
    results << dir << std::endl;
  }
  return 0;
}