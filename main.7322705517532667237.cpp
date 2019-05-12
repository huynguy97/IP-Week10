#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> heap;

void fill_vector(vector<int>& heap)
{
    cout << "Hello User! Hoeveel getallen wil je?" << endl;
    int aantal;
    cin >> aantal;
    cout << " Vul getallen in:" << endl;

    for (int k = 0; k < aantal; k++)
    {
        int getal;
        cin >> getal;
        heap.push_back(getal);
    }
}

void swap (vector<int>& heap, int i, int j)
{
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void push_up (vector<int>& heap)
{
    int i = 0;
    int j = 1;
    for (int k = 0; k < heap.size(); k++)
    {
        i = k;
        j = (k-1)/2;
        while (heap[i]> heap[j])
        {
            swap (heap, i, j);
            i = j;
            j = (j-1)/2;
        }
        for (int x = 0; x < heap.size(); x++)
            cout << heap[x]<< ", ";
        cout << endl;
    }
}

void push_down (vector<int>& heap)
{
//              
assert (true);
//               
//                                                                                       

int j = heap.size()-1;
    while(j >= 0)
    {
        int i = 0;
        int q = 0;
        if (heap[i] > heap[j])
        {
            swap(heap, i, j);

            int q = 2*i+1;

            while (heap[i] < heap[q] || heap[i] < heap[q+1])
            {
              if (heap[q] > heap[q+1])
                {
                    swap (heap, q, i);
                    cout << i << " " << q << " "  << heap[i] << " "  << heap[q] << " "  << endl;
                }
                else if (heap[q+1] > heap[q])
                {
                    swap (heap, q+1, i);
                    cout << i << " " << q << " "  << heap[i] << " "  << heap[q] << " "  << endl;
                }
                i = q;
                q = 2*i+1;
            }
            j = j-1;
        }
    }
}

int main()
{
    /*
                  
      
                                                                                            
                                                                                                           
      
                                                                                                                
                                                                                                                            
                                                                                                                  
                                                                                         

       
                                                       
                  
                          
                           
                            
                              
                               
                                
                                 
             
                          
                           
                            
                              
                               
                                
                                 

                           
                            
                             
                                 
                 
                                              
                                  
                 
                                               
                 
                                              
                                  
                                         
                                
                                 
                                  

                           
                            
                             
                               
                                
                                 
                                  

                                 
                                   
                                   
                                   
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  
                                  

            
                                         

       
*/
fill_vector(heap);

cout << '\n' << "Size of vector = " << heap.size() << endl;

for (int i=0; i<heap.size(); i++)
{
    cout << "Het " << i+1 << "e getal is: "<< heap[i] << " " << endl;

}
push_up (heap);
cout << "Push_up has been executed succesfully. " << endl;
push_down(heap);

for (int o=0; o< heap.size(); o++)
{
    cout << heap[o] << " ";
}
}

