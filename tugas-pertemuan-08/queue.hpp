#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T value;
  T priority;
  Element* next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> Head;
  ElementPtr<T> Tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> q;
  q.Head = nullptr;
  q.Tail = nullptr;
  return q;
  
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> newElement;
  newElement = new Element<T>;
  newElement->value = value;
  newElement->priority = priority;
  newElement->next = nullptr;

  ElementPtr<T> pRev = nullptr;
  ElementPtr<T> pHelp = q.Head;

  if(q.Head == nullptr){
    q.Head = newElement;
    q.Tail = newElement;
  }else{
    while(newElement->priority <= pHelp->priority){
      if(pHelp->next == nullptr){
        break;
      }
      pRev = pHelp;
      pHelp = pHelp->next;
    }if(pHelp == q.Head && newElement->priority > pHelp->priority ){
        newElement->next = q.Head;
        q.Head = newElement;
    }else if(pHelp == q.Tail && newElement->priority <= pHelp->priority){
        pHelp->next = newElement;
        q.Tail = newElement;
      }else{
        pRev->next = newElement;
        newElement->next = pHelp;
    }
  } 
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.Head->value;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> delElement;
  if(q.Head == nullptr)
  {
    delElement = nullptr;
  }
  else if(q.Head->next == nullptr)
  {
    delElement = q.Head;
    q.Head = nullptr;
    q.Tail = nullptr;
  }
  else
  {
    delElement = q.Head;
    q.Head = q.Head->next;
    delElement->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
