//
// Created by tim on 02.04.19.
//

#include "FilePathReader.h"
std::vector<std::string> FilePathReader::FindFilePath(std::vector<std::experimental::filesystem::path> *Directories) {
  std::vector<std::string> FilePath;
  for (auto &p : *Directories) {
    FilePath.push_back(p.filename());
  }
  return FilePath;
}