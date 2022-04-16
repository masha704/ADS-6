// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    int first;
    int last;
    T arr[10];
 public:
    TPQueue() : first(0), last(0) { }
    T pop() {
      return arr[(first++)%size];
    }
    void push(T value) {
      int tmp = last++;
      bool count = true;
      while (count) {
        if ((first <= --tmp) && (value.prior > arr[last%size].prior)) {
          arr[(tmp+1)%size] = arr[tmp%size];
        } else {
            count = false;
          }
      }
      arr[(tmp+1)%size] = value;
    }
  // реализация шаблона очереди с приоритетом на кольцевом буфере
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
