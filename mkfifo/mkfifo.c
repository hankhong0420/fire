#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


#define MYFIFO "myfifo"    

#define MAX_BUFFER_SIZE PIPE_BUF 


void fifo_read(void)
{
    char buff[MAX_BUFFER_SIZE];
    int fd;
    int nread;

    printf("***************** read fifo ************************\n");
    if (access(MYFIFO, F_OK) == -1)                 
    {
        if ((mkfifo(MYFIFO, 0666) < 0) && (errno != EEXIST))    
        {
            printf("Cannot create fifo file\n");
            exit(1);
        }
    }

    fd = open(MYFIFO, O_RDONLY);                
    if (fd == -1)
    {
        printf("Open fifo file error\n");
        exit(1);
    }

    memset(buff, 0, sizeof(buff));

    if ((nread = read(fd, buff, MAX_BUFFER_SIZE)) > 0)      
    {
        printf("Read '%s' from FIFO\n", buff);
    }

   printf("***************** close fifo ************************\n");

    close(fd);                              

    exit(0);
}


void fifo_write(void)
{
    int fd;
    char buff[] = "this is a fifo test demo";
    int nwrite;

    sleep(2);              

    fd = open(MYFIFO, O_WRONLY | O_CREAT, 0644);        
    if (fd == -1)
    {
        printf("Open fifo file error\n");
        exit(1);
    }

    printf("Write '%s' to FIFO\n", buff);

   
    nwrite = write(fd, buff, MAX_BUFFER_SIZE);          

    if(wait(NULL))  
    {
        close(fd);                          
        exit(0);
    }

}


int main()
{
    pid_t result;
    result = fork();               

    if(result == -1)
    {
        printf("Fork error\n");
    }


    else if (result == 0) 
    {
        fifo_read();            
    }

    else 
    {
        fifo_write();       
    }

    return result;
}


