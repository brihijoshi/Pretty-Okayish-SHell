/*
Brihi Joshi
OS Assignment 0
2016142
*/

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
      perror("-posh: ls");
      return 0;
    }
    while((d=readdir(p))){
      char* name = d->d_name;
      if (name[0]!='.'){
        //printf("TRUE");
        printf("%s\n",d->d_name);
      }
    }
  }
  else if (argc == 2){
    if (strcmp(argv[1],"-a")==0){
      p=opendir(".");
      if(p==NULL){
        perror("-posh: ls");
        return 0;
      }
      while((d=readdir(p))){
        printf("%s\n",d->d_name);
      }
    }
    else if (strcmp(argv[1],"-i")==0){
      p=opendir(".");
      if(p==NULL){
        perror("-posh: ls");
        return 0;
      }
      while((d=readdir(p))){
        char* name = d->d_name;
        if (name[0]!='.'){
          stat(d->d_name,&s);
          printf("%llu %s\n",s.st_ino,d->d_name);
        }

      }
    }
    else if (strcmp(argv[1],"-help")==0){
      printf("ls: usage: ls[-a | -i]\n");
    }
    else if (strcmp(argv[1],"-version")==0){
      printf("ls v1.0.1\n");

    }
    else if (argv[1][0] == '-'){
      printf("-posh: mkdir: %s: invalid option\n", argv[1]);
    }
    else{
      p=opendir(argv[1]);
      if(p==NULL){
        perror("-posh: ls");
        return 0;
      }
      while((d=readdir(p))){
        printf("%s\n",d->d_name);
      }
    }
  }
  else {
    printf("ls: usage: ls[-a | -i]\n");
  }

  return 0;
}
