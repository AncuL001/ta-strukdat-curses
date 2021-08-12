#include "linked-list.hpp"

namespace data_structures
{
  CategoryNode::CategoryNode(std::string name)
  {
    this->name = name;
    prev = nullptr;
    next = nullptr;
  }

  CategoryList::CategoryList() 
  {
    size = 0;
    head = nullptr;
    tail = nullptr;
  }

  bool CategoryList::is_empty() const
  {
    return size == 0;
  }
  
  size_t CategoryList::get_size() const
  {
    return size;
  }

  void CategoryList::make_empty()
  {
    while (!is_empty()){
      remove_category(0);
    }
    size = 0;
  }

  void CategoryList::insert_category(const CategoryNodePointer newNode)
  {
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
  
  bool CategoryList::does_exist(const std::string name) const 
  {
    for (auto temp = head; temp; temp = temp->next){
      if (name == temp->name) return true;
    }
    return false;
  }

  CategoryNodePointer CategoryList::at(const size_t index) const 
  {
    if (index > size) return nullptr;

    CategoryNodePointer temp = head;
    for (size_t i = 0; i != index; i++){
      temp = temp->next;
    }
    return temp;
  }
  
  CategoryNodePointer CategoryList::find_by_name(const std::string name) const 
  {
    CategoryNodePointer temp = head;
      while ((temp) && (temp->name != name)){
        temp = temp->next;
      }
      return temp;
  }

  void CategoryList::remove_category(size_t index) 
  {
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

  void CategoryList::rename_category(const size_t index, const std::string newName)
  {
    CategoryNodePointer temp = at(index);
    if (temp == nullptr) return;

    temp->name = newName;
    return;
  }
  
  CategoryNodePointer CategoryList::get_current() const 
  {
    return current;
  }

  void CategoryList::move_current(const size_t index)
  {
    CategoryNodePointer temp = at(index);
    if (temp == nullptr) return;

    current = temp;
  }
}