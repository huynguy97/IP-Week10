#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/*
                            
                       

      
                                                                      
                                                                      
                                                        
                                                                         
                                                                        
                                                                  
                         

      
                               

        

                          
         
                                 
           
                                 

       
         
          
           
            

       
         
          
           
            

       
         
          
           
            

        
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            

  
                                                                              
                                                                             
                                                

           
                           
         
                                    
           
                                    

                                                               
                                                               
                                      

                                                     
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          
                                                          

                                     
                                                                               
                         

                                                                       
                                                                          
                                          

                                                  
*/

void swap(vector<int>& List, int a, int b)
{
    //              
    assert(a >= 0 && a < List.size() && b >= 0 && b < List.size());
    //               
    //                                      
    const int TMP = List[a];
    List[a] = List[b];
    List[b] = TMP;
    //                                                             
}

void push_up(vector<int>& List, int i)
{
    //              
    assert(i > 0 && i < List.size());
    //               
    //                                                                        
    //                        
    while (i > 0 && List[i] > List[(i-1)/2])
    {
        swap(List, i, (i-1)/2);
        i = (i-1)/2;
    }
}

void build_heap(vector<int>& List)
{
    //              
    assert(true);
    //               
    //                                                                 
    //                     
    for (int i = 1; i < List.size(); i++)
        push_up(List, i);
}

ostream& operator<< (ostream& out, const vector<int>& List)
{
    //              
    assert(true);
    //               
    //                                            
    out << "{";
    for (int i = 0; i < List.size()-1; i++)
        out << List[i] << ", ";
    out << List[List.size()-1] << "}";
    return out;
}

void push_down(vector<int>& List, int length)
{
    //              
    assert(length > 0 && length < List.size());
    //               
    //                                                                    
    //                                        
    int i = 0;
    while (2*i+2 < length && (List[i] < List[2*i+1] || List[i] < List[2*i+2]))
    {
        if (List[2*i+1] < List[2*i+2])
        {
            swap(List, i, 2*i+2);
            i = 2*i+2;
        }
        else
        {
            swap(List, i, 2*i+1);
            i = 2*i+1;
        }
    }
    if (2*i+1 < length && List[i] < List[2*i+1])
        swap(List, i, 2*i+1);
}

void pick_heap(vector<int>& List)
{
    //              
    assert(true);
    //               
    //                                                               
    //                                     
    for (int length = List.size()-1; length > 0; length--)
    {
        swap(List, 0, length);
        push_down(List, length);
    }
}

int main()
{
    vector<int> List = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51}; //       
    build_heap(List);
    pick_heap(List);
    cout << List << endl; //                      
    return 0;
}

