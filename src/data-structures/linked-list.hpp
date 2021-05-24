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
        remove_category(0);
      }
      size = 0;
    }
    /**
     * @brief memasukan node ke paling belakang list.
     * 
     * @param newNode node yang ingin dimasukkan.
     */
    void insert_category(const CategoryNodePointer newNode){
      if (is_empty()){
        head = newNode;
        tail = newNode;
        current = newNode;
        size++;
        return;
      }
      if (does_exist(newNode->name)){
        delete newNode;
        return;
      }
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      size++;
    }

    bool does_exist(const std::string name) const {
       for (auto temp = head; temp; temp = temp->next){
        if (name == temp->name) return true;
      }
      return false;
    }

    /**
     * @brief mencari node dengan nama yang dimaksud.
     * 
     * @param index indeks node yang ingin dicari.
     * @return sebuah node jika ada, nullptr jika tidak ada
     */
    CategoryNodePointer at(const size_t index) const {
      if (index > size) return nullptr;

      CategoryNodePointer temp = head;
      for (size_t i = 0; i != index; i++){
        temp = temp->next;
      }
      return temp;
    }

    CategoryNodePointer find_by_name(const std::string name) const {
      CategoryNodePointer temp = head;
      while ((temp) && (temp->name != name)){
        temp = temp->next;
      }
      return temp;
    }

    /**
     * @brief menghapus node dengan nama yang dimaksud.
     * 
     * @param index indeks node yang ingin dihapus.
     */
    void remove_category(size_t index) {
      CategoryNodePointer temp = at(index);
      if (temp == nullptr) return;
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
    }

    /**
     * @brief mengubah nama node.
     * 
     * @param index indeks node yang ingin diganti namanya.
     * @param newName nama baru node.
     */
    void rename_category(const size_t index, const std::string newName){
      CategoryNodePointer temp = at(index);
      if (temp == nullptr) return;

      temp->name = newName;
      return;
    }

    /**
     * @brief mengembalikan current.
     * 
     * @return current
     */
    CategoryNodePointer get_current() const {
      return current;
    }

    /**
     * @brief mengganti current.
     * 
     * @param index indeks node yang ingin dijadikan current
     */
    void move_current(const size_t index){
      CategoryNodePointer temp = at(index);
      if (temp == nullptr) return;

      current = temp;
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