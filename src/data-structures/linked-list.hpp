#pragma once
#include "queue.hpp"

namespace data_structures {

  /**
   * @brief implementasi struct untuk elemen kategori
   */
  struct CategoryNode {
    std::string name;
    TaskPriorityQueue tasks;
    CategoryNode *prev;
    CategoryNode *next;
    
    /**
     * @brief Constructor
     * 
     * @param name nama kategori baru
     */
    CategoryNode(std::string name){
      this->name = name;
      prev = nullptr;
      next = nullptr;
    }
  };

  /**
   * @brief tipe data pointer untuk kategori
   */
  typedef CategoryNode *CategoryNodePointer;
  
  /**
   * @brief implementasi class untuk linked list
   */
  class CategoryList {
    private :
    size_t size;
    CategoryNodePointer head;
    CategoryNodePointer tail;

    /**
     * @brief menyimpan kategori yang sedang digunakan
     */
    CategoryNodePointer current;

    public :
    /**
     * @brief Constructor
     */
    CategoryList(){
      size = 0;
      head = nullptr;
      tail = nullptr;
    }

    /**
     * @brief mengetahui apakah list kosong
     *
     * @return 1 jika kosong, 0 jika tidak
     */
    bool is_empty() const{
      return size == 0;
    }

    size_t get_size() const{
      return size;
    }

    void make_empty(){
      while (!is_empty()){
        remove_category(head->name);
      }
      size = 0;
    }
    /**
     * @brief memasukan node ke paling belakang list.
     * 
     * @param newNode node yang ingin dimasukkan.
     * @return 0 jika pengisian gagal (nama sudah ada), 1 jika berhasil
     */
    bool insert_category(const CategoryNodePointer newNode){
      if (is_empty()){
        head = newNode;
        tail = newNode;
        current = newNode;
        size++;
        return 1;
      }
      if (find_category(newNode->name)) return 0;
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      size++;
      return 1;
    }

    /**
     * @brief mencari node dengan nama yang dimaksud.
     * 
     * @param name nama node yang ingin dicari.
     * @return sebuah node jika ada, nullptr jika tidak ada
     */
    CategoryNodePointer find_category(const std::string name) const {
      CategoryNodePointer temp = head;
      while ((temp) && (temp->name != name)){
        temp = temp->next;
      }
      return temp;
    }

    CategoryNodePointer at(const size_t size) const {
      if (size > this->size) return nullptr;

      CategoryNodePointer temp = head;
      for (size_t i = 0; i != size; i++){
        temp = temp->next;
      }
      return temp;
    }

    /**
     * @brief menghapus node dengan nama yang dimaksud.
     * 
     * @todo mengubah fungsi supaya memasukkan node ke undo stack.
     * 
     * @param name nama node yang ingin dihapus.
     * @return 0 jika penghapusan gagal (node tidak ditemukan), 1 jika berhasil
     */
    bool remove_category(std::string name) {
      CategoryNodePointer temp = find_category(name);
      if (temp == nullptr) return 0;
      temp->tasks.make_empty();

      if (temp == head){
        if (temp == tail){
          head = nullptr;
          tail = nullptr;
        }
        else {
          temp->next->prev = nullptr;
          head = temp->next;
        }
      }

      else {
        if (temp == tail){
          temp->prev->next = nullptr;
          tail = temp->prev;
        }
        else {
          temp->next->prev = temp->prev;
          temp->prev->next = temp->next;
        }
      }

      delete temp;
      size--;
      return 1;
    }

    bool remove_category(size_t index) {
      CategoryNodePointer temp = at(index);
      if (temp == nullptr) return 0;
      temp->tasks.make_empty();

      if (temp == head){
        if (temp == tail){
          head = nullptr;
          tail = nullptr;
        }
        else {
          temp->next->prev = nullptr;
          head = temp->next;
        }
      }

      else {
        if (temp == tail){
          temp->prev->next = nullptr;
          tail = temp->prev;
        }
        else {
          temp->next->prev = temp->prev;
          temp->prev->next = temp->next;
        }
      }

      delete temp;
      size--;
      return 1;
    }

    /**
     * @brief mengubah nama node.
     * 
     * @param oldName nama node yang ingin diganti namanya.
     * @param newName nama baru node.
     * @return 0 jika penggantian nama gagal (node tidak ditemukan), 1 jika berhasil
     */
    bool rename_category(const std::string oldName, const std::string newName){
      CategoryNodePointer temp = find_category(oldName);
      if (temp == nullptr) return 0;

      temp->name = newName;
      return 1;
    }

    bool rename_category(const size_t index, const std::string newName){
      CategoryNodePointer temp = at(index);
      if (temp == nullptr) return 0;

      temp->name = newName;
      return 1;
    }

    /**
     * @brief mengembalikan current.
     * @return current
     */
    CategoryNodePointer get_current() const {
      return current;
    }

    /**
     * @brief mengganti current.
     * 
     * @param name nama node yang ingin dijadikan current
     * @return 0 jika penggantian current gagal (node tidak ditemukan), 1 jika berhasil
     */
    bool move_current(const std::string name){
      CategoryNodePointer temp = find_category(name);
      if (temp == nullptr) return 0;

      current = temp;
      return 1;
    }

    bool move_current(const size_t index){
      CategoryNodePointer temp = at(index);
      if (temp == nullptr) return 0;

      current = temp;
      return 1;
    }

    /**
     * @brief mengiterasi elemen pada list dan memberikannya kepada fungsi.
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