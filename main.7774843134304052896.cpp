#include <iostream>
#include <vector>
using namespace std;

//                      
//                          

void our_swap (int& a, int& b)
{
    int t = a ;
    a = b ;
    b = t ;
}

int maximum (int a, int b)
{
    if (a >= b)
    {
        return a ;
    }
    return b ;
}

bool push_up (vector<int>& int_vector, int& pos)
{
    if ((pos-1)/(2) >= 0 && int_vector[pos] > int_vector[(pos-1)/(2)])
    {
        our_swap(int_vector[pos], int_vector[(pos-1)/(2)]) ;
        pos = (pos-1)/(2) ;
        return true ;
    }
    return false ;
}

void build_heap (vector<int>& int_vector)
{
    for (int i = 0 ; i < int_vector.size() ; i++)
    {
        int pos = i ;
        while (push_up(int_vector, pos)) ;
    }
}

bool push_down (vector<int>& int_vector, int& pos)
{
    int pos_to_swap = 0 ;
    if (maximum(int_vector[2*pos+1], int_vector[2*pos+2]) == int_vector[2*pos+1])
    {
        pos_to_swap = 2*pos + 1 ;
    }
    else
    {
        pos_to_swap = 2*pos + 2 ;
    }
    if (int_vector[pos] < int_vector[pos_to_swap] && (2*pos+1) < int_vector.size() && (2*pos+2) < int_vector.size())
    {
        our_swap(int_vector[pos], int_vector[pos_to_swap]) ;
        pos = pos_to_swap ;
        return true ;
    }
    return false ;
}

void pick_heap(vector<int>& int_vector, vector<int>& sorted)
{
    while(int_vector.size() > 1)
    {
        int pos = 0 ;
        our_swap(int_vector[0], int_vector[int_vector.size() - 1]) ;
        sorted.insert(sorted.begin(), int_vector[int_vector.size() - 1]) ;
        int_vector.pop_back() ;
        while (push_down(int_vector, pos)) ;
    }
    sorted.insert(sorted.begin(), int_vector[0]) ;
}

int main()
{
    vector<int> int_vector = {15, 40, 42, -15, 30, 35, 5} ;
    vector<int> sorted ;
    build_heap(int_vector) ;
    pick_heap(int_vector, sorted) ;
    for (int i = 0 ; i < sorted.size() ; i++)
    {
        cout << sorted[i] << "\t" ;
    }
    return 0 ;
}

/*
            
 
                                                                                                
 
                                                                                                               
                                                                                                     

            
 
       
          
            
              
               
                

          
            
              
               
                

          
            
              
               
                

          
            
              
               
                

       
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      

 
                                                                
                                                                                                           
                                                                                                                 
                                                                                      
                                                                  
                                                                                                          
                                                                                                                 
*/

