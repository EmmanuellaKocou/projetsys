

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    	//declarations des processus
	pid_t pid1, pid2, pid3;
   
  
  
	//creation du processus1
    pid1 = fork();
    if(pid1 < 0){
          perror("Erreur de création du processus\n");
          exit(EXIT_FAILURE);
    }

    if(pid1 == 0){
       printf("Nous sommes dans le fils du processus1 avec pid1 = %d\n", (int) getpid());
       
    }

    else{
       //creation du processus2
        pid2 = fork();
        if(pid2 < 0){
          perror("Erreur de création du second processus\n");
          exit(EXIT_FAILURE);
        }

        if(pid2 == 0){
            printf("Nous sommes dans le fils du processus2 avec pid2 = %d\n" ,(int) getpid());
        }

        else{
		//creation du processus3
            pid3 = fork();
            if(pid3 < 0){
              perror("Erreur de création du troisieme processus\n");
              exit(EXIT_FAILURE);
            }

            if(pid3 == 0){
           printf("Nous sommes dans le fils du processus3 avec pid3 = %d\n" ,(int) getpid());
            }

            else{
                printf("pid du processus 1 : %d\n", pid1);
                printf("pid du processus 2 :  %d\n", pid2);
                printf("pid du processus 3 :  %d\n",  pid3);
            }
        }

        
    } 
}
