#include "queue.hpp"

namespace data_structures
{
  TaskNode::TaskNode(const std::string description, const tm deadline)
  {
    this->description = description;
    this->deadline = deadline;
    this->next = nullptr;
  }
  
  TaskPriorityQueue::TaskPriorityQueue()
  {
    head = nullptr;
    tail = nullptr;    
  }
  
  bool TaskPriorityQueue::is_empty() const
  {
    return head == nullptr;
  }

  void TaskPriorityQueue::enqueue(const TaskNodePointer newNode){
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

  void TaskPriorityQueue::dequeue()
  {
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

  void TaskPriorityQueue::make_empty(){
    while (!is_empty()) dequeue();
  }
  
  TaskNodePointer TaskPriorityQueue::top() const
  {
    return head;
  }
}