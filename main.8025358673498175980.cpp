#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

//                                                         
//       
//                                                                                                                          
//                                         
//
//                                                                                                                             
//                                                                                                                    
//                                                                         

/*
       
  
                            
              
                
                  
                    
                     

               
                 
                   
                    
                     

                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            

   
                                                                                                      
                                                                                                                
                                                                                       

                                                                                                   
                       

                                                                                                                     

                                                                                                                       
                   
 */

vector<int> heap = {15, 40, 42, -15, 30, 35, 5};

void buildheap(int n, int i, vector<int>& heap )
{
    assert (true);
    //                                                    
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && heap[1] > heap[largest])
        largest = l;

    if (r  < n && heap[r] > heap[largest])
        largest = r;

    //                                                 
    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        buildheap(n, largest, heap);
    }
}

//                         
void heapSort(int n, vector<int>& heap ) {
    assert(true);
    //               
    for (int i = n / 2 - 1; i >= 0; i--)
        buildheap(n, i, heap);

    //          
    for (int i = n - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);

        //                                                          
        buildheap(i, 0, heap);
    }
}

void printheap(int n, vector<int>& heap )
{
    assert (true);
    //              
    for (int i=0; i<n; ++i)
        cout << heap[i] << " ";
    cout << "\n";
}

int main()
{
    int n = heap.size();
    heapSort(n, heap);

    cout << "Sorted array is \n";
    printheap(n, heap);
}
