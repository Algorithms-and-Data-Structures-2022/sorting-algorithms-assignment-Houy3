#include "assignment/insertion_sort.hpp"

#include <utility>  // move, swap

#include "assignment/partitioning.hpp"  // middle_of

namespace assignment {

  int linear_search(const std::vector<int>& arr, int index) {

    // итерация всех предыдущих элементов [0, index - 1] (они находятся в отсортированном порядке)
    for (int curr_pos = 0; curr_pos < index; curr_pos++) {
      if (arr[curr_pos] >= arr[index]) {
        return curr_pos;
      }
      // если текущий элемент меньше или равен вставляемому, позиция для вставки найдена ...
    }

    return index;
  }

  int binary_search(const std::vector<int>& arr, int index) {

    int start = 0;
    int stop = index;
    int middle = middle_of(start, stop);

    while (start <= stop) {

      if (arr[index] == arr[middle]) {
        return middle;
      }
      if (arr[index] < arr[middle]) {
        stop = middle - 1;
      } else {
        start = middle + 1;
      }
      middle = middle_of(start, stop);
    }

    return start;
  }

  void InsertionSort::Sort(std::vector<int>& arr) const {

    for (int index = 1; index < static_cast<int>(arr.size()); index++) {

      const int ins_index = searcher_(arr, index);
      if (ins_index != index) {
        int elem_to_insert = arr[index];
        for (int i = index - 1; i >= ins_index; --i) {
          arr[i + 1] = arr[i];
        }
        std::swap(arr[ins_index], elem_to_insert);
      }

    }
  }

  InsertionSort::InsertionSort(Searcher searcher) : searcher_{std::move(searcher)} {}

}  // namespace assignment