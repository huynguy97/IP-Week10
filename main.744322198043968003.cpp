//                        
//                       

#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

/*               
        
                                                        
                                                       
                                                        
                                                  

        
                                                           
                                                          
                                                           
                                                       
                                                            
                                                          
                                         

                
             
                              

                  
                   
                    
                     
                      
                       
                        
                         
                          

                  
                             

                  
                   
                    
                     
                      
                       
                        
                         
                          
                
       		  
                             

                  
                   
                    
                     
                      
                       
                        
                         
                          

       		  
                             

                  
                   
                    
                     
                      
                       
                        
                         
                          

                                                  

             

                              
                              
                              
                              
                              
                              
                              
                              
                              
                              
                              
                              
                              
                        

        

                                     

                                          

                                       

                                         

                                           

               */

void swap(int i, int j, vector<int>& dropbox)
{
	//             
	assert(i <= dropbox.size() && j <= dropbox.size());

	/*              
	                                                          
	                 */

	//               
	int t = dropbox[i];
	dropbox[i] = dropbox[j];
	dropbox[j] = t;	
}

bool push_up(int i,  vector<int>& dropbox)
{
	//             
	assert(0 < dropbox.size());

	/*              
	                                                              
	                                                              
	               */

	//               
	bool heaped = true;  
	while (dropbox[i] > dropbox[((i-1)/2)])
		{
			swap(i, ((i-1)/2), dropbox);
			i = ((i-1)/2);
			heaped = false;
		}
	return heaped;
        
}

bool build_heap(vector<int>& dropbox)
{
	//             
	assert(0 < dropbox.size());

	/*              
	                                                   */
	
	//               
	for(int i = 0; i < dropbox.size(); i++)
	{
		push_up(i, dropbox);
	}
	return push_up;
}

void push_down(int s, int i, vector<int>& dropbox)
{
	//             
	assert(true);

	/*              
	                                                                      
                              	*/

	//                
	int biggest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if (l < s && dropbox[l] > dropbox[biggest])
		biggest=l;

	if (r < s && dropbox[r] > dropbox[biggest])
		biggest=r;

	if(biggest != i)
	{
		swap (i,biggest, dropbox);
		push_down(s, biggest, dropbox);
	}
}

void pick_heap(vector<int>& dropbox)
{
	//             
	assert(build_heap);

	/*              
	                                                         */

	//               
	int s = dropbox.size();
	for(int i = s-1; i >= 0; i--)
	{
		 swap(0, i, dropbox);
		push_down(i, 0, dropbox);
	}
}

int main ()
{
	vector<int> dropbox = {2, 14, 30, 29, 42, 30, 11, -5, 0, 51};
	build_heap(dropbox);
	pick_heap(dropbox);
	for (int i=0; i<dropbox.size(); i++)
        {
                cout << dropbox[i] << ' ';
        }

    return 0;
}

