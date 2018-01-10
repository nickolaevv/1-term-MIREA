
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void shell_lp(void);
char *shell_read(void);
char **shell_split(char *line);

int main(int argc,char **argv){
    shell_lp();
    return EXIT_SUCCESS;
}


void shell_lp(void){
    char *line;
    char **args;
    int status;
    do{
        printf("> ");
        line = shell_read();
        args = shell_split(line);
        status = shell_exct(args);
        free(line);
        free(args);
    }while(status);
}


#define LSH_RL_BUFSIZE 1024
char *shell_read(void){
    int buffsz = LSH_RL_BUFSIZE;
    int val = 0;
    char *buff = malloc(sizeof(char) * buffsz);
    int c;
    if(!buff){
        fprintf(stderr,"shell: memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    while(1){
        c = getchar();
        if(c == EOF || c == '\n'){
            buff[val] = '\0';
            return buff;
        }else{
            buff[val] = c;
        }
        val++;
        if(val >= buffsz){
            buffsz += LSH_RL_BUFSIZE;
            buff = realloc(buff, buffsz);
            if(!buff){
                fprintf(stderr,"shell: memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char **shell_split(char *line){
    int buffsz = LSH_TOK_BUFSIZE, val = 0;
    char **tokens = malloc(buffsz * sizeof(char*));
    char *token;
    if(!tokens){
        fprintf(stderr, "shell: memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, LSH_TOK_DELIM);
    while (token != NULL) {
        tokens[val] = token;
        val++;
        if (val >= buffsz) {
            buffsz += LSH_TOK_BUFSIZE;
            tokens = realloc(tokens, buffsz * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "shell: memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, LSH_TOK_DELIM);
    }
    tokens[val] = NULL;
    return tokens;
}
int shell_launch(char **args){
    pid_t pid, wpid;
    int status;
    pid = fork();
    if (pid == 0) {
        // Add process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

  return 1;
}


int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtin_func[]) (char **) = {
  &shell_cd,
  &shell_help,
  &shell_exit
};

int shell_num_builtins(){
    return sizeof(builtin_str) / sizeof(char *);
}

int shell_cd(char **args){
    if(args[1] == NULL){
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
    } else{
        if(chdir(args[1]) != 0){
            perror("shell");
        }
    }
    return 1;
}

int shell_help(char **args){
    int i;
    printf("list of built-in commands:\n");
    for(i = 0;i < shell_num_builtins(); i++){
        printf("  %s\n", builtin_str[i]);
    }
    printf("Use the \"man\" command for information on other programs\n");
    return 1;
}

int shell_exit(char **args){
    return 0;
}

int shell_exct(char **args){
    int i;
    if(args[0] == NULL){
        return 1;
    }
    for(i = 0;i < shell_num_builtins(); i++){
        if(strcmp(args[0],builtin_str[i]) == 0){
            return (*builtin_func[i])(args);
        }
    }
    return shell_launch(args);
}
