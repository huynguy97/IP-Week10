#include <iostream>
#include<cassert>
#include<cstring>

using namespace std;

//                                           
//                                           

const int arraysize=7;
int TEST[10]={2, 14, 30, 29, 42, 30, 11, -5, 0, 51};
int A[7]={15, 40, 42, -15, 30, 35, 5};

bool is_sorted()
{
//	               
//	                                       
	bool sorted = true ;
	for (int i = 0; i < arraysize-1; i++)
		if (A[i] > A[i+1])
			sorted = false ;
    if(sorted==true)
        cout << "Sorted!";
	return sorted;
}

void show_A()
{
    cout << "{" << A[0];
    for(int i=1; i<arraysize; i++)
        cout << ", " << A[i];
    cout << "}" << endl;
}

bool push_up(int pos)
{
    //         
    //         
    //     
    //             
    //             

    int posparent=0;
    if(pos==0)
        return false;
    else if((pos-1)%2==0)        //                                                            
        posparent=(pos-1)/2;
    else
        posparent=(pos-2)/2;
    if(A[pos]>A[posparent])
    {
        cout << "Pushing up " << A[pos] << " from position " << pos << " to position " << posparent << endl;
        int HELP=A[posparent];
        A[posparent]=A[pos];
        A[pos]=HELP;
        return true;
    }
    return false;
}

void build_heap(int to)
{
    cout << endl << "Building heap..." << endl;
    int counter=0;
    while(counter<to)
    {
        for(int i=0; i<to; i++)
        {
            if(!push_up(i)){
                counter++;}
        }
        if(counter<to)
            counter=0;
    }
    cout << "Heap built, A=";
    show_A();
    cout << endl;
}

void swap_el(int to)
{
    cout << "Swapping el0 " << A[0] << " with el" << to << " " << A[to];

    int HELP=A[to];
    A[to]=A[0];
    A[0]=HELP;
    cout << endl;
}

void push_down(int pos, int unsorted)
{
    int temppos=pos;
    while((A[temppos]<A[(temppos*2)+1] && (temppos*2)+1<unsorted  ) || (A[temppos]<A[(temppos*2)+2] && (temppos*2)+2<unsorted))
    {
        if(A[temppos]<A[(temppos*2)+1] && A[temppos]<A[(temppos*2)+2] && (temppos*2)+1<unsorted && (temppos*2)+2<unsorted)
        {
            if(A[(temppos*2)+1]<A[(temppos*2)+2])
            {
                cout << "Pushing " << A[temppos] << " down from pos " << temppos << " to pos " << (temppos*2)+2 << "." << endl;
                int HELP=A[(temppos*2)+2];
                A[(temppos*2)+2]=A[temppos];
                A[temppos]=HELP;
                temppos=(temppos*2)+2;
            }
            else
            {
                cout << "Pushing " << A[temppos] << " down from pos " << temppos << " to pos " << (temppos*2)+1 << "." << endl;
                int HELP=A[(temppos*2)+1];
                A[(temppos*2)+1]=A[temppos];
                A[temppos]=HELP;
                temppos=(temppos*2)+1;
            }
        }
        else if(A[temppos]<A[(temppos*2)+1] && (temppos*2)+1<unsorted)
        {
            cout << "Pushing " << A[temppos] << " down from pos " << temppos << " to pos " << (temppos*2)+1 << "." << endl;
            int HELP=A[(temppos*2)+1];
            A[(temppos*2)+1]=A[temppos];
            A[temppos]=HELP;
            temppos=(temppos*2)+1;
        }
        else if(A[temppos]<A[(temppos*2)+2] && (temppos*2)+2<unsorted)
        {
            cout << "Pushing " << A[temppos] << " down from pos " << temppos << " to pos " << (temppos*2)+2 << "." << endl;
            int HELP=A[(temppos*2)+2];
            A[(temppos*2)+2]=A[temppos];
            A[temppos]=HELP;
            temppos=(temppos*2)+2;
        }
    }
}

void pick_heap()
{
    build_heap(arraysize);
    cout << "Heap sorting..." << endl;

    int i=arraysize-1;
    while(!is_sorted())
    {
        swap_el(i);
        push_down(0, i);
        cout << "A=";
        show_A();
        cout << endl;
        if(i>0)
            i--;
    }
}

int main()
{
    cout << "A=";
    show_A();
    pick_heap();
    return 0;
}

/*
                                                  
  
                                                  
     
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
     
                        
                                             

  
                                       
     
                    
                          
                                                                                
          
                                  
                           
          
                      
     
                                                                                               
                                  
                                                  

                                                  
  
           
                                    
                                  
                                   
                                    
                                      
                                       
                                        
                        
                                               
                                                                   
                                    
                                  
                                   
                                    
                                      
                                       
                                        
                                                                   
                                    
                                  
                                   
                                    
                                      
                                       
                                        
                                                                      
                                                                   
                                    
                                  
                                   
                                    
                                      
                                       
                                        
                                                                     
                                                                    

                                               
                                             
                                             
                                              
                                             
                                             
                                            

                               
                                    
                         
                                  
                                   
                                    
                                      
                                       
                                        
           
                                    
                              
                                    
                                 
                                    
                                 
                                    

                              
                                    
                                 
                                    

                               
                                    
                                  
                                    

                                
                                    
                                   
                                    

                              
                                    

                               
                                    

  
           			    
              		                                          
             		                   
             		                                       
*/

