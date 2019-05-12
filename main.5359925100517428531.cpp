#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

void switching(vector<int>& intergers, int a, int b)
{
    //              
    assert(intergers.size() > 0 && !(a > intergers.size()) && !(b > intergers.size()));
    //                                                                               
    int c = intergers[a];
    intergers[a] = intergers[b];
    intergers[b] = c;
}

void push_up(vector<int>& intergers, int numb)
{
    //              
    assert(intergers.size() > 0 && !(numb >intergers.size()));
    //                                                                       
    bool stop = false;
    int parent = numb;
    while(parent != 0 && !stop)
    {
        stop = true;
        parent = (numb-1)/2;
        if(intergers[parent] < intergers[numb]) //                                        
        {
            switching(intergers, parent, numb);
            stop = false;
            numb = parent;
        }
    }
}

void push_down(vector<int>& intergers,int ordered)
{
    //              
    assert(intergers.size() > 0 && !(ordered > intergers.size()));
    //                                                                       
    int numb = 0;
    bool stop = false;
    int child1;
    int child2;
    int child;
    while(2*numb+2 < ordered && !stop)
    {
        stop = true;
        child1 = 2*numb + 1;
        child2 = 2*numb + 2;
        if(intergers[child1] > intergers[child2]) //                                                              
        {
            child = child1;
        }
        else
        {
            child = child2;
        }
        if(intergers[child] > intergers[numb]) //                                        
        {
            switching(intergers, child, numb);
            numb = child;
            stop = false;
        }
    }
    if (2*numb + 1 < ordered && !stop)     //                                                                   
    {
        child = 2*numb + 1;
        if(intergers[child] > intergers[numb])
        {
            switching(intergers, child, numb);
        }
    }
}

void build_heap(vector<int>& intergers)
{
    //              
    assert(intergers.size() > 0);
    //                                                                                                             
    int n = intergers.size();
    for(int i = 0 ;i < n ;i++)
    {
        push_up(intergers,i);
    }

}

void pick_heap(vector<int>& intergers)
{
    //              
    assert(intergers.size() > 0);
    //                                                                       
    for(int ordered = intergers.size() - 1;ordered > 0 ;ordered--)
    {
        switching(intergers,0,ordered);
        push_down(intergers,ordered);
    }
}

void heap_sorting(vector<int>& intergers)
{
    //              
    assert(intergers.size() > 0);
    //                                                                       
    build_heap(intergers);
    pick_heap(intergers);
}

int main()
{
    vector<int> intergers;
    intergers.push_back(15);
    intergers.push_back(40);
    intergers.push_back(42);
    intergers.push_back(-15);
    intergers.push_back(30);
    intergers.push_back(35);
    intergers.push_back(5);
    heap_sorting(intergers);
    int n = intergers.size();
    for(int i = 0; i < n; i++)
        cout << intergers[i] << "\n";
    return 0;
}

/*

                       

 
  
                                                                                                                       

  
                                                                                                                                                                                       
                                   

 
  

        
          
            
             
                                  

        
          
            
             
                                  

         
           
             
              
                                     

         
           
             
              
                                    

          
           
             
              
                                   

          
           
             
              
                                 

          
           
             
              
               

                                    
                                                                                                         
                                             
                                      
                                             
                                      
                                              
                                      
                                               
                                      
                                             
                                      
                                               
                                                        

  

                                                                                                                                                 

                                                                                                                                      

                                                                                             

                                                                                                                                       

                                                                                                                                     

*/

