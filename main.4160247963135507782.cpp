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
vector<int> v = {15, 40, 42, -15, 30, 35, 5} ;

void swap(int& a, int& b)
{
    const int C = a ;
    a = b ;
    b = C ;
}

bool push_up(int el)
{
    int value = v[el];
    while (value > v[(el-1)/2])
    {
        swap(v[el], v[(el-1)/2]) ;
        el = (el-1)/2;
    }
    return true ;
}

bool build_heap()
{
    for (int i=0 ; i < v.size() ; i++)
    {
        push_up(i) ;
    }
    return true ;
}

bool push_down(int k)
{
    int i=0 ;
    int value = v[i];
    int larger = 2*i + 2 ;
    if (v[2*i + 1] > v[2*i + 2])
        larger = 2*i + 1 ;
    while (value < v[larger] && v[larger] != v[k])
    {
        larger = 2*i + 2 ;
        if (v[2*i + 1] > v[2*i + 2])
            larger = 2*i + 1 ;
        swap(v[i],v[larger]) ;
        i = larger;
    }
}

bool pick_heap()
{
    int n=1 ;
    for (int i=0 ; i < v.size() && (v.size() - n != 0) ; i++)
    {
        swap(v[v.size()-n],v[0]) ;
        for (int i=0 ; i<v.size() ; i++ )
        {
            cout << v[i] << ' ' ;
        }
        cout <<  '\n' ;
        push_down(v.size() - n);
        n++ ;
        for (int i=0 ; i<v.size() ; i++ )
        {
            cout << v[i] << ' ' ;
        }
        cout <<  '\n' ;
    }
    swap(v[2],v[0]) ;
    return true;
}

void heap_sort()
{
    build_heap() ;
    pick_heap() ;
}

int main()
{
    heap_sort();
    for (int i=0 ; i<v.size() ; i++ )
    {
        cout << v[i] << '\n' ;
    }
    return 0;
}

