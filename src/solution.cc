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
  std::vector<int> first_half(chunk_size);
  std::vector<int> second_half(vect.size() - chunk_size);
  for (unsigned int i = 0; i < chunk_size; ++i) {
    first_half[i] = vect[i];
  }
  for (unsigned int i = chunk_size; i < vect.size(); ++i) {
    second_half[i - chunk_size] = vect[i];
  }
  std::vector<int> rotated_first_half = RotateRight(first_half, no_rotations);
  std::vector<int> rotated_second_half = RotateRight(second_half, no_rotations);
  std::vector<int> result(vect.size());

  for (unsigned int i = 0; i < rotated_first_half.size(); ++i) {
    result[i] = rotated_first_half[i];
  }
  for (unsigned int i = 0; i < rotated_second_half.size(); ++i) {
    result[rotated_first_half.size() + i] = rotated_second_half[i];
  }
  return result;
}