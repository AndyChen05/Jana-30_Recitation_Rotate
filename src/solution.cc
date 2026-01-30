#include "solution.hpp"

#include "vector"

std::vector<int> RotateRight(const std::vector<int>& vect,
                             unsigned int no_rotations) {
  int temp = 0;
  std::vector<int> new_vector(vect.size());
  for (unsigned int i = 0; i < vect.size(); ++i) {
    temp = (i + no_rotations) % vect.size();
    new_vector[temp] = vect[i];
  }
  return new_vector;
}

std::vector<int> RotateChunks(const std::vector<int>& vect,
                              unsigned int chunk_size,
                              unsigned int no_rotations) {
  std::vector<int> new_vector(vect.size());
  for (unsigned int i = 0; i < vect.size(); i += chunk_size) {
    std::vector<int> chunk(chunk_size);
    for (unsigned int j = 0; j < chunk_size; j++) {
      chunk[j] = vect[(i + j) % vect.size()];
      RotateRight(chunk, no_rotations % chunk_size);
    }
    for (unsigned int j = 0; j < chunk_size; j++) {
      new_vector[(i + j) % vect.size()] = chunk[j];
    }
  }
  return new_vector;
}