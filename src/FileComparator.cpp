//
// Created by tim on 04.04.19.
//

#include <cstring>
#include "FileComparator.h"
using namespace std::experimental;
std::uintmax_t FileComparator::fileSize(std::experimental::filesystem::path directory) {
  return std::experimental::filesystem::file_size(directory);
}
bool FileComparator::isFile(std::experimental::filesystem::path directory) {
  return std::experimental::filesystem::is_regular_file(directory);
}
bool FileComparator::isSecondFileExist(std::experimental::filesystem::path directory1,
                                       std::experimental::filesystem::path directory2) {
  return std::experimental::filesystem::exists(directory1) && std::experimental::filesystem::exists(directory2);
}
PathVector FileComparator::Compare() {
  PathVector resultVector;
  for (auto &firstDir : firstDirectoryList) {
    for (auto &secondDir : secondDirectoryList) {
      std::string firstDirResult = firstDir.string().erase(0, std::strlen(sourceDirectory));
      std::string secondDirResult = secondDir.string().erase(0, std::strlen(destinationDirectory));
      //cut path to compare two different directories
      if (firstDirResult == secondDirResult) {
        if ((isFile(firstDir) && isFile(secondDir)) && (fileSize(firstDir) != fileSize(secondDir))) {
          resultVector.push_back(firstDir);
        } else if (isSecondFileExist(firstDir, secondDir)) {
          resultVector.push_back(firstDir);
        }
      }
    }
  }
  return resultVector;
}
FileComparator::FileComparator(const char *sourceDirectory, const char *destinationDirectory) {
  this->sourceDirectory = sourceDirectory;
  this->destinationDirectory = destinationDirectory;
  auto pathReader = PathReader();
  this->firstDirectoryList = pathReader.FindSubdirectories(sourceDirectory); //vector for first directory(paths)
  this->secondDirectoryList = pathReader.FindSubdirectories(destinationDirectory);//vector for the second directory
}