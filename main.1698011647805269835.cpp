#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <array>
using namespace std;
//                                                  
/*                                                                          
                   
                                                                       
*/
/*
          
        
       
              
                  
                     
       
              
                  
                     
       
              
                  
                     
       
              
                  
                     

        
                             
                             
                             
                             
                             
                             
                             
                             
                             
                              
                              
                              

           
                             
                                                   
                                                               
                                                     
                                                              
*/

int MAX_SIZE  ;

int push_up (int& i, int& parent, vector <int>& A)
{
    //               
    assert (i >= 0 && parent >= 0);
    //                                                                          
    //                     
    int h = A[parent] ;
    A[parent] = A[i] ;
    A[i] = h ;
    i = parent ;
    parent = (i - 1)/2 ;
}

int swapps (int i, int j, vector <int>& A)
{
    //                                                 
    int q = A[j];
    A[j]= A[i];
    A[i]= q ;
}

void push_down(int& i, int& child, int& child2, vector <int>& A, int j)
{
    //               
    assert(j >= 0 && i >= 0);
    //                                                               
    if( child2 > j )
        {
            if(A[child] < A[i])
            {
                return;
            }
            else
            {
                swapps(i, child, A);
                i=child;
                child = (2*i + 1);
                child2 = (2*i + 2);
            }

        }
    if (A[child] < A[child2])
        {
            swapps(i , child2, A);
            i=child2;
            child = (2*i + 1);
            child2 = (2*i + 2);
        }
    else
        {
            swapps(i, child, A);
            i=child;
            child = (2*i + 1);
            child2 = (2*i + 2);
        }
}

void build_heap(vector <int>& A)
{
    //                                          
    //                                                                         
    for ( int i = 0 ; i < MAX_SIZE  ; i++ )
    {
        int parent = ( i - 1 ) / 2 ;
            while ( A[i] > A[parent] && parent >= 0 )
            {
                push_up (i, parent, A ) ;
            }
    }
    for ( int i = 0 ; i < MAX_SIZE  ; i++ )
    {
        cout << A[i]  << " " ;
    }
}

void pick_heap (vector <int>& A)
{
    //                                                           
    //                                                                      
    //                         
    int i = 0;
    int j = MAX_SIZE - 1;
    while ( j > 0 )
    {
        if ( A[i] > A[j])
        {
        swapps(i, j, A);
        }
        j = j - 1 ;
        int child = (2*i + 1);
        int child2 = (2*i + 2);
            while ((A[i] < A[child] || A[i] < A[child2]) && (child <= j-1 || child2 <= j-1) )
                {
                        push_down(i, child, child2, A, j);
                }
        i = 0;
    }
    for ( int i = 0 ; i < MAX_SIZE  ; i++ )
    {
        cout << A[i]  << " " ;
    }
}

int main()
{
    vector <int> A = {15, 40, 42, -15, 30, 35, 5};
    MAX_SIZE = A.size() ;
    build_heap(A) ;
    cout << endl ;
    pick_heap(A) ;
}

