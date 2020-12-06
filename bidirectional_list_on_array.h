#ifndef KR2_GR1_KHOMYAKOVA_LILIYA__BIDIRECTIONAL_LIST_ON_ARRAY_H_
#define KR2_GR1_KHOMYAKOVA_LILIYA__BIDIRECTIONAL_LIST_ON_ARRAY_H_
#include <iostream>
#include <vector>
namespace containers {
template<typename T>
class BiDirectionalListOnArray {
 public:
  BiDirectionalListOnArray();
  ~BiDirectionalListOnArray() {
    delete[] data_;
  }
  BiDirectionalListOnArray(std::initializer_list<T> l);
  BiDirectionalListOnArray(BiDirectionalListOnArray<T> &);
  BiDirectionalListOnArray &operator=(BiDirectionalListOnArray<T> &);
  BiDirectionalListOnArray &operator=(BiDirectionalListOnArray<T> &&);
  BiDirectionalListOnArray(BiDirectionalListOnArray<T> &&) noexcept;
  void InsertBefore(size_t index, const T &value);
  void Erase(size_t index);
  std::vector<int> FindAll(const T &value);
  void PushFront(T &&value);
  void PushBack(T &&value);
  int Find(const T &value);
  void PushFront(const T &value);
  void PushBack(const T &value);
  int Size() const;
  bool IsEmpty() const;
  std::vector<T> ToVector() const;
  T PopFront(){
    if (size_==0){
      throw std::invalid_argument(" ");
    }
    T val=data_[0];
    for (int i=1; i <size_; ++i){
      data_[i-1]=data_[i];
    }
    size_--;
    return val;
  }
  T PopBack(){
    if (size_==0){
      throw std::invalid_argument(" ");
    }
    size_--;
    return data_[size_-1];
  }
  void InsertAfter(size_t index, const T&value);
  T* operator[](int index) const {
    if (index + 1 > size_ || index < 0) throw std::invalid_argument(" ");
    return data_+index;
  }
  T *Front() const {
    if (size_ == 0) throw std::invalid_argument(" ");
    return data_;
  }
  T *Back() const {
    if (size_ == 0) throw std::invalid_argument(" ");
    return (data_+size_-1);
  }
  void InsertBefore(size_t index, T &&value) {
    InsertBefore(index, value);
  }

