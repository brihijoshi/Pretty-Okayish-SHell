#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {
  if (argc == 2){
    remove(argv[1]);
    return 0;
  }
  if (strcmp(argv[1],"-i")==0){
    printf("remove %s? [y/n]",argv[2]);
    char reply[20];
    scanf("%s",reply);
    //printf("%s\n",reply);
    if (strcmp(reply,"y")==0){
      remove(argv[2]);
    }
    else{
      return 0;
    }
  }
  else if (strcmp(argv[1],"-v")==0){
    remove(argv[2]);
    printf("%s\n",argv[2]);
  }
  return 0;
}
