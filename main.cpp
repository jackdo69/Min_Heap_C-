#include <iostream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;
std::string randomString(int length){

    std::string source = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::string output = "";

    for (int i = 0; i < length; i++){

      output += source[std::rand() % source.size()];

    }

    return output;

  }
int main() {
  int choice, element, priority, i, j;
  PriorityQueue<int> pq;
  do {
    cout<<"1.Insert__";
    cout<<"2.Delete__";
    cout<<"3.Display__";
    cout<<"4.Peek__";
    cout<<"5.Size\n";
    cout<<"6.Empty__";
    cout<<"7.GetAllElements__";
    cout<<"8.GetAllPriorities__";
    cout<<"9.GetPriority__";
    cout<<"10.Insert All\n";
    cout<<"11.Change Priority__";
    cout<<"12.Swap__";
    cout<<"13.Trickle Down__";
    cout<<"14.Trickle Up__";
    cout<<"15.Heapify\n";
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Input the element value to be added in the queue : ";
        cin>>element;
        cout<<"Enter its priority : ";
        cin>>priority;
        pq.insert(priority, element);
        break;
    case 2:
        pq.remove_front();
        break;
    case 3:
        cout<< "\n";
        pq.display();
        cout<< "\n";
        break;
    case 4:
        cout << pq.peek() << endl;
        break;
    case 5:
        cout << pq.size() << endl;
        break;
    case 6:
        cout << pq.empty() << endl;
        break;
    case 7: //Print vector
        for(int i = 0; i<pq.get_all_elements().size(); ++i)
          cout << pq.get_all_elements()[i] << '\n';
        break;
    case 8:
        for(int i = 0; i<pq.get_all_priorities().size(); ++i)
          cout << pq.get_all_priorities()[i] << '\n';
        break;
    case 9:
        cout << "Input element to search: ";
        cin>>element;
        cout << "Priority of element is: " << pq.get_priority(element) << endl;
        break;
    case 10:
      {
        // int arr[] = {1, 2, 3};
        // int arr1[] = {5, 4, 3};
        // std::vector<std::pair<int, int> > vPair;
        // for (int i=0; i<3; ++i)//push array onto vector pair
        //   vPair.push_back( make_pair(arr[i],arr1[i]) );
        // //At this stage we have a vector pair
        // //print test to see values in vPair
        // cout << "Values in vPair: \n";
        // for(int i=0;i<vPair.size();++i) {
        //   cout << vPair[i].first << " " << vPair[i].second << endl;
        // }
        // pq.insert_all(vPair);
        // cout << "Values have been added to LinkedList" << endl;

    //     PriorityQueue<std::string> pq;
    //
    // for (int i = 0; i < rand()%10 + 1; i++){
    //
    //   pq.insert(rand()%100, randomString(rand()%5 + i));
    // }
    PriorityQueue<int> pq;
    int priority = rand()%10;
    pq.insert(priority, rand()%10);
      }
      break;
    case 11:
      {
        cout << "Input element to search: ";
        cin>>element;
        cout << "New Priority is: ";
        cin >>priority;
        pq.change_priority(element, priority);
      } //Will need to figure out how to sort LinkedList with new priority value
      break;
    case 12:
    {
      cout << "Which priority you want to swap: ";
      cin>> i;
      cout << ".. and to what priority" ;
      cin>> j;
      pq.swap(i,j);
    }
    break;
    case 13: {
      cout << "Which element you want to trickle down: ";
      cin>> i;
      pq.trickleDown(i);
    }
    break;
    case 14: {
      cout << "Which element you want to trickle up: ";
      cin>> i;
      pq.trickleUp(i);
    }
    break;
    case 15: {
      pq.heapify();
    }
    break;
    default :
        cout<<"Wrong choice\n";
    }
  }
  while (choice != 111);
  return 0;
}
