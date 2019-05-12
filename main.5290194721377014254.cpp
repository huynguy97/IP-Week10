#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

//                           
//                       

//       

void easter ( int year, int& day, int& month )
{
  //                                                                           

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
    //                                                                                                    

 //     
 if (x <= 1)
    return false ;

  //          
 for (divisor = 2 ; divisor <= sqrt (static_cast<double>(x)); divisor++)
    {
        //     
        if (x % divisor == 0)
        return false ;
    }
    return true ;
}

//       

/*

                                                   

          
           
            
             
              

   
                            

          
           
            
             
              

   
                            

          
           
            
             
              

   
                                   

          
           
            
             
              

   
                            

          
           
            
             
              

   
                                  

          
           
            
             
              

   
                                 

          
           
            
             
              

   
                            

          
           
            
             
              

                                                             

                                    

                                    
                                        

                      
                                        

                      
                                        

                                    
                                        

                      
                                        

                      
                                        

                                     
                                        

                       
                                        

                                      
                                        

                         
                                        

                                     
                                        

                                     
                                        
*/

vector<int>Tree = {15, 40, 42, -15, 30, 35, 5};

bool push_up(vector<int>&Tree, int i)
{
    //             
    assert( i >= 0 && i < Tree.size());
    //              
    //                                                                                                                        

    //                                      
    bool heap = false;
    while (!heap)
    {
        heap = true;
        if (Tree[(i-1)/2] < Tree[i])
        {
            int a = Tree[(i-1)/2];
            Tree[(i-1)/2] = Tree[i];
            Tree[i] = a;
            heap = false;
        }
    }

    return heap;
}

void build_heap(vector<int>&Tree)
{
    //             
    assert (true);
    //              
    //                                              

    //                        
    for (int i = 0; i < Tree.size(); i++)
        {
            push_up(Tree, i);
        }
}

void push_down(vector<int>&Tree, int i, int vsize)
{
    //             
    assert ( vsize >= 0 && vsize < Tree.size());
    //              
    //                                                                      

    //                                                              
    bool pusheddown = false;
    while (!pusheddown)
    {
        int biggestchild = 0;
        if ((2*i+2) < Tree.size() - vsize)
        {
            if ((2*i+1)  < (Tree.size() - vsize) && Tree[2*i+2] < Tree[2*i+1])
            {
                biggestchild = 2*i+1;
            }
            else
            {
                biggestchild = 2*i+2;
            }
        }
        else
        {
            pusheddown = true;
        }
            if (Tree[biggestchild] > Tree[i])
            {
                int a = Tree[i];
                Tree[i] = Tree[biggestchild];
                Tree[biggestchild] = a;
                i = biggestchild;
            }
            else
            {
                pusheddown = true;
            }

    }

    }

//
//                 
//     
//                         
//         
//                                       
//            
//                                  
//                                        
//                                
//                          
//            
//               
//            
//                            
//            
//         
//                              
//         
//                                     
//            
//                                
//                                      
//                                
//                          
//            
//               
//            
//                            
//            
//         
//            
//         
//                        
//         
//     

void swapping(vector<int>&Tree, int i)
{
    //             
    assert(true);
    //              
    //                                                                                          

    //                            
    int a = Tree[0];
    Tree[0] = Tree[Tree.size()-1];
    Tree[Tree.size()-1] = a;
}

void pick_heap(vector<int>&Tree)
{
    //             
    assert(true);
    //              
    //                                                           

    //                      
    int vsize = Tree.size();
        for (int i = 0; i < Tree.size(); i++)
        {
            swapping(Tree, i);
            vsize--;
            push_down(Tree, 0, i);
        }

}

int main()
{
    build_heap(Tree);
    for (int i = 0; i < Tree.size(); i++)
    {
        cout << Tree [i] << " ";
    }
    cout << endl;
    pick_heap(Tree);
    for (int i = 0; i < Tree.size(); i++)
    {
        cout << Tree [i] << " ";
    }
}

