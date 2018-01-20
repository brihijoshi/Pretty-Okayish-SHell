#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char* BUILTINS[5] = {"cd",
                  "echo",
                  "history",
                  "pwd",
                  "exit"};

int is_builtin(char* cmd){
  for (int i=0;i<5;i++){
    if (strcmp(cmd,BUILTINS[i])==0){
      return 1;
    }
  }
  return 0;
}

void posh_cd(char *args[100]){
  if (strcmp(args[1],"--help")==0){
    printf("cd: usage: cd [dir]\n");
  }
  else if (strcmp(args[1],"--version")==0){
    printf("cd v1.0.1\n");
  }
  else if (args[1][0] == '-'){
    printf("-posh: cd: %s: invalid option\n",args[1]);
  }
  else{
    if (chdir(args[1]) == -1){
      printf("-posh: cd: %s: No such file or directory\n", args[1]);
    }
  }
}

void posh_echo(char *args[100], int temp){
  int len = 0;
  int num_words = 0;
  char* str;
  //checking for flags
  if (strcmp(args[1],"-n") == 0){
    for (int i=2;i<temp-1;i++){
      num_words++;
      len = len + strlen(args[i]);
    }
    str = malloc(len+num_words+1);
    for (int i =2;i<temp-1;i++){
      strcat(str,args[i]);
      strcat(str," ");
    }
    str[strlen(str)-2]= '\0';
    printf("%s",str);
  }
  else if (strcmp(args[1],"-e")==0){
    char *s = args[2];
    char c;
    while ((c = *s++)){
      if (c == '\\' && *s){
          switch (c = *s++){
            case 'a': c = '\a'; break;
            case 'b': c = '\b'; break;
            case 'e': c = '\x1B'; break;
            case 'f': c = '\f'; break;
            case 'n': c = '\n'; break;
            case 'r': c = '\r'; break;
            case 't': c = '\t'; break;
            case 'v': c = '\v'; break;
            default:  putchar ('\\'); break;
          }
        }
      putchar (c);
    }
  }
  else{
    for (int i =1;i<temp-1;i++){
      num_words++;
      len = len + strlen(args[i]);
    }
    str = malloc(len+num_words+1);
    for (int i =1;i<temp-1;i++){
      strcat(str,args[i]);
      strcat(str," ");
    }
    printf("%s\n",str);
  }
}

void posh_pwd(char *args[100]){
  if (strcmp(args[1],"--help")==0){
    printf("The pwd utility writes the absolute pathname of the current working directory to the standard output.\n");
  }
  else if (strcmp(args[1],"--version")==0){
    printf("pwd v1.0.1\n");
  }
  else if (strcmp(args[1],"-L")==0){
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n",cwd);
  }
  else{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n",cwd);
  }
}

void posh_history(char *args[100]){
  //https://ss64.com/bash/history.html
  if(strcmp(args[1],"-c")==0){
    FILE *fr = fopen(".posh_history","w");
  }
  else if (strcmp(args[1],"-w")==0){
    FILE *new_fr = fopen(args[2],"w");
    FILE *fr = fopen(".posh_history","r");
    int line_num;
    char command[255];
    char ch = fgetc(fr);
    while (ch != EOF){
        fputc(ch,new_fr);
        ch = fgetc(fr);
    }
    fclose(fr);
    fclose(new_fr);
  }
  else{
    FILE *fr = fopen(".posh_history","r");
    //printf("%d\n",&fr);
    int line_num;
    char command[255];
    char ch = fgetc(fr);
    while (ch != EOF){
        printf ("%c", ch);
        ch = fgetc(fr);
    }
    fclose(fr);
  }
}





int main() {
  char* param = malloc(128*sizeof(char*));
  char* sep;
  char* args[100]; //Assuming 100 args at max
  size_t buf = 0;
  int hist_index = 1 ;

  while (1){
    printf("posh >>> ");
    //fgets(param, 80, stdin);
    getline(&param, &buf, stdin);
    if (strcmp(param,"\n")==0){
      continue;
    }
    FILE *fw = fopen(".posh_history", "a");
    fprintf(fw,"%d %s",hist_index++,param);
    fflush(fw);
    //printf("%s",param);
    int temp=0;
    while ((sep = strsep(&param," \n")) != NULL){
    //  printf("THIS IS SEP %s ", sep);
      args[temp] = sep;
      temp++;
    }

    if (strcmp(args[0], "exit")==0){
      break;
    }

    else if (strcmp(args[0],"cd") == 0){
      posh_cd(args);
    }

    else if (strcmp(args[0],"echo") == 0){
      posh_echo(args,temp);
    }

    else if (strcmp(args[0],"pwd")==0){
      posh_pwd(args);
    }

    else if (strcmp(args[0],"history")==0){
      posh_history(args);
    }
    if (is_builtin(args[0]) == 0){
      args[--temp]=NULL;
      pid_t pid = fork();
      int status;
      if (pid == 0) {
        if (strcmp(args[0],"cat")==0){
          if (execvp("./posh_cat", args) < 0) {
              printf("Could not execute command\n");
          }
          exit(0);
        }
        else if (strcmp(args[0],"date")==0){
          if (execvp("./posh_date", args) < 0) {
              printf("Could not execute command\n");
          }
          exit(0);

        }
        else if (strcmp(args[0],"mkdir")==0){
          if (execvp("./posh_mkdir", args) < 0) {
              printf("Could not execute command\n");
          }
          exit(0);

        }
        else if (strcmp(args[0],"rm")==0){
          if (execvp("./posh_rm", args) < 0) {
              printf("Could not execute command\n");
          }
          exit(0);

        }
        else if (strcmp(args[0],"ls")==0){
          if (execvp("./posh_ls", args) < 0) {
              printf("");
          }
          exit(0);

        }
      }
      else {
          wait(NULL);
      }
    }
  }
  free(param);
  return 0;
}
