#include <iostream>
#include <cstring>
#include <cmath>


using namespace std;

void insert_heap(int* heap, int i, int numInput);
void print_heap(int heap[], int arrSize);
  
int main() {
  int input;
  int numInput;
  int heap[101] = {0};
  heap[1] = 0;
  
  
  cout << "How many numbers do you want to enter? ";
  cin >> input;
  cout << "Given: " << input << endl;

  for(int i = 1; i < input+1; i++) {
    cout << "Enter number: ";
    cin >> numInput;
    cout << "[" << i << "] " << numInput << endl;

    insert_heap(heap, i, numInput);
  }
  
    

  int arrSize = *(&heap + 1) - heap;
  print_heap(heap, arrSize);

}

void print_heap(int heap[], int arrSize) {

  //int arrSize = *(&heap + 1) - heap;
  //int arrSize = heap.sizeof();
  cout << arrSize << "array" << endl;
  
  cout << "size" << arrSize << endl;
  
  // entire heap
  cout << "MAX HEAP: ";
  int level = 0;
  for (int j = 1; j < arrSize; j++) {
    if (heap[j] > 0) {
      cout << " " << heap[j];
    }
  }
  cout << endl << endl << "HEAP level break down: " << endl;
  
  // break down
  int prev_level = 0;
  int current_level = 0;
  for(int j = 1; j < arrSize; j++) {
    // new line for new level only.
    if (j >= pow(2, current_level)) {
      current_level++;
    }
    //-D- cout << " J= " << j << " curr " << current_level << " prev_l " << prev_level << endl;
    
    if (current_level > prev_level) {
      cout <<endl;
    }
    
    prev_level = current_level;
    if (heap[j] > 0) {
      cout << " " << heap[j] ;
    } else {
      // exit loop
      j = arrSize;
    }
    
    
  }
  
}



void insert_heap(int* heap, int i, int numInput) {
  heap[i] = numInput;
  // check Max heap;
  int child = i;
  int parent = child/2;
  while (heap[parent] < heap[child] && parent > 0) {
    int tempNum = heap[parent];
    heap[parent] = heap[child];
    heap[child] = tempNum;
    child = parent;
    parent = child/2;
    
  }
}
