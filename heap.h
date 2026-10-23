#ifndef HEAP_H
#define HEAP_H
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T, typename PComparator = std::less<T>> class Heap {
public:
  /**
   * @brief Construct a new Heap object
   *
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m = 2, PComparator c = PComparator());

  /**
   * @brief Destroy the Heap object
   *
   */
  ~Heap();

  /**
   * @brief Push an item to the heap
   *
   * @param item item to heap
   */
  void push(const T &item);

  /**
   * @brief Returns the top (priority) item
   *
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const &top() const;

  /**
   * @brief Remove the top priority item
   *
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   *
   */
  bool empty() const;

  /**
   * @brief Returns size of the heap
   *
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void heapifyUp(size_t idx);
  void heapifyDown(size_t idx);

  std::vector<T> data_;
  int m_;
  PComparator comp_;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : data_(), m_(m), comp_(c) {
  if (m_ < 2)
    m_ = 2;
}

template <typename T, typename PComparator> Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data_.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item) {
  data_.push_back(item);
  heapifyUp(data_.size() - 1);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t idx) {
  if (idx == 0)
    return;
  size_t parent = (idx - 1) / m_;
  if (comp_(data_[idx], data_[parent])) {
    T tmp = data_[idx];
    data_[idx] = data_[parent];
    data_[parent] = tmp;
    heapifyUp(parent);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t idx) {
  size_t n = data_.size();
  size_t best = idx;
  for (int k = 1; k <= m_; k++) {
    size_t c = idx * m_ + k;
    if (c < n && comp_(data_[c], data_[best]))
      best = c;
  }
  if (best != idx) {
    T tmp = data_[idx];
    data_[idx] = data_[best];
    data_[best] = tmp;
    heapifyDown(best);
  }
}

// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const {
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty()) {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator> void Heap<T, PComparator>::pop() {
  if (empty()) {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  data_[0] = data_.back();
  data_.pop_back();
  if (!data_.empty())
    heapifyDown(0);
}

#endif
