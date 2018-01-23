/*
Brihi Joshi
OS Assignment 0
2016142
*/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main( int argc,char *argv[3] ){
  int fh,i;
  char buf[2];
  if (argc == 3){
    if (strcmp(argv[1],"-n")==0){
      fh=open(argv[2],O_RDONLY,0777);
      if(fh==-1){
        printf("-posh: cat: %s: Permission denied/file doesn't exist\n",argv[2]);
      }
      else{
        int counter = 1;
        printf("\t%d  ", counter++);
        ssize_t i = read(fh,buf,1);
        while(i>0){
          printf("%c",buf[0]);
          if (buf[0]=='\n'){
            if ((i=read(fh,buf,1))<=0){
              return 0;
            }
            else{
              printf("\t%d  ", counter++);
            }
          }
          else{
            i = read(fh,buf,1);
          }
        }
      }
    }
    else if (strcmp(argv[1],"-e")==0){
      fh=open(argv[2],O_RDONLY,0777);
      if(fh==-1){
        printf("-posh: cat: %s: Permission denied/file doesn't exist\n",argv[2]);
      }
      else{
        ssize_t i = read(fh,buf,1);
        while(i>0){
          if (buf[0]=='\n'){
            printf("$");
            printf("%c",buf[0]);
            if ((i=read(fh,buf,1))<=0){
              return 0;
            }
          }
          else{
            printf("%c",buf[0]);
            i = read(fh,buf,1);
          }
        }
      }
    }
    else{
      printf("-posh: cat: %s: invalid option\n",argv[1]);
    }
  }
  else if (argc == 2){
    if (strcmp(argv[1],"--help")==0){
      printf("cat: usage: cat [-e | -n] [filename]\n");
    }
    else if (strcmp(argv[1],"--version")==0){
      printf("cat v1.0.1\n");
    }
    else{
      fh=open(argv[1],O_RDONLY,0777);
      if(fh==-1){
        printf("-posh: cat: %s: Permission denied/file doesn't exist\n",argv[1]);
        }
      else{
        while((i=read(fh,buf,1))>0){
          printf("%c",buf[0]);
        }
        return 0;
      }
    }
  }
  else{
    printf("cat: usage: cat [-e | -n] [filename]\n");
  }
}
