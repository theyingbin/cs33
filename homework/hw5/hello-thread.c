#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread(void* vargp);

int main(int argc, const char* argv[]){
  if(argc != 2){
    printf("Wrong number of arguments\n");
    return 1;
  }
  int num=atoi(argv[1]);
  pthread_t tid[num];
  int i;
  int created;
  for(i=0;i<num;i++){
    created=pthread_create(&tid[i], NULL, thread, NULL);
  }
  for(i=0;i<num;i++){
    pthread_join(tid[i], 0);
  }
  exit(0);
}

void* thread(void* vargp){
  printf("Hello, world!\n");
  return NULL;
}
