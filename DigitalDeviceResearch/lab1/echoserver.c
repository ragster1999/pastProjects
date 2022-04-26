/* echoserver.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cnaiapi.h>

#define BUFFSIZE		256

/*-----------------------------------------------------------------------
 *
 * Program: echoserver
 * Purpose: wait for a connection from an echoclient and echo data
 * Usage:   echoserver <appnum>
 *
 *-----------------------------------------------------------------------
 */
int
main(int argc, char *argv[])
{
	connection	conn;
	int		len;
	char		buff[BUFFSIZE];

	if (argc != 2) {
		(void) fprintf(stderr, "usage: %s <appnum>\n", argv[0]);
		exit(1);
	}

	/* wait for a connection from an echo client */

	conn = await_contact((appnum) atoi(argv[1]));
	if (conn < 0)
		exit(1);
		
int check = fork();

while(check  == 0){

	conn = await_contact((appnum) atoi(argv[1]));
        if (conn < 0)
                exit(1);
	check = fork();
}
memset(buff, 0, 256);
// printf("countdown from server");
// printf("%d", check);
//	buff[BUFFSIZE] = "countdown from server";
strcpy(buff, "countdown from server\n");
	(void) send(conn, buff, BUFFSIZE,0);
char	convert[BUFFSIZE];
sprintf(convert, "%d", check);
memset(buff, 0, 256);
strcpy(buff, convert);
	(void) send(conn, buff, BUFFSIZE, 0);
	 

	/* iterate, echoing all data received until end of file */
for (int i = 15; i>0; i = i-1){
char    convert2[BUFFSIZE];
memset(buff,0,256);
sprintf(convert2,"%d\n",i);
strcpy(buff, convert2);
len = BUFFSIZE;	
//	while((len = recv(conn, buff, BUFFSIZE, 0)) > 0)
		(void) send(conn, buff, len, 0);

sleep(1) ;}
	send_eof(conn);
	return 0;
}
