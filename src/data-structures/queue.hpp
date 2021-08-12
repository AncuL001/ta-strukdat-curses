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
    TaskNode(const std::string description, const tm deadline);
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
    TaskPriorityQueue();

    /**
     * @brief mengetahui apakah queue kosong
     *
     * @return 1 jika kosong, 0 jika tidak
     */
    bool is_empty() const;

    /**
     * @brief memasukan node ke list sesuai priority elemen.
     * @note deadline lebih awal = lebih di atas. Jika ada dua node dengan deadline sama, yang baru diletakkan di bawahnya
     * 
     * @param newNode node yang ingin dimasukkan.
     */
    void enqueue(const TaskNodePointer newNode);

    /**
     * @brief menghapus elemen head queue (First in first out).
     *
     * @param q queue yang dipakai.
     * @todo mengubah fungsi supaya memasukkan node ke undo stack.
     */
    void dequeue();

    /**
     * @brief menghapus isi queue.
     */
    void make_empty();

    /**
     * @brief mengembalikan elemen head.
     *
     * @return elemen head.
     */
    TaskNodePointer top() const;

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