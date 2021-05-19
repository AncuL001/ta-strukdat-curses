#pragma once
#include "../functions/datetime-plus.hpp"

namespace data_structures {
  
  /**
   * @brief implementasi struct untuk elemen task
   */
  struct TaskNode {
    std::string description;
    tm deadline;
    TaskNode *next;
    
    /**
     * @brief Constructor
     * 
     * @param description deskripsi task
     * @param deadline tanggal deadline
     */
    TaskNode(const std::string description, const tm deadline){
      this->description = description;
      this->deadline = deadline;
      this->next = nullptr;
    }    
  };

  /**
   * @brief tipe data pointer untuk node task
   */
  typedef TaskNode *TaskNodePointer;

  /**
   * @brief implementasi class untuk queue
   */
  class TaskPriorityQueue {
    private :
    TaskNodePointer head;
    TaskNodePointer tail;

    public:
    /**
     * @brief Constructor
     * 
     * @constructor
     */
    TaskPriorityQueue() {
      head = nullptr;
      tail = nullptr;
    }

    /**
     * @brief mengetahui apakah queue kosong
     *
     * @return 1 jika kosong, 0 jika tidak
     */
    bool is_empty() const {
      return head == nullptr;
    }

    /**
     * @brief memasukan node ke list sesuai priority elemen.
     * @note deadline lebih awal = lebih di atas. Jika ada dua node dengan deadline sama, yang baru diletakkan di bawahnya
     * 
     * @param newNode node yang ingin dimasukkan.
     */
    void enqueue(const TaskNodePointer newNode){
      if (is_empty()) {
        head = newNode;
        tail = newNode;
        return;
      } 

      TaskNodePointer tempPrev = nullptr;
      TaskNodePointer temp = head;
      
      while (compare_deadline(temp->deadline, newNode->deadline) == '<' || 
             compare_deadline(temp->deadline, newNode->deadline) == '='){
        if (temp == tail) break;
        tempPrev = temp;
        temp = temp->next;
      }

      if (temp == head && compare_deadline(newNode->deadline, temp->deadline) == '<'){
        newNode->next = temp;
        head = newNode;
        return;
      }
      if (temp == tail && compare_deadline(newNode->deadline, temp->deadline) == '>'){
        temp->next = newNode;
        tail = newNode;
        return;
      }
      tempPrev->next = newNode;
      newNode->next = temp;
    }

    /**
     * @brief menghapus elemen head queue (First in first out).
     *
     * @param q queue yang dipakai.
     * @todo mengubah fungsi supaya memasukkan node ke undo stack.
     */
    void dequeue(){
      TaskNodePointer delPtr;
      if (is_empty()){
        delPtr = nullptr;
        return;
      }

      if (head->next == nullptr){
        delPtr = head;
        head = nullptr;
        tail = nullptr;
        delete delPtr;
        return;
      }
      
      delPtr = head;
      head = head->next;
      delete delPtr;
    }

    /**
     * @brief menghapus isi queue.
     */
    void make_empty(){
      while (!is_empty()) dequeue();
    }

    /**
     * @brief mengembalikan elemen head.
     *
     * @return elemen head.
     */
    TaskNodePointer top() const {
      return head;
    }

     /**
     * @brief mengiterasi elemen pada queue dan memberikannya kepada fungsi.
     *
     * @param func fungsi yang akan diberikan elemen.
     */
    template <typename F>
    void for_each(F func) const {
      for (auto temp = head; temp; temp = temp->next){
        func(temp);
      }
    }
  };
}