#include<stdio.h>
#include<fcntl.h>
#include <string.h>


int main( int argc,char *argv[3] ){
  int fh,i;
  char buf[2];
  printf("%s\n",argv[1]);
  if (strcmp(argv[1],"-n")==0){
    fh=open(argv[2],O_RDONLY,0777);
    if(fh==-argc){
      printf("file open error");
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
    if(fh==-argc){
      printf("file open error");
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
    fh=open(argv[1],O_RDONLY,0777);
    if(fh==-argc){
      printf("file open error");
      }
    else{
      while((i=read(fh,buf,1))>0){
        printf("%c",buf[0]);
      }
      return 0;
    }
  }
}