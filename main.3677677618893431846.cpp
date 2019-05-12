//                                                
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
/*
      
                                                                                                                   
                                                                               
                                                                         

      
   
          
            
              
                
                 

          
            
              
                
                 

          
            
              
                
                 

          
            
              
                
                 
   
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
*/

void push_up(vector<int>& MyVector,int n, int i)
{
    int largest;
    int left = 2*i;
    int right = (2*i) + 1;

    if((left <= n)&& (MyVector[left-1]> MyVector[i-1]))
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if((right <= n)&& (MyVector[right-1] > MyVector[largest-1]))
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(MyVector[i-1], MyVector[largest-1]);
        push_up(MyVector, largest,n);
    }

}

void Build_heap(vector<int>& MyVector, int n,int b)
{
    for (int i=n/2; i >=1; i--)
    {
        push_up(MyVector,i,n);
        cout<<MyVector[i];
    }

}
void HeapSort(vector<int>& MyVector, int n)
{
    for(int i=n-1; i>=0; i--)
    {
        Build_heap(MyVector,n,i);
    }
    for(int i=n ;i>=1; i--)
    {
        swap(MyVector[0], MyVector[i]);
        HeapSort(MyVector,i);
    }
}

int main (int n, int b)
{
    //                                                                                                    
    vector<int> MyVector={-5,0,100};
        Build_heap(MyVector,n,b);
        push_up(MyVector,b,n);
        n = MyVector.size()/MyVector[0];
        HeapSort(MyVector, n);

    for(int i=0; i<MyVector.size();i++)
    {

        cout<< MyVector[i]<<" ";
    }

}

