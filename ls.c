#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  DIR *p;
  struct dirent *d;
  char buf[512];
  struct stat s;
  struct passwd *t;
  struct group *g;

  if (argc == 1){
    p=opendir(".");
    if(p==NULL){
      perror("Cannot find directory");
      return 0;
    }
    while((d=readdir(p))){
      char* name = d->d_name;
      if (name[0]!='.'){
        //printf("TRUE");
        printf("%s\n",d->d_name);
      }
      //printf("%s\n",d->d_name);

    }
  }
  else if (argc == 2){
    if (strcmp(argv[1],"-a")==0){
      p=opendir(".");
      if(p==NULL){
        perror("Cannot find directory");
        return 0;
      }
      while((d=readdir(p))){
        printf("%s\n",d->d_name);
      }
    }


    else if (strcmp(argv[1],"-l")==0){
  
    }
    else{
      p=opendir(argv[1]);
      if(p==NULL){
        perror("Cannot find directory");
        return 0;
      }
      while((d=readdir(p))){
        printf("%s\n",d->d_name);
      }
    }
  }

  return 0;
}
