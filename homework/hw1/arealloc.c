#include <stdlib.h>
#include <errno.h>
void* arealloc(void* ptr, size_t nmemb, size_t size){
  if(size && nmemb*size/size == nmemb){
    return realloc(ptr, nmemb*size);
  }
  errno = ENOMEM;
  return NULL;
}
