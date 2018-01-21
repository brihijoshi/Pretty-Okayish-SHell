/*
Brihi Joshi
OS Assignment 0
2016142
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {
  if (argc == 2){
    if (strcmp(argv[1],"--help")==0){
        printf("rm: usage: rm [-i | -v] file\n");
    }
    else if (strcmp(argv[1],"--version")==0){
        printf("rm v1.0.1\n");
    }
    else{
      if (remove(argv[1])==-1){
        perror("-posh: rm");
      }
    }
    return 0;
  }
  else if ( argc == 3){
    if (strcmp(argv[1],"-i")==0){
      printf("remove %s? [y/n]\t",argv[2]);
      char reply[20];
      scanf("%s",reply);
      if (strcmp(reply,"y")==0){
        if (remove(argv[2])==-1){
          perror("-posh: rm");
        }
      }
      else{
        return 0;
      }
    }
    else if (strcmp(argv[1],"-v")==0){
      if (remove(argv[2])==-1){
        perror("-posh: rm");
      }
      else{
        printf("%s\n",argv[2]);
      }
    }
    else{
      printf("-posh: rm: %s: invalid option\n", argv[1]);
    }
    return 0;
  }
  else{
    printf("rm: usage: rm [-i | -v] file\n");
  }
}
