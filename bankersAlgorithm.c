// Bankers Algorithm
// Nathaniel Capeta
// 11.19.22

#include <stdio.h>

int main(){
    const int numProcesses, numResources;
    numProcesses = 5; // Number of processes
    numResources = 3; // Number of resources

    // Allocation matrix
    int allocationMatrix[5][3] = { { 0, 1, 0 },
                        { 2, 0, 0 },
                        { 3, 0, 2 },
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } };

    // Max of matrix
    int maxMatrix[5][3] = { { 7, 5, 3 }, 
                      { 3, 2, 2 }, 
                      { 9, 0, 2 }, 
                      { 2, 2, 2 }, 
                      { 4, 3, 3 } };

    // Resources Available
    int available[3] = { 3, 3, 2 };

    int f[numProcesses], ans[numProcesses], index = 0;
    for (int k = 0; k < numProcesses; k++) {
        f[k] = 0;
    }

    int need[numProcesses][numResources];
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++)
            need[i][j] = maxMatrix[i][j] - allocationMatrix[i][j];
    }

    int y = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < numProcesses; i++) {
            if (f[i] == 0) {
 
                int flag = 0;
                for (int j = 0; j < numResources; j++) {
                    if (need[i][j] > available[j]){
                        flag = 1;
                         break;
                    }
                }
                if (flag == 0) {
                    ans[index++] = i;
                    for (y = 0; y < numResources; y++)
                        available[y] += allocationMatrix[i][y];
                    f[i] = 1;
                }
            }
        }
    }

      int flag = 1;
       
      for(int i=0;i<numProcesses;i++)
    {
      if(f[i]==0)
      {
        flag=0;
         printf("The following system is not safe");
        break;
      }
    }
     
      if(flag==1)
    {
      printf("Following is the SAFE Sequence\n");
      for (i = 0; i < numProcesses - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[numProcesses - 1]);
    }
     
 
    return (0);

}