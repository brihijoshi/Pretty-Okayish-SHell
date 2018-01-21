#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]){
  //printf("%d\n",argc);
  if (argc == 3){
    if (strcmp(argv[1],"-v")==0){
      if(mkdir(argv[2], 0777)== -1){
        perror("-posh: mkdir");
        exit(EXIT_FAILURE);
      }
      printf("%s: created directory '%s'\n",argv[0],argv[2]);
    }
    else if (strcmp(argv[1],"-p")==0){
      //printf("%s HERE\n",argv[2]);
      char* sep;
      for (sep=strchr(argv[2]+1,'/'); sep; sep=strchr(sep+1,'/')) {
        // printf("%s\n",sep);
        // printf("%s\n",argv[2]);
        *sep='\0';
        if (mkdir(argv[2], 0777)==-1) {
          //credits for checking errno - https://stackoverflow.com/questions/503878/how-to-know-what-the-errno-means
          if (errno!=EEXIST) {
            *sep='/';
            return -1;
          }
        }
        *sep='/';
      }
      if(mkdir(argv[2], 0777)== -1){
        perror("-posh: mkdir");
        exit(EXIT_FAILURE);
      }
    }
    else{
      printf("-posh: mkdir: %s: invalid option\n", argv[1]);
    }
  }
  else if (argc == 2){
    if (strcmp(argv[1],"--help")==0){
      printf("mkdir: usage: mkdir [-v | -p] directory\n");
    }
    else if(strcmp(argv[1],"--version")==0){
      printf("mkdir v1.0.1\n");
    }
    else{
      if(mkdir(argv[1], 0777)== -1){
        perror("-posh: mkdir");
        exit(EXIT_FAILURE);
      }
    }
  }
  else{
    printf("mkdir: usage: mkdir [-v | -p] directory\n");
  }
  return 0;
}
