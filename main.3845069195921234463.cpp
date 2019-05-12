#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

//                                                   
//                                                   
//                                                   

/*

                            

               
                  
                     
                      
                       
                        
                                                                                                        

                  
                     
                      
                       
                        

    
                  
                     
                      
                       
                        
    
                  
                     
                      
                       
                        
    
                  
                     
                      
                       
                        
                                                                                   
                                                                                   
           
                  
                     
                      
                       
                         
                                                                                  
                                                                                                
                                                          
                  
                     
                      
                       
                         
                                             
                  
                     
                      
                       
                        
                                                
                     
           
                  
                     
                      
                       
                         
                                                                                
                   
                     
                      
                       
                         
                                                                 

                    
                    
              
*/

void print(vector<int>& h, int s)
{   //            
    assert(true);
    //                                             

    for(int i=0;i<s;i++)
    {
        cout<<h[i]<<",";
    }
}

void push_up (vector<int>& h, int s, int i)
{   //            
    assert(true);
    //                                                                                                  
    int parent = i;
    int left = 2*i+1;
    int right = 2*i +2;

    if (left<s && h[left]>h[parent]){
        parent = left;
    }

     if (right<s && h[right]>h[parent]){
        parent = right;
    }

    if (parent !=i)
    {
        swap(h[i],h[parent]);
        push_up(h,s,parent);
    }

}
void push_down(vector<int>& h, int s, int i)
{
    int child=i;
    int parent=(i-1)/2;
    if (parent<s && h[parent]>h[child]){
        child = parent;
    }

    if (child !=i)
    {
        swap(h[i],h[child]);
        push_down(h,s,child);
    }

}

void heapsort(vector<int>& h, int s)
{   //            
    assert(true);
    //                                                                                                  
    //                                                                           
    for (int i=h.size()/2; i>=0; i--){
        push_up(h,s,i);
    }
     cout<<endl<<"After creating max heap: ";
    print(h,s);
    for (int i=s; i>=0; i-- )
    {
        swap(h[0],h[i]);
        push_up(h,i,0);
    }

     cout<<endl<<"After sorting: ";
    print(h,s);

}

int main()
{
    vector<int> heap;
    int n,b;
    cout<<"How many element's will you write?"<<endl;
    cin >> n;
    cout<<"Write down all the elements "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>b;
        heap.push_back(b);
    }
    cout<<"This is your elements: ";
    for(int b=0; b<n; b++)
    {
        cout<<heap[b]<<" ";
    }

    int s=heap.size();
    heapsort(heap,s);

    return 0;
}

