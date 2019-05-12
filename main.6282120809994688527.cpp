//                     
//                

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

int HeapSort1[10] = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};
 int HeapSort2[7] = {15, 40, 42, -15, 30, 35, 5};
vector<int> heap = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};

ostream& operator<< (ostream& out, vector<int> heap[10])
{//               
    assert (true) ;
/*                 
                                                                                
*/
    out << heap   << endl ;
    return out ;
}

//                                          
void swap1(int heap[], int i, int j)
{
    //               
    assert ( i >= 0 && j >= 0 ) ; //                          
                     //                          
    //                                                                    
    const int HELP =  heap[i];
    heap [i] = heap [j] ;
    heap [j] = HELP;
}

//                            
void push_up(int v[],int n, int i)
{
    for(int j=0; j<i;j++)
    {
    int left = 2*j + 1;
    int right = 2*j +2;
    if (left<n &&v[left]> v[j])
        swap1(v,j,left);
    if (right<n && v[right] > v[j])
        swap1(v,j,right);
    }
}

void buildHeap(int v[], int n)
{
    for (int i = 0; i <n; i++)
        push_up(v,n,i);

}
void showHeap(int v[],int n)
{
    for ( int i = 0 ; i <n; i++)
        cout << v[i]<<"  ";
    cout<<"\n";
}

int compare (int v[], int a, int b)
{
    if (v[a]>v[b])
        return a;
    else
        return b;
}

void push_down(int v[], int n)
{

    for(int j=0; j<n;j++)
    {
    int left = 2*j + 1;
    int right = 2*j +2;
    int large = compare(v,left,right);
    if (right>=n&&left>=n)
    { }
    else if (right>=n&&left<n)
    {
        if (v[left]> v[j])
            swap1(v,j,left);
    }
    else if (right<n && left<n)
        if (v[j]<v[large])
            swap1(v,j,large);

    }

}

void pick_heap(int v[], int n)
{

    for (int i = n-1; i >0; i--)
        {

        swap1(v,0,i);
        push_down(v,i);
        showHeap(v,n);
        }
}

/*           
                                                                               
                                                                                                                                                 
                                                                            
   
                                                                                                                                 
                                                                                                                                               

      
  
                       

                            

          
              
                 

          
               
                 

          
              
                 

          
              
                 

                         

                                   
                                   
                                   
                                   
                                   
                                   
                                   
  

                                         
                                              
                                           
                                             

*/

int main()
{
    int n = sizeof(HeapSort1)/sizeof(HeapSort1[0]);
    buildHeap(HeapSort1,n);
    showHeap(HeapSort1,n);
    pick_heap(HeapSort1,n);

}

