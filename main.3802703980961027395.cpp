#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//                          
//                     

int size (vector<int> List)
{
    //             
    assert(true);
    //                                                      
    return static_cast<int> (List.size());
}

void print_vector(vector<int> List, int length)
{
    assert(true);
    //                                      
    for(int i = 0; i<= length; i++)
    {
        cout << List[i]<< ", ";
    }
}

void swap (vector<int>& List, int  i, int  j )
{//	              
	assert ( i >= 0 && j >= 0 ) ;	//                         
						            //                         
//                                                                
	const int HELP = List [i];
	List [i] = List [j] ;
	List [j] = HELP;
}

void push_up(int index, vector<int>& List)
{
    //            
    assert(index >= 0);
    //                                                                               
    while(List[index]>List[(index-1)/2])
    {
        swap(List, index, ((index-1)/2));
        index = ((index-1)/2);
    }
}

void build_heap(vector<int>& List, int from, int to)
{
    //            
    assert(from>=0&&to>=0&&from<=to&&to<=size(List));
    //                                                                            
    //                                                                                              
    //                                    
    for(int i = from; i<=to; i++)
    {
        if(List[i]>List[(i-1)/2])
        {
            push_up(i, List);
        }
    }
}

int max_child(vector<int>& List, int i, int j)
{
    //             
    assert(i>=0&&j>=0&&i<=size(List)&&j<=size(List));
    //                                                      
    if(List[i]>List[j])
        return i;
    else
        return j;
}

void push_down(int from, int to, vector<int>& List)
{
    //             
    assert(from>=0&&to>=0&&from<=to&&to<=size(List));
    //                                                                                                                
    bool done = false;
    while(!done)
    {
        if(from*2+1<to&&from*2+2<to)//                            
        {
            if(List[(from*2)+1]>List[from]||List[(from*2)+2]>List[from])
            {
                int maxi = max_child(List, from*2+1, from*2+2);
                swap(List, from, maxi);
                from = maxi;
            }
            else
            {
                done = true;
            }
        }
        if(from*2+1<to)
        {
            if(List[from*2+1]>List[from])
                swap(List[from], List[(from*2)+1]);
            else
                done = true;
        }
        else
            done = true;
    }
}

void pick_heap(vector<int>& List,int from,int to)
{
    //             
    assert(from>=0&&to>=0&&from<=to&&to<=size(List));
    //                                                                     
    for(int i = to; i >= from; i--)
    {
        swap(List, i, from);
        cout << "Swap ";
        print_vector(List, to);
        cout << endl;
        push_down(from, i, List);
        cout << "Push down ";
        print_vector(List, to);
        cout << endl;
    }
}

int main()
{
    vector<int> ListA = {4, 8, 10, -2, 16, 5, 0};
    vector<int> ListB = {15, 40, 42, -15, 30, 35, 5};
    const int NUMBER_EL = size(ListA);

    build_heap(ListA, 0, NUMBER_EL-1);
    print_vector(ListA, NUMBER_EL-1);
    cout << endl;
    pick_heap(ListA, 0, NUMBER_EL-1);
    print_vector(ListA, NUMBER_EL-1);
    return 0;
}
/*
       
       
             

       
        
                             
              
               
                  
                   
                    

                             
              
               
                  
                   
                    

                             
              
               
                  
                   
                    

                             
              
               
                  
                   
                    

                            
              
               
                  
                   
                    

                            
              
               
                  
                   
                    

                            
              
               
                  
                   
                    

        
                           
              
               
                  
                   
                    

                            
             
               
                  
                   
                     

                             
              
               
                 
                  
                    

                             
              
                
                   
                   
                    

                              
              
                
                   
                   
                     

                              
               
                
                  
                   
                     

                               
               
                
                  
                   
                     

                               
               
                
                  
                   
                     

                              
                
                
                  
                   
                    

                              
               
                
                   
                   
                    

                              
              
                
                   
                   
                    

                             
               
                
                 
                   
                    

                             
               
                
                 
                   
                    

  
                                      
                                            
                                        
                                           
*/

