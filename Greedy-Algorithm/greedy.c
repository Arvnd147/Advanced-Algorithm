#include<stdio.h>
int main()
{
    float profit[7]={10,15,7,8,9,5,4}; //profit array
    float weight[7]={1,3,5,4,1,3,2}; //respective weight array
    float prowei[7]; //array to store the profit/weight ratio
    //profit and weight can also be taken through input
    int w = 0; //to store the weight
    int a,b; //assisting variables
    float pro=0; //total profit

    for(int i=0;i<7;i++)
    {
        prowei[i]=profit[i]/weight[i]; //the array containing the profit/weight ratios
        //printf("%f ",prowei[i]);
    }
    printf("Order               : ");
    for(int i=0;i<7;i++)
    {
        float temp=0; //temporary varaible
        int max=0; //to find which object has the highest pro/weight ratio
        a=0; //to find the overflow in weight

        for(int j=0;j<7;j++)
        {
            if(prowei[j]>temp) //comparing which obj has the highest raio
            {                  //similar to sorting
                max=j;         //index of the highest ratio is stored
                temp=prowei[j]; //temp stores the value of highest ratio
            }
        }

        printf("%d ",max+1); //prints the sequence of pro/weig in descending oreder
        w = w + weight[max]; /*calculates the total weight,
                             respective weights are added sequentially*/
        if(w>15) //if weight goes beyond 15 kgs
        {
            w=w-weight[max]; //we subtract the last added weight
            a=15-w; //to know how much excess has been added
            b=max; //obj number which causes overload
        }
        pro=pro+profit[max]; //the profit gained by each obj is added sequentially
        prowei[max]=0; 
        //the element in pro/weig array is assigned zero so that next largest number is selected
    }
    //printf("%f", profit[b] / weight[b]); //to find the pro/weig of the overloading object
        pro = pro + (profit[b] / weight[b])-profit[b]; // the last obj is added partially to the total profit
    printf("\nweight distribution : %d + %d \ntotal profit        : %.2f",w,a,pro); //print final result
} 