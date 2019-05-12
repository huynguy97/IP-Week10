#include <iostream>
#include<cmath>

using namespace std;
//                                
//                             

void push_up(int data[], int length, int index);
bool push_up_fin(int data[], int length);

void build_heap(int data[], int lenght)
{

    for(int i=0; i<lenght; i++)
    {

        {
            push_up(data,lenght,i);
        }
    }

}

void push_up(int data[], int length, int index)
{

    {
        int j=(index-1)/2;
        while (data[index]>data[j] && (index!=0))
        {
            int c=data[index];
            data[index]=data[j];
            data[j]=c;
            index=j;
            j=(index-1)/2;
        }

    }
}

void push_down(int data[], int length, int index)
{

    while(((2*index +1) < length-1) || ((2*index +2) < length-1))
    {

        if(data[index]>data[(2*index +1 )] || (data[index]> data[(2*index +2)]))
        {

            if((2*index+2) < length-1)
            {
                if((2*index+1)<length-1)

                {
                    if(data[(2*index +1)]>data[(2*index+2)])
                    {
                        int c=data[index];
                        data[index]=data[(2*index+1)];
                        data[(2*index+1)]=c;

                    }
                    index=2*index +1;

                }

                else
                {
                    int c=data[index];
                    data[index]=data[(2*index+2)];
                    data[(2*index+2)]=c;

                }
                index=2*index+2;
            }
        }
        else
            index = length;

    }
}

void pick_heap(int data[], int lenght)
{

    for(int k=1; k < lenght; k++)

    {
        int c=data[0];
        data[0]=data[lenght-k];
        data[lenght-k]=c;

        push_down(data,lenght,0);

    }

}

int main()
{
    /*    
                                               
                        
                       
                           
     
                           
     
                 

             */
}

//      
//                                                                         
//                                                                                                                                  
//                                                                     

//      
//                                                                                                     
//                          

//                                      
//                                   

