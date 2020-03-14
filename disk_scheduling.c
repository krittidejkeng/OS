#include <stdio.h>  
#include <stdlib.h> 

#define LOW 0
#define HIGH 199

void FCFS();
void SCAN();

int main()
{
    int i,ans; 

    printf("\nSelect the policy : \n");
    printf("----------------\n");
    printf("1\t FCFS\n");
    printf("2\t SCAN\n");
    printf("3\t EXIT\n");
    printf("----------------\n");
    scanf("%d",&ans);
    switch (ans)
    {
    case 1: printf ("\n FCFS \n");
            FCFS();
        break;

    case 2: printf ("\n SCAN \n");
            SCAN();
        break;    

    case 3: exit(0);
        break;
    }
    return 0;  
}

void FCFS ()
{

  int queue[100], q_size, head, seek =0, diff;
  float avg;

  printf("%s\n", "***FCFS Disk Scheduling Algorithm***");

  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &q_size);

  printf("%s\n", "Enter queue elements");
  for(int i=1; i<=q_size; i++){
    scanf("%d",&queue[i]);
  }
  printf("%s\n","Enter initial head position");
  scanf("%d", &head);
  queue[0]=head;
  for(int j=0; j<=q_size-1; j++){
    diff = abs(queue[j]-queue[j+1]);
    seek += diff;
    printf(" %d ---> %d with Seek %d\n",queue[j],queue[j+1],diff);
  }
  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\t", avg);
}

void SCAN(){
  int queue[20];
  int head, max, q_size, temp, sum;
  int dloc;
  printf("%s\t", "Input no of disk locations");
  scanf("%d", &q_size);

  printf("%s\t", "Enter head position");
  scanf("%d", &head);

  printf("%s\n", "Input elements into disk queue");
  for(int i=0; i<q_size; i++){
    scanf("%d", &queue[i]);
  }
  queue[q_size] = head; 
  q_size++;

  for(int i=0; i<q_size;i++){
    for(int j=i; j<q_size; j++){
      if(queue[i]>queue[j]){
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }
  max = queue[q_size-1];
  for(int i=0; i<q_size; i++){
    if(head == queue[i]){
      dloc = i;
      break;
    }
  }

  if(abs(head-LOW) <= abs(head-HIGH)){

      for(int j=dloc; j>=0; j--){
        printf("%d --> ",queue[j]);
      }
      for(int j=dloc+1; j<q_size; j++){
        printf("%d --> ",queue[j]);
      }
  } 
  else {
      for(int j=dloc+1; j<q_size; j++){
          printf("%d --> ",queue[j]);
      }
      for(int j=dloc; j>=0; j--){
          printf("%d --> ",queue[j]);
      }
  }
  sum  = head + max;
  printf("\nmovement of total cylinders %d", sum);
}