#include<stdio.h>
#include <string.h>
#include <sys/time.h>


int main(int argc, char const *argv[]) {
  char time_buf[200];
  time_t t = time(NULL);

  if (argc == 1){
    struct tm *local_time = localtime(&t);
    //printf("%s\n",local_time->tm_zone);
    switch (local_time->tm_wday) {
      case 0: printf("Sun");
              break;
      case 1: printf("Mon");
              break;
      case 2: printf("Tue");
              break;
      case 3: printf("Wed");
              break;
      case 4: printf("Thu");
              break;
      case 5: printf("Fri");
              break;
      case 6: printf("Sat");
              break;
    }


    switch (local_time->tm_mon) {
      case 0: printf(" Jan");
              break;
      case 1: printf(" Feb");
              break;
      case 2: printf(" Mar");
              break;
      case 3: printf(" Apr");
              break;
      case 4: printf(" May");
              break;
      case 5: printf(" Jun");
              break;
      case 6: printf(" Jul");
              break;
      case 7: printf(" Aug");
              break;
      case 8: printf(" Sep");
              break;
      case 9: printf(" Oct");
              break;
      case 10: printf(" Nov");
              break;
      case 11: printf(" Dec");
              break;
    }

    printf(" %d",local_time->tm_mday);
    printf(" %02d:%02d:%02d",local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
    printf(" %s",local_time->tm_zone);
    printf(" %d\n",local_time->tm_year+1900);
  }
  else if (argc == 2){
    if (strcmp(argv[1],"-u")==0){
      struct tm *gmt_time = gmtime (&t);
      switch (gmt_time->tm_wday) {
        case 0: printf("Sun");
                break;
        case 1: printf("Mon");
                break;
        case 2: printf("Tue");
                break;
        case 3: printf("Wed");
                break;
        case 4: printf("Thu");
                break;
        case 5: printf("Fri");
                break;
        case 6: printf("Sat");
                break;
      }


      switch (gmt_time->tm_mon) {
        case 0: printf(" Jan");
                break;
        case 1: printf(" Feb");
                break;
        case 2: printf(" Mar");
                break;
        case 3: printf(" Apr");
                break;
        case 4: printf(" May");
                break;
        case 5: printf(" Jun");
                break;
        case 6: printf(" Jul");
                break;
        case 7: printf(" Aug");
                break;
        case 8: printf(" Sep");
                break;
        case 9: printf(" Oct");
                break;
        case 10: printf(" Nov");
                break;
        case 11: printf(" Dec");
                break;
      }

      printf(" %d",gmt_time->tm_mday);
      printf(" %02d:%02d:%02d",gmt_time->tm_hour,gmt_time->tm_min,gmt_time->tm_sec);
      printf(" %s",gmt_time->tm_zone);
      printf(" %d\n",gmt_time->tm_year+1900);
    }
  }

}
