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
  // TODO
  return vect;
}