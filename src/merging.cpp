#include "assignment/merging.hpp"

#include <cassert>    // assert
#include <algorithm>  // copy

namespace assignment {

  void merge(std::vector<int>& arr, int start, int middle, int stop, std::vector<int>& buf) {
    assert(start >= 0 && start < arr.size() && stop >= start && stop < arr.size() && middle >= start && middle <= stop);

    int left_offset = start;
    int right_offset = middle + 1;

    int buf_offset = start;

    while (left_offset <= middle && right_offset <= stop) {
      if (arr[left_offset] > arr[right_offset]) {
        buf[buf_offset] = arr[right_offset++];

      } else {
        buf[buf_offset] = arr[left_offset++];

      }
      buf_offset += 1;
    }

    for (/* ... */; left_offset <= middle; left_offset++) {
      buf[buf_offset] = arr[left_offset];
      buf_offset += 1;
    }
    for (/* ... */; right_offset <= stop; right_offset++) {
      buf[buf_offset] = arr[right_offset];
      buf_offset += 1;
    }
    for (int i = 0; i <= stop; i++){
      arr[i] = buf[i];
    }
  }

}  // namespace assignment