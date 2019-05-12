/*                                               
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

/*
           
                                                                              
                                   
                                                                     
                        
*/

/*
         
                                                                  
                                                                      
                                                                        

          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
                          

      
                                                                                                            
                                   
                                                                                                 
                   
                                                                                             
                                         
                                                                                       

*/

vector<int> test = {15,40,42,-15,30,35,5};

void push_up (vector<int>& array,int n, int i)
{
  //                
    assert (n >= 0);
  /*                 
                                                          */
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && array[left] > array[i])
        swap(array[left],array[i]);
    if (right < n && array[right] > array[i])
        swap(array[right],array[i]);
}

void build_heap (vector<int>& array, int n)
{
 //                
    assert (n >= 0);
 /*                 
                             */
    for (int i = 0; i < n; i++)
        push_up(array,n,i);
    for (int i = 0; i < n; i++)
        push_up(array,n,i);
    for (int i = 0; i < n; i++)
        push_up(array,n,i);
}

void swap (vector<int>& array, int n, int i)
{
    //                
    assert ( n >= 0);
    /*                 
                                                      
    */
    swap(array[0],array[i]);
}

void push_down (vector<int>& array, int n, int i)
{
    //               
    assert (n >= 0);
    /*                 
                                                   
                                                                               
                     
    */
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;
    if (largest != i)
    {
        swap(array[i],array[largest]);
        push_down (array, n, largest);
    }
}

void pick_heap (vector<int>& array, int n)
{
    //               
    assert (n >= 0);
    /*                 
                                                        
    */
    for (int a = n-1; a >= 0; a--)
    {
        swap(array,n,a);
        push_down(array,a,0);
    }
}

int main()
{
    int n = test.size();

    build_heap(test,n);
    for (int i = 0; i <= n-1; i++)
        cout << test[i] << ' ';
    cout << endl;
    pick_heap(test,n);
    for (int i = 0; i <= n-1; i++)
        cout << test[i] << ' ';
    cout << endl;
    return 0;
}

