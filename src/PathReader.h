//
// Created by tim on 02.04.19.
//

#ifndef NPOWORLDTESTTASK_PATHREADER_H
#define NPOWORLDTESTTASK_PATHREADER_H
#include <experimental/filesystem>
#include <iostream>
#include <vector>
namespace filesystem = std::experimental::filesystem;
class PathReader {
 public:
  PathReader() = default;
  ~PathReader() = default;
  std::vector<filesystem::path> FindSubdirectories(std::string path);
};

#endif //NPOWORLDTESTTASK_PATHREADER_H
