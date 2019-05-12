#include <iostream>
#include <vector>
#include <cassert>

//                     
//                             

using namespace std;

void push_up(vector<int>& numbers, int n, int i)
{
    //              
    assert (i >= 0 && n>= 0);
    //                                                                                
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && numbers[l] > numbers[largest])
        largest = l;
    if (r < n && numbers[r] > numbers[largest])
        largest = r;
    if (largest != i)
    {
        swap(numbers[i], numbers[largest]);
        push_up(numbers, n, largest);
    }
}

void build_heap (vector<int>& numbers, int n)
{
    //              
    assert (true);
    //                                                                              
    for (int i = n / 2 - 1; i>= 0; i--)
    {
        push_up(numbers, n, i);
    }
}

void push_down(vector<int>& numbers, int n)
{
    //              
    assert (true);
    //                                                                                                                                                                            
    for (int i=n-1; i>=0; i--)
    {
        swap(numbers[0], numbers[i]);
        push_up(numbers, i, 0);
    }
}

void pick_heap (vector<int>& numbers, int n)
{
    //              
    assert (true);
    //                                           
    push_down(numbers, n);
}

void printArray(vector<int>& numbers, int n)
{
    //              
    assert (true);
    //                                             
    for (int i=0; i<n; ++i)
        cout << numbers[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> numbers = {15, 40, 42, -15, 30, 35, 5};
    int n = numbers.size();
    build_heap(numbers, n);
    pick_heap(numbers, n);
    cout << "Sorted vector is \n";
    printArray(numbers, n);
}

/*
       
                                                                                                
                                                                                                                                              

       
          
              
                

          
              
                

          
              
                     

          
              
                

          
              
                     

          
              
                     

          
              
                    

                                             
                                                          
                                                                                      
                                                                                      
                                                                                      
                                                                                      
                                                                                      
       

                                                                                                                                                           
                                                                                                                        
                                                  
*/

