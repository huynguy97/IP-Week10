//                                                 
//                                                                   
/*             
       
                                                                                 
                                                                                                   
                                                                                   
                                                                          
       
            
                                                      

       
     
                                                     

       
     
                                                   

       
        
                                                              

       
        
                                                                            

       
        
          
  
                                                            

       
        
          
     
                                                                         

       
        
          
     
                                                             

       
        
          
         
                                                          

       
        
          
           
                                                                              

        
                                                                                     
                                                 
                                                            
                                                           
                                                      
                                                           
                                                   
                                                           
                                                    
                                                           
                                                     
                                                           
                                                                            

                                                                  
                                                                             
                                         
                                                                                                                

                                                                                     
                                                                                                

                                                                                      
                                                                           
                                                                                             
                       
             */
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

int parent_index(int pos){
    //              
    assert(pos>=0);
    //                                                                                                     
    if(pos==0){return -1;}
    return (pos-1)/2;
}

int size(vector<int>& vals){
    //              
    assert(true);
    //                                                          
    return static_cast<int>(vals.size());
}

void swap(vector<int>& vals, int pos_a, int pos_b){
    //              
    assert(size(vals)>pos_a && size(vals)>pos_b && pos_a>=0 && pos_b>=0);
    //                                                                       
    const int TEMP= vals[pos_a];
    vals[pos_a]=vals[pos_b];
    vals[pos_b]=TEMP;
}
//       
void push_up(vector<int>& vals, int pos){
    //              
    assert(pos>=0);
    //                                                                                             
    int parent_pos=parent_index(pos);
    while(parent_pos!=-1 && vals[parent_pos]<vals[pos]){
        swap(vals,parent_pos,pos);
        pos=parent_pos;
        parent_pos=parent_index(pos);
    }
}

void build_heap(vector<int>& vals){
    //              
    assert(true);
    //                                         
    for(int i=0;i<size(vals);i++){
        push_up(vals,i);
    }
}

//       
vector<int> children(int pos, int len){
    //              
    assert(len>=pos);
    //                                                                           
    //                                 
    int child1=2*pos+1;
    if(child1>=len){child1=pos;}
    int child2=2*pos+2;
    if(child2>=len){child2=pos;}
    vector<int> ret={child1,child2};
    return ret;
}
void push_down(vector<int>& vals, int len){
    //              
    assert(len<size(vals));
    //                                                                            
    //                                                                                           
    swap(vals,0,len);
    int pos=0;
    vector<int> child_pos=children(pos,len);
    int bigger_child=((vals[child_pos[0]]>vals[child_pos[1]])?child_pos[0]:child_pos[1]);
    while(vals[bigger_child]>vals[pos]){
        swap(vals,pos,bigger_child);
        pos=bigger_child;
        child_pos=children(pos,len);
        bigger_child=((vals[child_pos[0]]>vals[child_pos[1]])?child_pos[0]:child_pos[1]);
    }
}

void pick_heap(vector<int>& vals){
    //              
    assert(true);
    //                             
    for(int sorted_sep=size(vals)-1;sorted_sep>0;sorted_sep--){
        push_down(vals,sorted_sep);
    }
}

int main()
{
    //              
    assert(true);
    //                                                                        
    vector<int> vals={2,14,30,29,42,30,11,-5,0,51};
    build_heap(vals);
    pick_heap(vals);
    for(int i=0;i<size(vals);i++){
        cout<<vals[i]<<((i==size(vals)-1)?"\n":", ");
    }
    return 0;
}

