#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int moreCommands = 1;

void parseArgs(char *buffer, char** args, int argsSize, int *nargs);

int main(){
    while(moreCommands){
        //pwd stuff
        char* cwd;
        char buff[PATH_MAX + 1];
        cwd = getcwd(buff, PATH_MAX+1);

        //fgets stuff
        char* str = (char*)malloc(60*sizeof(char));
        printf("%s>", cwd);
        printf("%s\n", fgets(str, 60, stdin));

        //parsing stuff
        char** args = (char**)malloc(10*sizeof(char*));
        //populate the array with stuff
        int i;
        for(i=0; i<10; i++){
            args[i] = (char*)malloc(25 * sizeof(char));
        }
        int* nargs = (int*)malloc(sizeof(int));
        parseArgs(str, args, 10, nargs);
        if(strcmp("exit", args[0]) == 0){
            return 0;
        }
        if(strcmp("cd", args[0]) == 0){
            int ret;
            ret = chdir(args[1]);
            if(ret != 0){
                printf("Directory was not valid\n");
            }
        }
        //else if(strcmp("ls", args[0]) == 0 || strcmp("pwd", args[0]) == 0){
        else{
            int pid = fork();
            if(pid == 0){
                int rc = execvp(args[0], args);
                printf("Thing executed.\n");
            }
            else{
                int status;
                int result = waitpid(pid, &status, 0);
            }
        }
    }
    return EXIT_SUCCESS;
}

void parseArgs(char *buffer, char** args, int argsSize, int *nargs){
    char *bufArgs[argsSize];
    char **cp;
    char *wbuf;
    int i, j;

    wbuf=buffer;
    bufArgs[0]=buffer;
    args[0]=buffer;

    for(cp=bufArgs; (*cp=strsep(&wbuf, " \n\t")) != NULL;){
        if((*cp != '\0') && (++cp >= &bufArgs[argsSize]))
            break;
    }
    for(j=i=0; bufArgs[i] != NULL; i++){
        if(strlen(bufArgs[i]) > 0)
            args[j++]=bufArgs[i];
    }
    *nargs = j;
    args[j] = NULL;

}
