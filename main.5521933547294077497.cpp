#include <iostream>
#include <vector>

using namespace std;

//                        

void push_up(vector<int> &vec, int index)
{
    //                                                                
    //                                                                 
    int cache;
    if(index == 0)
        return void(); //        
    if(vec[index] > vec[(index-1)/2])
    {
        cache = vec[index];
        vec[index] = vec[(index-1)/2];
        vec[(index-1)/2] = cache;
        push_up(vec,(index-1)/2);
    }

}
void push_down(vector<int> &vec, int index, int sizea)
{
    //                                                                
    //                                                               
    int cache;
    int swapindex;
    if(index*2+1 > sizea-1)
        return void(); //                          
    else if(index*2+2 >sizea-1)
    {
        //                                                 
        if(vec[index] < vec[index*2+1])
        {
            swapindex = index*2+1;
            cache = vec[index];
            vec[index] = vec[swapindex];
            vec[swapindex] = cache;
        }
    }
    else if(vec[index] < vec[index*2+1] || vec[index] < vec[index*2+2])
    {
        //                       
        swapindex = vec[index*2+1] > vec[index*2+2] ? index*2+1 : index*2+2;
        cache = vec[index];
        vec[index] = vec[swapindex];
        vec[swapindex] = cache;
        push_down(vec,swapindex,sizea);
    }

}

void build_heap(vector<int> &vec,int sizea)
{
    //                         
    for(int i=0; i< sizea;i++)
    {
        push_up(vec,i);
    }
}

void swap(vector<int> &vec,int sizea)
{
    //                                
    int cache;
    cache = vec[0];
    vec[0] = vec[sizea-1];
    vec[sizea-1] = cache;
}

void pick_heap(vector<int> &vec, int sizea)
{
    //                 
    while(sizea > 0)
    {
        swap(vec, sizea);
        sizea --;
        push_down(vec, 0, sizea);
    }
}

void fill_vec(vector<int>& vec,int input[],int sizea)
    {
        //                              
        for(int i=0; i< sizea; i++)
        {
            vec.push_back(input[i]);
        }
    }

int main()
{
    //             
    int unsorted[] = {2,14,30,29,42,30,11,-5,0,51};
    vector<int> myvec;
    fill_vec(myvec, unsorted, 10);
    build_heap(myvec, 10);
    pick_heap(myvec, 10);
    for(int a = 0; a< 10; a++)
    {
        cout << myvec[a]<< " ";
    }
    return 0;
}

/*            
      
        
              

  
   
               
                                
                                
                                
                                
              
                                
                            
                            
                            
              
                            
                        
                        
                        
              
                        
                    
                    
              
                    
                
                
              
                
            
            
              
            
         
              
         
      

   
                      
                           
                        
                          
*/

