#include<stdio.h>
#include <string.h>
#include <sys/time.h>


int main(int argc, char const *argv[]) {
  char time_buf[200];
  time_t t;
  struct tm *local_time;

  t = time(NULL);
  local_time = localtime(&t);

  printf("%s",asctime(local_time));
  //printf("%ld\n",t);
}
