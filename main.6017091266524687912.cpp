/*
                                 
                                   

                                                                                                                                                                                       
                                                                                                                                          

        

        

                                       
                                         
                                          
                                           
                                            

                                        
                                         
                                          
                                           
                                            
                             
                  

                                        
                                         
                                          
                                           
                                            

                                        
                                         
                                          
                                           
                                            

                                        
                                         
                                          
                                           
                                            
               
                                  

                                  

                                  

                                  

                                  

                                  

                                  

                                  

                                  

                                  
                                
                                  

*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int size(vector<int>& data)
{
    return static_cast<int>(data.size());
}

ostream& operator<< (ostream& out, vector<int>& data) //                                                                                       
{
    out <<"{"<< data[0];
    for(int i=1; i< size(data); i++)
        out << ", " << data[i];
    out<<"}"<< endl;
    return out;
}

int datamax(int a,int b, vector<int>& data) //                                                             
{
    //              
    assert(a < size(data) && b < size(data));
    //               
    //                                                           
    if (data[a]> data[b])
        return a;
    return b;
}

void swap(int& a, int&b)
{
    //              
    assert(true);
    //               
    //                                         
    int c = a;
    a = b;
    b = c;
}

int find_parent(int i)
{
    //              
    assert(true);
    //               
    //                               

    if((i+1)/2 == i/2) //                                                             
       return (i-1)/2;
    return i/2;
}

/*
                                                     
                                                 
                          
                 
*/
void push_up(vector<int>& data, int i)
{
    //            
    assert(true);
    //               
    //                                                            

    int parent = find_parent(i);
    while(data[i] > data[parent])
    {
        swap(data[i], data[parent]);    //                 
        i = parent;                     //                                               
        parent = find_parent(i);
    }

}
/*
                                          
                               
                      
*/
void build_heap(vector<int>& data)
{
    //             
    assert(true);
    //                                    

    for(int i = 1; i < size(data); i++)
    {
        push_up(data,i); //                             
    }
}

/*
                                                     
                                            
                          
                   
*/

void push_down(vector<int>& data, int& heapsize)
{
    //              
    assert(heapsize >= 1);
    //               
    //                                                               

    int i = 0, maxchild;
    bool pushable = true;
    while(pushable && i < heapsize/2)       //                                                                                                     
    {
        maxchild = datamax(2*i+1 , 2*i+2, data); //                                         
        if (data[maxchild] > data[i])
        {
            swap(data[maxchild] , data[i]);
            i = maxchild;
        }
        else
            pushable = false;                   //                                                 
    }
}

/*
                                                      
                                                   
                            
                     
*/

void pick_heap(vector<int>& data, int& heapsize)
{
    //              
    assert(true);
    //               
    //                        

    while(heapsize > 1) //                                                                                                       
    {
        swap(data[0],data[heapsize]);  //                                                                            
        heapsize -= 1;
        push_down(data,heapsize);
    }
}
/*
                                           
                              
                     
*/
int main()
{
    vector<int> data = {2,1,2,4,7,8,84,123,123,12332,4,26,432,21,1,12,6,13,634,64,3,232,21};  //                        
    int heapsize = size(data) - 1;                  //                                                            
    build_heap(data);
    pick_heap(data, heapsize);
    cout<< data << endl;
    return 0;
}

