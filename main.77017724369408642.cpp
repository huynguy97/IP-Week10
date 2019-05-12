#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/*
         
                  
                       
       

                                                                                                                                           
                                                                                            

       
           
        
         
          
           
            
             
        
         
          
           
            
             
        
         
          
           
            
             
        
         
          
           
            

           

                      
                                                  
                                         
                                                       
                                         
                                       
                                                   
                                       
                                       
                                   
                            
*/

struct Slice
{
    int from ;
    int to ;
};

void push_up(int& a, int& b )
{
//             
assert(true);
//                                                    
    int help = a;
    a = b;
    b = help;
}

void swap(vector<int>& heaps, int& i ,Slice s)
{
//             
assert(true);
//                                                            

    push_up (heaps[i], heaps[0]);
    i--;
}

void build_heap(vector<int>& heaps )
{
//             
assert (true);
//                                                                                                                     
//                                                                                  
int k = 0;
    for ( int i = 0; i < heaps.size(); i++)
    {
        k = 2*i+1;
        if( heaps[i] < heaps[k] && k < 7 )
            push_up (heaps[i], heaps[k]);

        k = 2*i+2;
        if (heaps[i] < heaps[k] && k < 7 )
            push_up (heaps[i], heaps[k]);
    }
}

void push_down(vector<int>& heaps, int to )
{
//             
assert (true);
//                                                                              

    int k = 0;
    int h = 0;
    {
        for ( int i = 1; i <= to; i++)
        {
            k = (i-1)/2;
            h = (i-2)/2;
            if(heaps[k]>= heaps[h])
            {
                if( heaps[i] > heaps[k] && k >= 0 )
                    push_up (heaps[i], heaps[k]);
            }
            else if (heaps[i] > heaps[h] && k >= 0 )
                    push_up (heaps[i], heaps[h]);
        }vector_of_integers
    }
}

void pick_heap(vector<int>& heaps )
{
//            
assert (true);
//                                                                                                                        
//                                                                                 
    int from = 0;
    int to = heaps.size() -1;
    Slice s = {from,to};

    while (from<= to)
    {
    swap( heaps, to, s);
    s.to = to;
    push_down(heaps, to);
    }
}

int main()
{
    vector<int> heaps = {15, 40, 42, -15, 30, 35, 5}; //                               

    for (int j = 0 ; j < heaps.size(); j++)
        cout << heaps[j] << " " ;
    cout << endl;

   build_heap( heaps );

    for (int j = 0 ; j < heaps.size(); j++)
        cout << heaps[j] << " " ;
    cout << endl;

    pick_heap(heaps);

     for (int j = 0 ; j < heaps.size(); j++)
        cout << heaps[j] << " " ;
    cout << endl;

    return 0;
}

