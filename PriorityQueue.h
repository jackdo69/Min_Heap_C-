#ifndef _PR_QUEUE_H
#define _PR_QUEUE_H

/*
 * Some headers that may be useful.
 * The utility header is included for the
 * std::pair<X,Y> class, used below.
 */
#include <vector>
#include <list>
#include <utility> //std::pair
#include <iostream>


/*
 * This class implements a priority queue ADT
 * with priorities specified in ints.
 * Lower priority values precede higher values in
 * the ordering.
 * The template type E is the element type.
 * See the tests for examples.
 */
template <typename E>
class PriorityQueue {

private:

  /*
   * You will probably want to add some data
   * members here.
   */
   std::vector<std::pair<int,E>> pq;
  //  int _size;
public:

  /*
   * A constructor, if you need it.
   */
  PriorityQueue() {
  }

  PriorityQueue(E element) {

  }

  /*
   * This function adds a new element "element" to the queue
   * with priorioty "priority".
   */
  void insert(int priority, E element) {
    if(priority >= 0) {
      std::pair<int,E> p = std::make_pair(priority, element);
      pq.push_back(p);

      // _size++;
    }
    if (pq.size() > 2)
    trickleUp(pq.size()-1);
  }

  /*
   * Similar to insert, but takes a whole vector of new things to
   * add.
   */
  void insert_all(std::vector<std::pair<int,E> > new_elements) {
    for(int i=0; i < new_elements.size(); i++) {
      pq.push_back(new_elements[i]);
    }
  }

  /*
   * Takes the lowest priority value element off the queue,
   * and returns it.
   */
  E remove_front() {
    if (empty()) return E();
     std::pair<int,E> low = pq[0];
     int index;
     for (int i=0; i< pq.size(); i++) {
       if (pq[i].first < low.first) {
         low = pq[i];
         index = i;
       }
     }
    pq.erase(pq.begin() + index);
     return low.second;


//    return E();
  }

  /*
   * Returns the lowest priority value element in the queue, but leaves
   * it in the queue.
   */
  E peek() {
    if (!pq.empty()) {
      std::pair<int,E> low = pq[0];
      for (int i=0; i< pq.size(); i++) {
        if (pq[i].first < low.first) {
          low = pq[i];
        }
      }
      return low.second;
    }
    return E();
  }

  /*
   * Returns a vector containing all the elements in the queue.
   */
  std::vector<E> get_all_elements() {
    std::vector<E> myE;
    for(int i=0; i < pq.size(); i++) {
      myE.push_back(pq[i].second);
    }
    return myE;

  }

  /*
   * Returns true if the queue contains element "element", false
   * otherwise.
   */
  bool contains(E element){
    for (int i=0; i < pq.size(); i ++) {
      if (pq[i].second == element)
      return true;
    }
    return false;

  }

  /*
   * Returns the priority of the element that matches
   * "element". If there is more than one, return it returns
   * the lowest priority value.
   * If no element matches, return -1.
   */
  int get_priority(E element){
    std::vector<std::pair<int,E>> pri;
    for (int i=0; i < pq.size(); i++) {
      if (pq[i].second == element) {
        pri.push_back(pq[i]);
      }
    }
    if (pri.size()>1) {
      std::pair<int,E> low = pri[0];
      for (int i=0; i< pri.size(); i++) {
        if (pq[i].first < low.first) {
          low = pq[i];
        }
      }
      return low.first;
    } else if(pri.size() == 1) {
      return pri[0].first;
    } else {
      return -1;
    }
  }

  /*
   * Returns a vector containing all the priorities.
   * The ordering of the vector should match that of the
   * return from get_all_elements().
   * That is, the priority of the element
   * get_all_elements()[i] should be get_all_prriorities()[i].
   */
  std::vector<int> get_all_priorities(){
    std::vector<int> myP;
    for(int i=0; i < pq.size(); i++) {
      myP.push_back(pq[i].first);
    }
    return myP;

  }

  /*
   * Finds the first (in priority order) element that matches
   * "element", and changes its priority to "new_priority".
   */

  // 1 2 3 4 5 6 7 10 15
  // 1 2 8 4 5 6 7 10 15
  void change_priority(E element, int new_priority) {
//    int pri = get_priority(element);
//    if (!pri == NULL) {
//      for (int i =0; i < pq.size(); i++) {
//        if (pq[i].first = pri) {
//          pq[i].first = new_priority;
//        }
//      }
//    }
    for (int i = 0; i < pq.size(); i++) {
      if (pq[i].second == element) {
        pq[i].first = new_priority;
        break;
      }
    }
  }

  /*
   * Returns the number of elements in the queue.
   */
  int size() {

    return pq.size();

  }

  /*
   * Returns true if the queue has no elements, false otherwise.
   */
  bool empty() {
    return pq.size() == 0;
  }


  //
  //Some extrea function to implement the min-heap
  //
  void display() {
    for (int i = 0; i < pq.size(); i++) {
      std::cout<<pq[i].first<<pq[i].second;
      std::cout<<" ";
    }
    std::cout<<"\n";
  }

  void swap(int i, int j) {
    std::pair<int,E> temp = pq[i];
    pq[i] = pq[j];
    pq[j] = temp;
  }

  //Repairs the heap order after adding a new element
  void trickleUp (int i) {
    int parent = (i-1)/2;

    if (parent >= 0) {
      if (pq[i].first < pq[parent].first) {
        swap(i, parent);
        trickleUp(parent);
      }
    }
  }

  //Repairs the heap order after replace the root
  //trickleDown(i) performs the repair on the subtree root
  //at pq[i]
  //heapify() calls trickleDown(i) for i from (size()/2)-1 to 0

  void trickleDown (int i) {
    int l_child = (2 * i) + 1;
    int r_child = (2 * i) + 2;

    if (l_child < pq.size()) {
      if ((r_child < pq.size()) && (pq[l_child].first > pq[r_child].first)) {
        swap(l_child,r_child);
      }
      if (pq[i].first > pq[l_child].first) {
        swap(i,l_child);
        trickleDown(l_child);
      }
    }
  }

  // Turns the vector into a min-heap
  void heapify() {
    for (int i = (size()/2)-1; i >= 0; i--) {
      trickleDown(i);
    }
  }
};

#endif
