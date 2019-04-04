//
// Created by tim on 04.04.19.
//

#ifndef NPOWORLDTESTTASK_FILECOMPARATOR_H
#define NPOWORLDTESTTASK_FILECOMPARATOR_H
#include <vector>
#include <experimental/filesystem>
#include "PathReader.h"
using PathVector = std::vector<std::experimental::filesystem::path>;
class FileComparator {
 private:
  const char *sourceDirectory;
  const char *destinationDirectory;
  PathVector firstDirectoryList;
  PathVector secondDirectoryList;
  bool isFile(std::experimental::filesystem::path directory);
  bool isSecondFileExist(std::experimental::filesystem::path directory1,
                         std::experimental::filesystem::path directory2);
  std::uintmax_t fileSize(std::experimental::filesystem::path directory);
 public:
  FileComparator(const char *sourceDirectory, const char *destinationDirectory);
  PathVector Compare();
};

#endif //NPOWORLDTESTTASK_FILECOMPARATOR_H
