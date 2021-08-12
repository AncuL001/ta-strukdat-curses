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
    CategoryNode(std::string name);
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
    CategoryList();

    /**
     * @brief mengetahui apakah list kosong
     *
     * @return 1 jika kosong, 0 jika tidak
     */
    bool is_empty() const;

    /**
     * @brief mengetahui ukuran list
     */
    size_t get_size() const;

    /**
     * @brief mengosongkan list
     */
    void make_empty();

    /**
     * @brief memasukan node ke paling belakang list.
     * 
     * @param newNode node yang ingin dimasukkan.
     */
    void insert_category(const CategoryNodePointer newNode);

    /**
     * @brief mengetahui apakah node dengan nama yang dimaksud ada di list
     * 
     * @param name nama node yang ingin dicari
     */
    bool does_exist(const std::string name) const;

    /**
     * @brief mencari node dengan nama yang dimaksud.
     * 
     * @param index indeks node yang ingin dicari.
     * @return sebuah node jika ada, nullptr jika tidak ada
     */
    CategoryNodePointer at(const size_t index) const;

    /**
     * @brief mengembalikan node dengan nama yang dimaksud
     * 
     * @param name nama yang ingin diambil
     * @return nullptr jika tidak ada, node yang dimaksud jika ada
     */
    CategoryNodePointer find_by_name(const std::string name) const;

    /**
     * @brief menghapus node dengan nama yang dimaksud.
     * 
     * @param index indeks node yang ingin dihapus.
     */
    void remove_category(size_t index);

    /**
     * @brief mengubah nama node.
     * 
     * @param index indeks node yang ingin diganti namanya.
     * @param newName nama baru node.
     */
    void rename_category(const size_t index, const std::string newName);

    /**
     * @brief mengembalikan current.
     * 
     * @return current
     */
    CategoryNodePointer get_current() const;

    /**
     * @brief mengganti current.
     * 
     * @param index indeks node yang ingin dijadikan current
     */
    void move_current(const size_t index);

    /**
     * @brief mengiterasi elemen pada list dan memberikannya kepada fungsi.
     *
     * @param func fungsi yang akan diberikan elemen.
     */
    template <typename F>
    void for_each(F func) const{
      for (auto temp = head; temp; temp = temp->next){
        func(temp);
      }
    }
  };
}