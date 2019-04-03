//
// Created by tim on 02.04.19.
//

#ifndef NPOWORLDTESTTASK_FILEPATHREADER_H
#define NPOWORLDTESTTASK_FILEPATHREADER_H
#include <vector>
#include <string>
#include <experimental/filesystem>
namespace filesystem = std::experimental::filesystem;
class FilePathReader {
  public:
  FilePathReader()= default;
  ~FilePathReader()= default;
  std::vector<std::string> FindFilePath(std::vector<filesystem::path> *Directories);
};

#endif //NPOWORLDTESTTASK_FILEPATHREADER_H
