#include "PathReader.h"
//
// Created by tim on 02.04.19.
//
std::vector<filesystem::path> PathReader::FindSubdirectories(std::string path) {
  std::vector<filesystem::path> paths;
  for (auto &p : filesystem::recursive_directory_iterator(path)) {
    paths.push_back(p.path());
  }
  return paths;
}
//-lstdc++fs