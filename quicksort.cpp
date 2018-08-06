
#include<stdio.h>

int partition(int* A, int p, int r) {

  int x = A[r];
  int i = p-1;
  int tmp;

  for(int j = p; j < r;j++) {
      
            if(A[j] <= x) {

               i = i + 1;
               
               tmp = A[j];
               A[j] = A[i];
               A[i] = tmp;
               
            }
  }

  tmp = x;
  A[r] = A[i+1];
  A[i+1] = tmp;
  
 return i+1;
 
}

void quicksort(int* A, int p, int r, int s) {
 
  if(p < r) {
     int q = partition(A, p, r);
     quicksort(A, p, q-1, s);
     quicksort(A, q+1, r, s);
  }
}

int main() {

    int A[] = {23, 12, 1, -5, 34, 11, 9, 4, 3, 3, -1};

    int s = sizeof(A)/sizeof(A[0]);
    
    printf("BEFORE SORT: \n");
    for(int i = 0; i < s;i++){
        printf("%d\t", A[i]);
    }
    printf("\n");
    
    quicksort(A, 0, s-1, s);

    printf("AFTER SORT: \n");
    for(int i = 0; i < s;i++){
        printf("%d\t", A[i]);
    }
    printf("\n");

}
