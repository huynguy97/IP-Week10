#include <iostream>
#include <assert.h>

using namespace std;

//                      

/*
       
                                                                                
                                                                           

       
              
               
                  
                   
                    
                     

               
                  
                   
                    
                     

               
                  
                   
                    
                     

               
                  
                   
                    
                     

              
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                                                             
                                                                                                                                   
                                                                               
                                                                                                                                                 
*/

//         
void push_up(int a[], int n, int i)
{
    assert(true);
//                                                                          
//                           

    int biggest = i;
    int right_child = 2*i+2;
    int left_child = 2*i+1;

    if (a[right_child] > a[biggest] && right_child < n)
        biggest = right_child;
    if (a[left_child] > a[biggest] && left_child < n)
        biggest = left_child;

    if (biggest!=i)
    {
        swap(a[i], a[biggest]);
        push_up(a,n,biggest);
    }

}

void build_heap(int a[], int n, int i)
{
    assert(true);
    //                                                

    for(int i = n/2 -1; i>= 0; i--)
        push_up(a, n, i);
}

//         

void push_down(int a[], int n, int i)
{
    assert(true);
    //                                                                          

    swap(a[0], a[i]);
    push_up(a,i,0);

}

void pick_heap(int a[], int n, int i)
{
    assert(true);
    //                                                                                           

    for (int i=n-1; i>=0; i--)
        push_down(a,n,i);
}

int main()
{
   int a[] = {15, 40, 42, -15, 30, 35, 5};
   int n = sizeof(a)/sizeof(a[0]);
   int i = 0;

   build_heap(a, n, i);
   pick_heap(a, n, i);

   cout<< "The sorted array is: {";
   for (int j = 0; j<= n-2; j++)
    cout<<a[j]<<", ";

    cout<<a[n-1]<<"}";
}

