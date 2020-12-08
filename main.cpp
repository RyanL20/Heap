#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

/* A MAX Heap assignment that can take user input or from a file, then add value to MAX Heap array, print, and delete.  
 * Author: Ryan Le
 * Date: 12/7/2020
 */

using namespace std;

void insert_heap(int* heap, int i, int numInput);
void print_heap(int heap[], int arrSize);
void delete_heap(int* heap, int arrSize, int numDelete);

int main() {
  char* action = new char[20];
  int input;
  int numInput;
  int numDelete;
  int heap[102] = {0};
  heap[1] = 0;
  bool exit = 0;

  int current_index = 1;
  
  int arrSize = *(&heap + 1) - heap; //finds array size  https://www.educative.io/edpresso/how-to-find-the-length-of-an-array-in-cpp

  while(exit == 0) {
    //checks if user typed ADDFILE, ADD, PRINT, DELETE, QUIT
    cout << "Executable Actions: ADDFILE, ADD, PRINT, DELETE, QUIT" << endl;
    cin >> action;

    //ADD FILE
    //Opening file help from https://www.bgsu.edu/arts-and-sciences/computer-science/cs-documentation/reading-data-from-files-using-c-plus-plus.html
    if(action[0] == 'A' && action[1] == 'D' && action[2] == 'D'
       && action[3] == 'F' && action[4] == 'I' && action[5] == 'L' && action[6] == 'E' && action[7] == '\0') {

      ifstream indata;
      int num;
      indata.open("file.txt");
      indata >> num;
      int i = 1;
      while ( !indata.eof()) {
	insert_heap(heap, i, num);
	i++;
	indata >> num;
      }
      indata.close();
      cout << "Read file" << endl;
    }
    
    //ADD from user input
    else if(action[0] == 'A' && action[1] == 'D' && action[2] == 'D' && action[3] == '\0') {
      cout << "Can store up to 100 numbers." << endl;    //tells user how many total numbers they can store
      cout << "How many numbers do you want to enter? "; //asks how many numbers user wants to input
      cin >> input;
      cout << "Given: " << input << endl;
      cout << "Enter a number between 1-1000." << endl;  //tells user to only enter number between 1-1000
   
      for(int i = 1; i < input+1; i++) {
	cout << "[" << i << "] Enter number: ";  //[i] shows the number order that the user enter
	cin >> numInput;

	insert_heap(heap, current_index, numInput);
	current_index++;
      }
    }

    //PRINT
    else if (action[0] == 'P' && action[1] == 'R' && action[2] == 'I' && action[3] == 'N' && action[4] == 'T' && action[5] == '\0') {
      print_heap(heap, arrSize);
    }

    //DELETE
    else if (action[0] == 'D' && action[1] == 'E' && action[2] == 'L' && action[3] == 'E' && action[4] == 'T' && action[5] == 'E' && action[6] == '\0') {
      cout << endl;
      cout << "What number do you want to delete? ";
      cin >> numDelete;
      delete_heap(heap, arrSize, numDelete);
    }

    //QUIT
    else if (action[0] == 'Q' && action[1] == 'U' && action[2] == 'I' && action[3] == 'T' && action[4] == '\0') {
      cout << "EXITED PROGRAM" << endl;
      exit = 1;
    }
  }
}

