#include "assignment/merge_sort.hpp"

#include "assignment/partitioning.hpp"  // middle_of
#include "assignment/merging.hpp"       // merge

namespace assignment {

  void MergeSort::Sort(std::vector<int>& arr) const {
    std::vector<int> buf(arr.size());
    merge_sort(arr, 0, arr.size()-1, buf);
  }

  void MergeSort::merge_sort(std::vector<int>& arr, int start, int stop, std::vector<int>& buf) const {
    if (start >= stop) {
      return;
    }

    const int middle = middle_of(start, stop);
    merge_sort(arr,start, middle, buf);
    merge_sort(arr, middle+1, stop, buf);
    merge(arr, start, middle, stop, buf);
  }

}  // namespace assignment
