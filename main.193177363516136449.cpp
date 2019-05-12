#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

/*                                            

                                                                                  
                                                                                 

       
                                                                                                                                  
                                                                                                                                                                               

       
                                        
             
         	    
	    		  
	                
   		  	  		 

                                             
            
        	   
	             
                   
   		  	  		 

                                             
             
		       
	    	      
	                
   		  	   		 

                                             
             
        	    
	  		      
                    
   		  	  		 

                                        
                      

                                  
                      

                                       
                      

                                  
                      

                                       
                      

                                  
                      

                                       
                      

                                  
                      

                                       
                      

                                  
                      

                                       
                      

                                                                                                       

           
                                                                                                                                                                    

	           
                                                                                                                                                                                   

	          
                                                                                                                                                                                                                                               

	          

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
*/

//                                                                                                                                                       

vector<int> test = {15, 40, 42, -15, 30, 35, 5};

bool push_up(vector<int>& vect,int vsize)
{
    assert(vsize>0);
    //                                                                                                                                                  
    //                                                                   
    bool swapped=false;
    int c=0;
    while(!swapped&&c<vsize){
        int p=(c-1)/2;  //                       
        if(vect[c]>vect[p]&&c!=0){
            const int a=vect[p];
            vect[p]=vect[c];
            vect[c]=a;
            swapped=true;}
        else{
            c++;}
    }
    return swapped;
}

void build_heap(vector<int>& vect,int vsize)
{
    assert(vsize>0);
    //                                                                                                    
    while(push_up(test,vsize));
}

void display_vector(vector<int>& vect,int vsize)
{
    assert(vsize>0);
    //                                                                                     
    for(int i=0;i<vsize;i++){
        cout<<vect[i]<<',';}
    cout<<endl;
}

void push_down(vector<int>& vect, int& b){
    assert(true);
    //                                                                                                                                 
    //                                                                                                                                                  
    //                                                                                                                                                                
    for(int a=0; a<b; a++){
        int child1=2*a + 1;
        int child2=2*a + 2;
        if(vect[a]<vect[child1]||vect[a]<vect[child2]){
            if(vect[child1]>vect[child2]&&child1<b){
                const int HELP=vect[child1];
                vect[child1]=vect[a];
                vect[a]=HELP;}
            else if (child2<b){
                const int HELP=vect[child2];
                vect[child2]=vect[a];
                vect[a]=HELP;}
        }
    }
}

void swap_heap(vector<int>& vect, int& b){
    assert(true);
    //                                                                                                                           
    b--;
    const int a = vect[b];
    vect[b]=vect[0];
    vect[0]=a;
}

void pick_heap(vector<int> vect,int vsize){
    assert(vsize>0);
    //                                                                                           
    int b=vsize;
    while(b>0){
        swap_heap(test, b);
        push_down(test, b);
    }
}

int main()
{
    int vsize=test.size();
    build_heap(test,vsize);
    display_vector(test,vsize);
    pick_heap(test,vsize);
    display_vector(test,vsize);
    return 0;
}

