#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
//                                          
/*
                 
                                                                                                              
                                                                                                                                                                                                            

                 
                                                                                                    
     
             
                    
                       
     
             
                    
                       
     
             
                    
                       
                                                  
             
                    
                       
                                               
                          
     
                        

     
                        

     
                        

     
                          

     
                          

     
                            

     
                              

     
                              

     
                                

      
                                  

      
                                    
    
        
                                                                                                                                                                               
                                                                                                                                                                                                                     
                                                                                                                     
                                                                                                                                                                                                                                                             
                                                                                                                                                                     
*/
using namespace std;
void swap (vector<int>& v, int index_a, int index_b) //                       
{
    assert(index_a>=0 && index_b>=0 && index_b<v.size()&&index_a<v.size());//                 
    int memory = v[index_a];
    v[index_a]=v[index_b];
    v[index_b]=memory;
}

void push_up(vector<int>& v,int child_index)
{
    assert(child_index>=0 && child_index<v.size());//                                                                                       
    int parent_index=(child_index-1)/2;
    while (v[child_index]>v[parent_index]) //                                                                                              
    {
        swap(v,child_index,parent_index);
        child_index=parent_index; //               
        parent_index=(child_index-1)/2; //                         
    }
}
void build_heap(vector<int>& v) //                                                                   
{
    assert(true);
    int to_push_up=v.size(); //                                                                                               
    for (int element=1;element<to_push_up;element++)//                                                                                                                                    
        push_up(v,element);
}
void push_down(vector<int>& v, int limit) //                                                                                        
{
    assert(limit<v.size()&&limit>=0); //                                            
    int current_index=0;  //                 
    int child_index1=1;   //                            
    int child_index2=2;
    int child_index;      //                         
    if (v[child_index1]>=v[child_index2] || limit==1) //                                                      
        child_index=child_index1;
    else
        child_index=child_index2;
    bool current_is_smaller=true; //                        
    while (child_index<=limit && current_is_smaller)//                                                             
    {
        if (v[current_index]>=v[child_index])
            current_is_smaller=false; //                                                                          
        else
        {
            swap(v,current_index,child_index);
            current_index=child_index;//             
            child_index1=(current_index*2)+1;//                         
            child_index2=child_index1+1;
            if (v[child_index1]>=v[child_index2] || limit==child_index1) //                                                            
                child_index=child_index1;
            else
                child_index=child_index2;
        }
    }
}
void pick_heap(vector<int>& v) //                                        
{
    assert(true);
    int vectorsize=v.size();//                             
    swap(v,0,vectorsize-1);//                                                                                               
    for (int elements=vectorsize-2;elements>0;elements--)//                          
    {
        push_down(v,elements);//                                                 
        swap(v,0,elements); //                                     
    }
}
void heap_sort(vector<int>& v) //        
{
    assert(true);
    build_heap(v);//     
    pick_heap(v);//         
    //       
}
int main()
{
    vector<int> v={1,2,3,4,5,6,7,20,1,44,6,1,35,6,1,6,81,7,0,-4,6,4,15,7373,12,39};//                     
    cout<<"pre sort:\n{";
    for (int i=0;i<v.size()-1;i++)
        cout<<v[i]<<",";
    cout<<v[v.size()-1]<<"}\n";
    heap_sort(v);
    cout<<"post sort:\n{";
    for (int i=0;i<v.size()-1;i++)
        cout<<v[i]<<",";
    cout<<v[v.size()-1]<<"}\n";
    return 0;
}

