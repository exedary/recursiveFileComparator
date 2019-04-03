#include <iostream>
#include <fstream>
#include <cstring>
#include "PathReader.h"
int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << "need path" << std::endl;
    exit(0);
  }
  char *sourceDirectory = argv[1];
  char *destinationDirectory = argv[2];
  char *resultDirectory = argv[3];
  char *rFileName = "/result.txt";
  std::remove(std::strcat(resultDirectory, rFileName));
  auto pathReader = PathReader();
  auto sourceDirectoryList = pathReader.FindSubdirectories(sourceDirectory); //vector for first directory(paths)
  auto secondDirectoryList = pathReader.FindSubdirectories(destinationDirectory); //vector for the second directory
  std::ofstream results(resultDirectory);
  for (auto &firstdir : sourceDirectoryList) {
    for (auto &secondir : secondDirectoryList) {
      // compare files with similar names
      if (std::experimental::filesystem::is_regular_file(firstdir)
          && std::experimental::filesystem::is_regular_file(secondir)) {
        if (firstdir.filename() == secondir.filename()
            && std::experimental::filesystem::file_size(firstdir) == std::experimental::filesystem::file_size(secondir))
          results << firstdir << std::endl;
      }
    }
  }

  return 0;
}