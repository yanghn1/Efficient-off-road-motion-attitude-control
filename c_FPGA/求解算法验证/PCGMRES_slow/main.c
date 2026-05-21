/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 21-May-2026 10:28:04
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "PCGMRES_slow.h"
#include "PCGMRES_slow_terminate.h"
#include "rt_nonfinite.h"
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
/* Function Declarations */
static double argInit_real_T(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_PCGMRES_slow();
  /* Terminate the application.
You do not need to do this more than one time. */
  PCGMRES_slow_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
int main_PCGMRES_slow(void)
{struct sockaddr_in serv_addr;

	int ret,sock_fd;
		socklen_t addr_len;
		// create two-way transmission socket
		if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
			perror("error");
		// initialize address
		memset(&serv_addr, 0, sizeof(struct sockaddr_in));
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(5000);
		serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		// bind the local port
		if ((bind(sock_fd, (struct sockaddr *)&serv_addr,
				sizeof(struct sockaddr_in))) < 0)
		{
			perror("bind");
		}
		double sendbuf[3] = {0};
		double recvbuf[8] = {0};
		struct sockaddr_in peeraddr;
		socklen_t peerlen;

		int count;
   	while(1)
         {peerlen = sizeof(peeraddr);
			memset(recvbuf, 0, sizeof(recvbuf));
			count = recvfrom(sock_fd, recvbuf, sizeof(recvbuf), 0,
					(struct sockaddr *)&peeraddr, &peerlen);
double target;
double x;
double y;
double theta;
double vx;
double vy;
double omega;
double deltaf_lastout;
double phi;
double dot_phi;
			target = (double)recvbuf[0];
			x = (double)recvbuf[1];
			y = (double)recvbuf[2];
			theta = (double)recvbuf[3];
			vx = (double)recvbuf[4];
			vy = (double)recvbuf[5];
			omega = (double)recvbuf[6];
			deltaf_lastout = (double)recvbuf[7];
  double ax_next;
  double deltaf_next;
  double ifnum;
  double kp_num;
  double target_tmp;
  /* Initialize function 'PCGMRES_slow' input arguments. */
  target_tmp = argInit_real_T();
  /* Call the entry-point 'PCGMRES_slow'. */
  PCGMRES_slow(target, x, y, theta, vx,
          vy, omega, deltaf_lastout, &ax_next, &deltaf_next, &kp_num,
          &ifnum);
    }
 return 0;
         }

/*
 * File trailer for main.c
 *
 * [EOF]
 */