void print_heap(int heap[], int arrSize) {

  // entire heap
  cout << "MAX HEAP: ";
  int level = 0;
  for (int j = 1; j < arrSize; j++) {
    if (heap[j] > 0) {
      cout << " " << heap[j];
    }
  }
  cout << endl << endl << "HEAP level break down: " << endl;
  
  // print break down MAX heap (tree)
  int prev_level = 0;
  int current_level = 0;
  for(int j = 1; j < arrSize; j++) {
    // new line for new level only.
    if (j >= pow(2, current_level)) {
      current_level++;
    }
    //visual heap tree print       
    if (current_level > prev_level) {
      cout <<endl;
      if (current_level == 1) {
	//cout << "\t\t\t\t\t\t";
	//cout << "                                  ";
	cout << "                                                                ";
       
      }
      else if (current_level == 2) {
	//cout << "\t\t\t\t\t";
	//cout << "          ";
	cout << "                                "; 
      }
      else if (current_level == 3) {
	//cout << "\t\t\t\t";
	//cout << "             ";
	cout << "                ";
      }
      else if (current_level == 4) {
	//cout << "\t\t\t";
	//cout << "              ";
	cout << "        ";
      }
      else if (current_level == 5) {
	//cout << "\t\t";
	//cout << "            ";
	cout << "    ";
      }
      else if (current_level == 6) {
	//cout << "\t";
	cout << "  ";
	
      }
    }
    
    prev_level = current_level;
    
    if (heap[j] > 0) {
      if (current_level == 1) {
	cout << heap[j];
      }
      else if (current_level == 2) {
	//cout << "                     " << heap[j];
	cout << heap[j] << "                                                                ";
      }
      else if (current_level == 3 ) {
	//cout << "           " << heap[j];
	cout << heap[j] << "                                ";
      }
      else if (current_level == 4) {
	//cout << "     " << heap[j];
	cout << heap[j] << "                ";
      }
      else if (current_level == 5) {
	//cout << "   " << heap[j];
	cout << heap[j] << "        ";
      }
      else if (current_level == 6) {
	//cout << "     " << heap[j]; 
	cout << heap[j] << "   ";
      }
      else if (current_level == 7) {
	//cout << " " << heap[j];
	cout << heap[j] << " ";
      }
      //else if (j == 2 || j == 3)  
    }
    else {
      // exit loop
      j = arrSize;
    }
    
    
  }
  cout << endl;
}


void insert_heap(int* heap, int i, int numInput) {
  heap[i] = numInput;
  // check Max heap;
  int child = i;
  int parent = child/2;
  while (heap[parent] < heap[child] && parent > 0) {  //checking and swaping
    int tempNum = heap[parent];  
    heap[parent] = heap[child];
    heap[child] = tempNum;
    child = parent;
    parent = child/2;
    
  }
}

void delete_heap(int* heap, int arrSize, int numDelete) {
  int lastNumber;  //last number in the heap
  int lastNumberIndex;
  //finds last number in heap
  for (int i= 1; i < arrSize; i++) {
    if (heap[1] == 0) {
      cout << "Heap is empty!" << endl;
    }
    else if (heap[i + 1] == 0) { //get the last element in the heap array 
      lastNumber = heap[i];
      lastNumberIndex = i;
      i = arrSize;
      //cout << "last Number Index: " << lastNumberIndex << endl;
      //cout << "lastNumber: " << lastNumber << endl;
    }
  }
  for (int i = 1; i < arrSize; i++) {
    //cout << "heaps: " << heap[i] << endl;
    if (heap[i] == numDelete) {
      heap[i] = lastNumber;
      heap[lastNumberIndex] = 0;
      //cout << "heap[" << i << "]: " << heap[i] << endl; 
      //cout << "heap[lastNumberIndex]: " << heap[lastNumberIndex] << endl; 

      //re-checks MAX heap properties & swapping child to parent if parent < child
      int parent = i; cout << "parent: " << parent << endl;
      int child1 = parent*2; cout << "child1: " << child1 << endl;
      int child2 = parent*2+1; cout << "child2: " << child2 << endl;
      if (heap[child1] > heap[child2]) {
	  while (heap[child1] > heap[parent]) {
	    int tempNum = heap[parent];
	    heap[parent] = heap[child1];
	    heap[child1] = tempNum;
	    parent = child1;
	    child1 = parent*2;
	    child2 = parent*2+1;
	  }
      } else if (heap[child2] > heap[child1]) {
	while (heap[child2] > heap[parent]) {
	  int tempNum = heap[parent];
	  heap[parent] = heap[child2];
	  heap[child2] = tempNum;
	  parent = child2;
	  child1 = parent*2;
	  child2 = parent*2+1;
	}

      }
      i = arrSize; 
    }
    else if (heap[i] == 0) {
      cout << numDelete << " not found in heap." << endl; 
    }
    //exit loop
    if (heap[i] ==0) {
      i = arrSize; 
    }
  }
}

