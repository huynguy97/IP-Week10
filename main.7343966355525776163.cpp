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
vector <int> VecForHeap = {15, 40, 42, -15, 30, 35, 5};
vector <int> SortedVec (VecForHeap.size());

void swap(vector <int>& VecForHeap, int i, int j)
{
    /*                */
    assert ( i >= 0 && j >= 0 ) ;
    /*                                                                                         */
    const int HELP = VecForHeap [i];
    VecForHeap [i] = VecForHeap [j] ;
    VecForHeap [j] = HELP;
}

void push_up (vector <int>& VecForHeap, int i)
{
    /*                */
    assert ( i >= 0 && i < VecForHeap.size()) ;
    /*                                                                                      */
    int j = (i-1)/2;
    if (VecForHeap [i] > VecForHeap[j])
    {
        swap(VecForHeap, i, j);
    }
}

void build_heap (vector <int>& VecForHeap)
{
    /*                */
    assert (true) ;
    /*                                                                                            */
    for (int i = 1; i < VecForHeap.size(); i++)
    {
        push_up(VecForHeap, i);
    }
    for (int j = 0; j < VecForHeap.size(); j++)
    {
        cout << VecForHeap[j] << " ";
    }
    cout << endl;
}

void push_down (vector <int>& VecForHeap, int i)
{
    /*                */
    assert (i >= 0) ;
    /*                                                                                                                                       */
    int j;
    int k;
    int counter;
    while(counter != 0){
        counter = 0;
        j = ((2*i)+1);
        k = ((2*i)+2);
        if (j < (VecForHeap.size()))
        {
            if ((VecForHeap[j] > VecForHeap[k] || k >= VecForHeap.size()) && VecForHeap[j] > VecForHeap[i])
            {
                swap(VecForHeap, i, j);
                i = j;
                counter++;
            }
        }
        if (k < (VecForHeap.size()))
        {
            if (VecForHeap[k] > VecForHeap[j] && VecForHeap[k] > VecForHeap[i])
            {
                swap(VecForHeap, i, k);
                i = k;
                counter++;
            }
        }
    }
}

void pick_heap (vector <int>& VecForHeap, vector <int>& SortedVec)
{
    /*                */
    assert (true);
    /*                                                                    */
    int times = VecForHeap.size();
    for (int i = 0; i < times; i++)
    {
        swap(VecForHeap, 0, VecForHeap.size() - 1);
        SortedVec[VecForHeap.size() - 1] = VecForHeap[VecForHeap.size() - 1];
        VecForHeap.pop_back();
        push_down(VecForHeap, 0);
    }
    for (int j = 0; j < SortedVec.size(); j++)
    {
        cout << SortedVec[j] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "====================" << endl << "  Build heap:   " << endl << "====================" << endl;
    build_heap(VecForHeap) ;
    cout << endl;
    cout << "====================" << endl << "  Sorted vector:   " << endl << "====================" << endl;
    pick_heap(VecForHeap, SortedVec) ;
}

