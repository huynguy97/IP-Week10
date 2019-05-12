/*  
                 
                              
  */

/*
       
	                                               
	                                              
	                                               
	                                      
	                                                  
	                                            
	                                               
	                                             
	           

       
	          
					  
					   
				         
				          
			               

			  		   
					    
				         
				          
			               

					   
					    
				         
				          
			               

	          

	                       
	                        
	                        
	                        
	                        
	                        
	                        
	                        
	                        
	                        
	                        

	                                           
	                                         
	                                           
	                                           
	                                              

	                                         
	                                          
	                                           
	                                                

	                                             
	                                                   
	                                                   

	                                          
	                                               
	                                                  

*/
#include <vector>
#include <iostream>
using namespace std;

void swap (int a[], int  i, int  j )
{
    const int x = a[i];
	a [i] = a [j] ;
	a [j] = x;
}

void heapify(int a[], int i, int n)
{
    int left, right, largest, loc;
    left= i*2;
    right= (2*i+1);
    if((left<=n)&& a[left]> a[i])
    {
        largest=left;
    }
    else
    {
        largest=i;
    }
    if((right<=n)&&(a[right]>a[largest]))
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(a,i,largest);
        heapify(a,largest,n);
    }
}

void build_heap(int a[],int n)
{
    for(int x = n/2; x>=1; x--)
    {
        heapify(a,x,n);
    }
}

void sortheap(int a[], int n)
{
    build_heap(a,n);
    int temp;
    for (int i=n; i>=2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        heapify(a,1,i-1);
    }
}

//                                    
void vswap ( vector<int>& v, int  i, int  j )
{
    const int x = v[i];
	v [i] = v [j] ;
	v [j] = x;
}

void vheapify(vector<int>& v, int i, int n)
{
    int left, right, largest, loc;
    left = i*2;
    right = (2*i+1);
    if((left<=n)&& v[left]> v[i])
    {
        largest=left;
    }
    else
    {
        largest=i;
    }
    if((right<=n)&&(v[right]>v[largest]))
    {
        largest=right;
    }
    if(largest!=i)
    {
        vswap(v,i,largest);
        vheapify(v,largest,n);
    }

}

void vbuild_heap(vector<int>& v, int n)
{
    for(int x = n/2; x>=1; x--)
    {
        vheapify(v,x,n);
    }
}

void vsortheap(vector<int>& v, int n)
{
    vbuild_heap(v,n);
    int temp;
    for (int i=n; i>=2; i--)
    {
        vswap(v,i,1);
        vheapify(v,1,i-1);
    }
}

int main()
{

    int n, choice;
    cout << "Would you prefer: \n (1) Array \n (2) Vector \n (3) Exit \n";
    cin >> choice;
    if(choice == 1)
    {
        cout << "Enter the size of the array"<<endl;
        cin >> n;
        int a[n];
        cout<<"Enter the elements in the array"<<endl;
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }
        sortheap(a, n);
        cout<<"This is what the array looks like when sorted" <<endl;
        for (int i = 1; i <= n; i++)
        {
            cout<<a[i]<<endl;
        }
    }
    else if (choice == 2)
    {
        vector<int> ivector;
        int temp, check = 0;
        cout << "To stop entering values simply enter any non number symbol and hit enter" << endl;
		while(cin >> temp)
		{
		    ivector.push_back(temp);
		    cout << ivector[check] << endl;
			check ++;
			cout << "Enter element #" << check +1 << endl;
		}
		vsortheap(ivector,ivector.size());
		cout << "The vector looks as follows after sorting"<< endl;
		for (int i = 1; i <= ivector.size(); i++)
        {
            cout<<ivector[i]<<endl;
        }

    }
    else if (choice == 3)
    {
		cout << "shutting down";
        return 0;
    }
    else
    {
        cout << "please choose either (1) or (2) for Array or Vector";
    }
}

