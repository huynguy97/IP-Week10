#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//                                            
//                                   

/*
    
                                                                                                                                         
   
          
                                                                                                                                                                           
                                      
 
   
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
*/
vector<int> input {15,40,42,-15,30,35,5};

int size (vector<int>& v)
{
    return static_cast<int> (v.size());
}

void swap_nodes ( int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

}

int maximum(int a, int b)
{
    if(a>b)
        return a;
    else return b;
}
void print (vector<int>& ar)
{

    int j = size(ar);
    cout << "[" ;
    for ( int i=0; i<j-1; i++)
    {
        cout << ar[i] << ",";
    }
    cout << ar[j-1] << "]" << endl;
}

//                       

void push_up (vector<int>& ar, int i)
{

         int parent = (i-1)/2;

         while ( ar[i] > ar[parent] && i > 0)
            {
                swap_nodes(ar[i], ar[parent]);
                i=parent;
                parent=(parent-1)/2;
            }

}

void build_heap(vector<int>& ar, int length)
{
    for(int i=0; i<length;i++)
        push_up(ar,i);
}

//        

void push_down(vector<int> ar)
{
    int i=0;
    int child_1=1;
    int child_2=2;
    int greatest_child;
    while(ar[i]<maximum(ar[child_1], ar[child_2]))
    {
        greatest_child=maximum(ar[child_1], ar[child_2]);
        //                                                     
        if( maximum(ar[child_1], ar[child_2])==ar[child_1])
        {
            i=child_1;
            if(child_1*2+1<size(ar))
                child_1=child_1*2+1;
            if(child_1*2+2<size(ar))
                child_2=child_1*2+2;
        }
        else
        {
            i=child_2;
            child_1=child_2*2+1;
            child_2=child_2*2+2;
        }
    }
}

void heap_sort (vector<int>& ar)
{
    cout << "Sorting steps of the vector" << endl;
    int i = size(ar)-1;
    while (i > 0)
    {
        swap_nodes(ar[i], ar[0]);
        cout << "Sorted: ";
        build_heap(ar, i-1);
        print(ar);
        cout << "Heaped: ";
        print(ar);
        i--;

    }
}

int main()
{
    cout << "Initial vector: ";
    print(input);
    build_heap(input, size(input));
    cout << "Heaped Vector: ";
    print(input);
    heap_sort(input);
    cout << "Sorted vector: ";
    print(input);
    return 0;
}

/*                                                                                                                               

                                                

                         
 
                                       
 

                                 
 
             
             
          
             

 
                            
 

                     
                 
                              
     
                             
     
                                   
 

                         

                                          
 
              

                          
     

                                      
                                       
                                 
                                                                 
             
                                                   
             
                                                                   
             
                                                    
             
                                                   
             
                                              

             
                

     
                                      
     
                              
                                                
             
                                              
             
     

 

          

                                
 
                                                  
                     
                
                  
     
                                 
                           
                  
                         
                           
                  
            

     
 

          
 
                               
                 
                                
                              
                 
                     
                              
                 
             
 
*/

