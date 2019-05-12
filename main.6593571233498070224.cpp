#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

/*                                              */
/*                                                                               
      

                                                                   
                                   
                                                                             
                                                                                  
                                                           
                                                                                                      
                                                                           

       
             

            
              
                
                 
                   

            
              
                
                 
                   

            
              
                
                 
                   

            
              
                
                 
                   

            
              
                
                 
                   

            
              
                
                 
                   

            
              
                
                 
                   

              
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      

                                       
                            
                                                                    
                                                      

                                     
                                                                           
                                              

                                                                           
                                

                                              

                                                                           
                                                 

                                                                                */
int size (vector <int>& test)
{
        return static_cast<int>(test.size());
}

void parse_tree(vector<int>& test)
{
//              
assert(true);
//                                                                                                          
//                          
 cout << "          " << test[0] << "         " << endl;
 cout << "        " << "/    \\" << "       " << endl;
 cout << "       " << test[1] <<"     " << test[2] << "       " << endl;
 cout << "      " << "/ \\" << "     " << "/ \\" << "       " << endl;
 cout << "    "<< test[3] << " " << test[4] << "   " << test[5] <<"   " << test[6] << " " << endl;

}

void push_up(vector<int>& test, int i)
{
//              
assert(test.size()>0);
//                                                                  
//                                                                      
//                                                        
   while(test[i]>test[(i-1)/2])
   {
       swap(test[i], test[(i-1)/2]);
       if (i!=0)
       {i=(i-1)/2;}
   }
}

void push_down(vector<int>& test, int heapsize)
{
//               
assert(test.size()>0);
//                                                                                
//                                                               
int i=0;
int l=2*i+1;
int r=2*i+2;
bool done = false;

while(!done)
    {
//                 
done = true;
    if(r<heapsize)
        {
            if(test[r] > test[l] &&  test[i] < test[r])
            {
            swap(test[i], test[r]);
            i=r;
            done=false;
            }
            else if( test[l]>test[r] && test[i]<test[l])
            {
            swap(test[i], test[l]);
            i=l;
            done = false;
            }
        }

    else if(l<heapsize)
        {
        if(test[i]<test[l])
            {
            swap(test[i], test[l]);
            i=l;
            done = false;
            }
        }
l=2*i+1;
r=2*i+2;
//                 
    }
}

void build_heap(vector<int>& test)
{
//                
assert(test.size()>0);
//                  
//                                                                                  
//                                                                                 
   //                          
for (int i=0; i<test.size(); i++)
    {
    push_up(test, i);
 //                    
 //                
    }

}

void pick_heap(vector<int>& test)
{
//               
assert(test.size()>0);
//                                                                                                
//                                                                                                   
//                                                                             
//                         
int heapsize= test.size();
while(heapsize > 0)
    {
   //                  
    swap(test[0], test[heapsize-1]);
    heapsize--;
    push_down(test, heapsize);

    }
}

using namespace std;
void heap_sort(vector<int>& test)
{
//              
 assert(test.size()>0);
//                                                                           
//                                                         
build_heap(test);
pick_heap(test);
cout << "end result" << endl;
parse_tree(test);
}

int main()
{
//               
assert(true);
//                                                     
vector<int> test ={15,40,42,-15,30,35,5};
heap_sort(test);
return 0;
}