  void InsertAfter(size_t index, T &&value) {
    InsertAfter(index, value);
  }
  bool operator==(BiDirectionalListOnArray<T> &a) const {
    if (size_ != a.size_) return false;
    for (int i = 0; i < size_; ++i) {
      if (data_[i] != a.data_[i]) return false;
    }
    return true;
  }
  bool operator!=(BiDirectionalListOnArray<T> &a) const {
    return !(*this == a);
  }
 private:
  T *data_;
  size_t size_ = 0;
  size_t capacity_;
  static const size_t MIN_CAPACITY = 10;
  static const size_t GROWTH_FACTOR = 2;
};
template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray() {
  size_ = 0;
  capacity_ = MIN_CAPACITY;
  data_ = new T[capacity_];
}
template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(BiDirectionalListOnArray<T> &a) {
  delete data_;
  size_ = a.size_;
  capacity_ = a.capacity_;
  data_ = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    data_[i] = a.data_[i];
  }
}
template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(std::initializer_list<T> l) {
  size_ = l.size();
  if (size_ > MIN_CAPACITY) {
    capacity_ = size_;
  } else
    capacity_ = MIN_CAPACITY;
  data_ = new T[capacity_];
}
template<typename T>
int BiDirectionalListOnArray<T>::Size() const {
  return size_;
}
template<typename T>
bool BiDirectionalListOnArray<T>::IsEmpty() const {
  return (size_ == 0);
}
template<typename T>
std::vector<T> BiDirectionalListOnArray<T>::ToVector() const {
  std::vector<T> res;
  for (auto x : data_) {
    res.push_back(x);
  }
  return res;
}
template<typename T>
BiDirectionalListOnArray<T> &BiDirectionalListOnArray<T>::operator=(BiDirectionalListOnArray<T> &a) {
  delete data_;
  size_ = a.size_;
  capacity_ = a.capacity_;
  data_ = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    data_[i] = a.data_[i];
  }
  return *this;
}
template<typename T>
BiDirectionalListOnArray<T>::BiDirectionalListOnArray(BiDirectionalListOnArray<T> &&a) noexcept {
  delete data_;
  size_ = a.size_;
  capacity_ = a.capacity_;
  data_ = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    data_[i] = a.data_[i];
  }
  delete[] a.data_;
  a.size_ = 0;
}
template<typename T>
BiDirectionalListOnArray<T> &BiDirectionalListOnArray<T>::operator=(BiDirectionalListOnArray<T> &&a) {
  if (this == &a) return *this;
  delete data_;
  size_ = a.size_;
  capacity_ = a.capacity_;
  data_ = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    data_[i] = a.data_[i];
  }
  delete[] a.data_;
  a.size_ = 0;
  return *this;
}
template<typename T>
void BiDirectionalListOnArray<T>::PushFront(const T &value) {
  if (size_ == 0) {
    data_[0] = value;
    size_++;
    return;
  }
  if (size_ == MIN_CAPACITY)
    capacity_ = capacity_ * GROWTH_FACTOR;
  else
    capacity_ = MIN_CAPACITY;
  T *newdata = new T[capacity_];
  newdata[0] = value;
  for (int i = 0; i < size_; i++) {
    newdata[i + 1] = data_[i];
  }
  delete[] data_;
  data_ = new T[capacity_];
  for (int k = 0; k < size_ + 1; ++k) {
    data_[k] = newdata[k];
  }
  delete[] newdata;
  size_++;
}
template<typename T>
void BiDirectionalListOnArray<T>::PushBack(const T &value) {
  if (size_ == 0) {
    data_[0] = value;
    size_++;
    return;
  }
  if (size_ == MIN_CAPACITY)
    capacity_ = capacity_ * GROWTH_FACTOR;
  else
    capacity_ == MIN_CAPACITY;
  T *newdata = new T[capacity_];
  int i = 0;
  for (; i < size_; i++) {
    newdata[i] = data_[i];
  }
  newdata[i] = value;
  delete[] data_;
  data_ = new T[capacity_];
  for (int k = 0; k < size_ + 1; ++k) {
    data_[k] = newdata[k];
  }
  delete[] newdata;
  size_++;
}
template<typename T>
void BiDirectionalListOnArray<T>::PushFront(T &&value) {
  PushFront(value);
}
template<typename T>
void BiDirectionalListOnArray<T>::PushBack(T &&value) {
  PushBack(value);
}
template<typename T>
void BiDirectionalListOnArray<T>::InsertBefore(size_t index, const T &value) {
  if (index + 1 >= size_ || index < 0 || index==0) throw "error";
  else InsertAfter(index-1,value);

}
template<typename T>
int BiDirectionalListOnArray<T>::Find(const T &value) {
  for (int i = 0; i < size_; i++) {
    if (data_[i] == value)
      return i;
  }
  return -1;
}
template<typename T>
std::vector<int> BiDirectionalListOnArray<T>::FindAll(const T &value) {
  std::vector<int> res;
  for (int i = 0; i < size_; ++i) {
    if (data_[i] == value) {
      res.push_back(i);
    }
  }
  return res;
}
template<typename T>
void BiDirectionalListOnArray<T>::InsertAfter(size_t index, const T &value) {

    if (index+1>size_ || index<0 ) throw std::invalid_argument(" ");
    if (size_==capacity_)
      capacity_*=GROWTH_FACTOR;
    if(index==0) {
      PushFront(value);
      return;
    }

    T* temp=new T[size_-index];
    for (int i=index+1, k=0; i<size_; ++i, ++k){
      temp[k]=data_[i];
    }
    data_[index+1]=value;
    for ( int i = index+2, k = 0; i < size_+1; ++i, ++k){
      data_[i]=temp[k];
    }
    delete [] temp;

    size_++;
}
template<typename T>
void BiDirectionalListOnArray<T>::Erase(size_t index) {
  if(index<0||index+1>size_){
    throw std::invalid_argument(" ");
  }
  if(index==0){
    PopFront();
    return;
  }
  if (index==size_-1){
    PopBack();
    return;
  }
  for (int i = index; i<size_-1; ++i) {
    data_[i] = data_[i + 1];
  }
  size_--;

}

}

#endif //KR2_GR1_KHOMYAKOVA_LILIYA__BIDIRECTIONAL_LIST_ON_ARRAY_H_
