#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

//                                                       
//                                                 

vector<int> elements= {2,14,30,29,42,30,11,-5,0,51};
//                                             

bool check (vector<int> data)
{
    //            
    assert(data.size()>0);
    //                                                                                              
    bool a=true;
    for(int i=1; i<data.size(); i++)
        if(data[i]<data[i-1])
            a=false;
    return a;
}

void show_vector(vector<int> data)
{
    //                                                                             
    for(int i=0; i<data.size(); i++)
        cout<<data[i]<<" ";
    cout<<endl;
}

void swap(vector<int>& data, int i,int j)
{
    //                                                                    

    const int AUX=data[i];
    data[i]=data[j];
    data[j]=AUX;
}

void push_up(vector<int>& data,int id)
{
    //              
    assert(id<data.size() && data.size()>0);
    //                                                                                                                                       
    int a=(id-1)/2,x=0;
    while(x<2)
    {
        if(data[id]>data[a])
        {
            swap(data,a,id);
            id=a;
        }
        a=(a-1)/2;
        if(a==0)
            x++;
    }
}

void build_heap(vector<int>& data)
{
    //             
    assert(data.size()>0);
    //                                             

    for(int i=0; i<data.size(); i++)
        push_up(data,i);
}

void push_down(vector<int>& data,int id,int length)
{
    //              
    assert(data.size()>0 );
    //                                                                                                   

    int a=2*id+1,b=2*id+2;
    while((data[id]<data[a] || data[id]<data[b]) && a<length)
    {
        if(data[b]>data[a] && b<length)
        {
            swap(data,id,b);
            id=b;
        }
        else
        {
            swap(data,id,a);
            id=a;
        }
        a=2*id+1;
        b=2*id+2;
    }
}

void pick_heap(vector<int>& data)
{
    //              
    assert(data.size()>0);
    //                                                 

    int aux=data.size();
    for(int i=0; i<data.size(); i++)
    {
        if(!check(data))
        {
            swap(data,0,aux-1);
            aux--;
            push_down(data,0,aux);
        }

    }
}

int main()
{
    cout<<"Original: ";
    show_vector(elements);

    build_heap(elements);
    cout<<endl<<"After build_heap: ";
    show_vector(elements);

    //                                   
    //                      

    pick_heap(elements);
    cout<<endl<<"After pick_heap: ";
    show_vector(elements);

    return 0;
}

/*
           
                                                                          
                             

                                 
                                 
                  

           
   
            
          
            
              
               
                

          
            
              
               
                

          
            
              
               
                

          
            
              
               
                

          

                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        

    
               
                   
                  
             
                   
                  
                                                
                                                 

*/

