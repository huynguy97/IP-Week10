#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
                         
                  

                     
                  
*/

/*
                                                
   
                                                  
                                                     
                                      
                                
   
                                                  
                                     
                                                                              
                                                                                                            
                                                

                               
   
                        
                                                                                
       
         
           
            
             

       
         
           
            
             

       
         
           
            
             
                          
                                                            
                         
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
   
                                                                                      
                                            
                                                               
                                                                
                                                      
                                                                                       
                                        
                                                             
*/

/*                                      */

void swap(vector<int> &v, int parent, int child) {
    //               
    assert(parent >= 0 && parent < v.size() && child >= 0 && child < v.size());
    //                
    //                                                  
    const int TMP = v[parent];
    v[parent] = v[child];
    v[child] = TMP;
}

int maxv(vector<int> &v, int a, int b) {
    //               
    assert(a >= 0 && a < v.size() && b >= 0 && b < v.size());
    //                
    //                                      
    //                               
    if(v[a] > v[b]) return a;
    else return b;
}

void push_up(vector<int> &v, int child) {
    //               
    assert(child >= 0 && child < v.size());
    //                
    //                                    
    //                                 
    int parent = (child-1)/2;
    if(parent < 0 || parent > v.size()) return;
    while(v[child] > v[parent]) {
        swap(v, child, parent);
        child = parent;
        parent = (child-1)/2;
        if((child < 0 || child > v.size()) || (parent < 0 || parent > v.size())) return;
    }
}

void push_down(vector<int> &v, int parent, int heapsize) {
    //               
    assert(parent >= 0 && parent < v.size());
    //                
    //                                                    
    //                                               
    //                                      
    int child1 = 2*parent+1;
    int child2 = 2*parent+2;
    if((child1 < 0 || child1 > heapsize) && (child2 < 0 || child2 > heapsize)) return;
    int maxchild = maxv(v, child1, child2);
    while(v[parent] < v[maxchild]) {
        if(v[parent] < v[maxchild]) {
            swap(v, parent, maxchild);
            parent = maxchild;
        } else return;
        child1 = 2*parent+1;
        child2 = 2*parent+2;
        if((child1 > 0 && child1 <= heapsize)) {
           if (child2 > heapsize)
                maxchild = child1;
           else
                maxchild = maxv(v, child1, child2);
        }
    }
}

void build_heap(vector<int> &v) {
    //               
    assert(true);
    //                
    //                           
    for(int i = 0; i < v.size(); i++) push_up(v,i);
}

void pick_heap(vector<int> &v) {
    //               
    assert(true);
    //                
    //                                   
    int heapsize = v.size()-1;
    while(heapsize != 0) {
        swap(v, 0, heapsize);
        heapsize--;
        if(heapsize == 1) {
            if(v[heapsize] < v[0]) swap(v, 0, heapsize);
            return;
        }
        push_down(v, 0, heapsize);
    }
}

int main()
{
    vector<int> v = {390,196,433,188,216,288,170,484,280,450,401,58,415,215,374,271,126,59,498,52,88,353,4,372,402,114,166,289,455,165,68,6,258,316,257,84,284,144,371,254,145,315,189,69,135,350,226,139,85,207,51,267,476,125,116,323,306,48,121,56,105,35,397,211,428,446,248,351,365,261,203,441,39,12,295,210,172,293,273,317,95,179,86,361,336,29,492,198,200,153,120,321,302,250,298,411,217,453,332,357};
    build_heap(v);
    pick_heap(v);
    cout << "Sorted list" << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

