
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <math.h>
#include <tuple>

using namespace std;

//                               

//            
void easter ( int year, int& day, int& month )
{
 const int a = year % 19 ;
 const int b = year / 100 ;
 const int c = year % 100 ;
 const int d = b / 4 ;
 const int e = b % 4 ;
 const int f = (b + 8) / 25 ;
 const int g = (b - f + 1) / 3 ;
 const int h = (19 * a + b - d - g + 15) % 30 ;
 const int i = c / 4 ;
 const int k = c % 4 ;
 const int L = (32 + 2 * e + 2 * i - h - k) % 7 ;
 const int m = (a + 11 * h + 22 * L) / 451 ;
 month = (h + L - 7 * m + 114) / 31 ;
 day = ((h + L - 7 * m + 114) % 31) + 1 ;
}

bool is_prime (int x, int& divisor)
{
 if (x <= 1)
 return false ;
 for (divisor = 2 ; divisor <= sqrt (static_cast<double>(x)); divisor++)
 {
 if (x % divisor == 0)
 return false ;
 }
 return true ;
}

//             

/*
                       
 
                            
                  
     
                                  
                     
     
                        
 
*/

//                                                                                                           
/*
                                  
 
                
                           
     
                     
         
                                 
         
            
         
                         
         
     
                        
 
                                         
 
                
                           
     
                     
         
                                 
         
            
         
                         
         
     
                        
 
*/

void push_up_array(int A[], int i)
{
    //               
    assert(i>=0);
    /*                
                                                          
    */
    int element = i;
    int parent= (i-1)/2;
    if (A[parent]<A[i])
    {
        swap(A[parent], A[i]);
        element=parent;
    }
    if (element != i)
    {
        push_up_array(A, element);
    }
}

void push_up_vector(vector<int>& V, int i)
{
    //               
    assert(i>=0);
    /*                
                                                           
    */
    int element = i;
    int parent= (i-1)/2;
    if (V[parent]<V[i])
    {
        swap(V[parent], V[i]);
        element=parent;
    }
    if (element != i)
    {
        push_up_vector(V, element);
    }
}

void push_down_array (int A[], int i, int N)
{
    //               
    assert(N>=0 && i>=0);
    /*                
                                                              
    */
    int element=i;
    int left_child= 2*i + 1;
    int right_child= 2*i + 2;
    if (left_child < N && A[left_child] > A[element])
    {
        element = left_child;
    }
    if (right_child < N && A[right_child] > A[element])
    {
        element = right_child;
    }
    if (element != i)
    {
        swap(A[i], A[element]);
        push_down_array(A, element, N);
    }
}

void push_down_vector (vector<int>& V, int i, int n)
{
    //               
    assert(n>=0 && i>=0);
    /*                
                                                               
    */
    int element=i;
    int left_child= 2*i + 1;
    int right_child= 2*i + 2;
    if (left_child < n && V[left_child] > V[element])
    {
        element = left_child;
    }
    if (right_child < n && V[right_child] > V[element])
    {
        element = right_child;
    }
    if (element != i)
    {
        swap(V[i], V[element]);
        push_down_vector(V, element, n);
    }
}

int on_level(int element)
{
    //               
    assert(element>=0);
    /*                
                                                                                              
    */
    int num_branch=0, sum=0, last;
    while (sum<=element)
    {
        sum=pow(2,num_branch)+sum;
        last=pow(2,num_branch);
        num_branch++;
    }
    return last;
}

void print_heap_array(int A[], int N)
{
    //               
    assert(N>=0);
    /*                
                                           
    */
    int el_on_l=0;
    for (int k=0; k<=N; k=k+el_on_l)
    {
        el_on_l=on_level(k);
        for (int j=0; j<el_on_l && (j+k)<=N; j++)
        {
            cout << A[k+j] << "\t";
        }
        cout << endl;
    }
}

void print_heap_vector(vector<int>& V, int n)
{
    //               
    assert(n>=0);
    /*                
                                            
    */
    int el_on_l=0;
    for (int k=0; k<=n; k=k+el_on_l)
    {
        el_on_l=on_level(k);
        for (int j=0; j<el_on_l && (j+k)<=n; j++)
        {
            cout << V[k+j] << "\t";
        }
        cout << endl;
    }
}

void printArray(int A[], int element, int N)
{
    //               
    assert(element>=0 && N>0);
    /*                
                                             
    */
    int start=N-element-1, i=0;
    cout << "{";
    for (i=start; i<=(N-1); i++)
    {
        if (i!=(N-1))
        {
            cout << A[i] << ", ";
        }
        else
        {
            cout << A[i];
        }
    }
    cout << "}" << endl;
}

void printVector(vector<int>& V, int element, int n)
{
    //               
    assert(element>=0 && n>0);
    /*                
                                              
    */
    int start=n-element-1, i=0;
    cout << "{";
    for (i=start; i<=(n-1); i++)
    {
        if (i!=(n-1))
        {
            cout << V[i] << ", ";
        }
        else
        {
            cout << V[i];
        }
    }
    cout << "}" << endl;
}

void build_heap_array (int A[], int N)
{
    //               
    assert(N>0);
    /*                
                                                                                                                                       
    */
    for (int i = 0; i<=N-1; i++)
    {
        push_up_array(A, i);
        print_heap_array(A, i);
        cout << endl;
    }
}

void build_heap_vector (vector<int>& V, int n)
{
    //               
    assert(n>0);
    /*                
                                                                                                                                        
    */
    for (int i = 0; i<=n-1; i++)
    {
        push_up_vector(V, i);
        print_heap_vector(V, i);
        cout << endl;
    }
}

void pick_heap_array(int A[], int N)
{
    //               
    assert(N>0);
    /*                
                                                                                                                                
                                                                 
    */
    for (int i=0; i<N; i++)
    {
        swap(A[0],A[N-1-i]);
        push_down_array(A,0,N-1-i);
        printArray(A, i, N);
    }
}

void pick_heap_vector(vector<int>& V, int n)
{
    //               
    assert(n>0);
    /*                
                                                                                                                                 
                                                                 
    */
    for (int i=0; i<n; i++)
    {
        swap(V[0],V[n-1-i]);
        push_down_vector(V,0,n-1-i);
        printVector(V, i, n);
    }
}

void Heap_sort_array(int A[], int N)
{
    //               
    assert(N>0);
    /*                
                                                                                                                           
    */
    cout << "Building the heap" << endl << endl;
    build_heap_array(A, N);
    cout << "Sorting the heap" << endl << endl;
    pick_heap_array(A, N);
}

void Heap_sort_vector (vector<int>& V, int n)
{
    //               
    assert(n>0);
    /*                
                                                                                                                            
    */
    cout << "Building the heap" << endl << endl;
    build_heap_vector(V, n);
    cout << "Sorting the heap" << endl << endl;
    pick_heap_vector(V, n);
}

int main ()
{
    //           
    int day=6, month=3, a, divisor;
    easter(2010,day,month);
    /*                                                                                                                   
                                          
    */
    //           
    is_prime(7,divisor);
    /*                                                                                                                         
    */
    //           
    int A[] = {15, 40, 42, -15, 30, 35, 5};     //                                                     
    //                                                                                                 
    int N=(sizeof(A)/sizeof(A[0]));
    Heap_sort_array(A, N);
    //           
    /*
                                      
                                         
                                              
                                        
                                        
    */

    //          
    vector<int> V= {2,14,30,29,42,30,11,-5,0,51};
    int n=V.size();
    Heap_sort_vector(V, n);

}

