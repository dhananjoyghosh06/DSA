//Q1. circular Tour
//TC-O(n*n)
//SC-O(1)

#include<iostream>
using namespace std;

class petrolPump{
    public:
    int petrol;
    int distance;
};

// class Problem{
//     public:
//      int circularTour(petrolPump arr[], int n){
//             //taking two pointer
//             int start = 0;  
//             int end = 1;  
  
//             int curr_petrol = arr[start].petrol - arr[start].distance;  
  
//     /* Run a loop while all petrol pumps are not visited.  
//     And we have reached first petrol pump again with 0 or more petrol */
//     while (end != start || curr_petrol < 0)  
//     {  
//         // If current amount of petrol in truck becomes less than 0, then  
//         // remove the starting petrol pump from tour  
//         while (curr_petrol < 0 && start != end)  
//         {  
//             // Remove starting petrol pump. Change start  
//             curr_petrol -= arr[start].petrol - arr[start].distance;  
//             start = (start + 1) % n;  
  
//             // If 0 is being considered as start again, then there is no  
//             // possible solution  
//             if (start == 0)  
//             return -1;  
//         }  
  
//             // Add a petrol pump to current tour  
//             curr_petrol += arr[end].petrol - arr[end].distance;  
    
//             end = (end + 1) % n;  
//         }  
//         return start;
//      }
// };
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int dp =0;
       int rest_petrol = 0;
       int st = 0;
        for(int i=0;i<n;i++){
            rest_petrol += p[i].petrol-p[i].distance;
            if(rest_petrol<0){
                dp +=rest_petrol;
                st=i+1;
                rest_petrol = 0;
                
            }
        }
        if(dp+rest_petrol>=0) return st;
        else{
            return -1;
        }
       
    }
};
int main(){
    Solution a;
    petrolPump p[] = {{4,6},{6,7},{7,9},{4,5}};
    int ans =  a.tour(p,4);

    cout<<"Answer is "<< ans<<endl;

    return 0;
}

// 2nd approach - Queue approach

