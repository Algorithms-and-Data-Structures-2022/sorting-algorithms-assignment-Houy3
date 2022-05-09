#include "assignment/heap_sort.hpp"

#include <utility>  // swap
#include <cassert>  // assert

namespace assignment {

  void HeapSort::Sort(std::vector<int>& arr) const {

    BuildMaxHeap(arr);
    for (int index = static_cast<int>(arr.size()) - 1; index > 0; index--) {
      std::swap(arr[0], arr[index]);
      Heapify(arr, index, 0);
    }
  }

  void HeapSort::BuildMaxHeap(std::vector<int>& arr) {
    const int size = static_cast<int>(arr.size());
    for(int i = size/2-1; i>=0;i--) {
      Heapify(arr, size,i);
    }
  }

  void HeapSort::Heapify(std::vector<int>& arr, int heap_size, int index) {
    assert(heap_size >= 0 && heap_size <= arr.size() && index >= 0 && index < heap_size);

    for (int largest = index; largest < heap_size; /* ... */) {

      const int left_child = LeftChild(index);
      const int right_child = RightChild(index);
      if (left_child < heap_size && arr[left_child] > arr[largest]){
        largest = left_child;
      }
      if (right_child <heap_size && arr[right_child] >arr[largest]) {
        largest = right_child;
      }
      if (largest == index) {
        return;
      }
      std::swap(arr[index], arr[largest]);
      index = largest;
    }
  }

  int HeapSort::Parent(int index) {
    assert(index >= 0);
    return (index - 1) / 2;
  }

  int HeapSort::LeftChild(int index) {
    assert(index >= 0);
    return 2 * index + 1;
  }

  int HeapSort::RightChild(int index) {
    assert(index >= 0);
    return 2 * index + 2;
  }

}  // namespace assignment
