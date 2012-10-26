#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

main () {
    char c;

    printf ("\nPress any key...");
    c = getch ();
    printf ("\ngot it... You pressed [%c]\n ",c);

    time_t now;
    struct tm* tmchess;
 
    now = time(0);
    tmchess = localtime(&now);
    /* see time.h for structure tm members*/
 
    printf("\nMonth: %d\n", tmchess->tm_mon+1);
    printf("Day: %d\n", tmchess->tm_mday);
    printf("Year: %d\n\n", tmchess->tm_year+1900); 
   
    printf("Hour: %d\n", tmchess->tm_hour);
    printf("Minute: %d\n", tmchess->tm_min);
    printf("Seconds: %d\n\n", tmchess->tm_sec);

    printf("Date: %d-%02d-%02d\n", tmchess->tm_year+1900, tmchess->tm_mon+1, tmchess->tm_mday);
    printf("Time: %02d:%02d:%02d\n\n", tmchess->tm_hour, tmchess->tm_min, tmchess->tm_sec);

 int time1 = tmchess->tm_sec;
 int time2 = 0;
 int timediff = 0;

    printf ("\nPress any key...");
    c = getch ();

    now = time(0);
    time2 = tmchess->tm_sec;
    timediff = time2 - time1;

    printf("\nseconds (2): %d\n", time2);
    printf("seconds passed: %d\n\n", timediff);
}

int getch ( void ) {
  int ch;
  struct termios origterm, tmpterm;
  
  tcgetattr ( STDIN_FILENO, &origterm );
  tmpterm = origterm;
  tmpterm.c_lflag &= ~( ICANON | ECHO );
  tcsetattr ( STDIN_FILENO, TCSANOW, &tmpterm );
  ch = getchar();
  tcsetattr ( STDIN_FILENO, TCSANOW, &origterm );
  
  return ch;
  }


//  struct tm {
//          int tm_sec;     /* seconds after the minute - [0,59] */
//          int tm_min;     /* minutes after the hour - [0,59] */
//          int tm_hour;    /* hours since midnight - [0,23] */
//          int tm_mday;    /* day of the month - [1,31] */
//          int tm_mon;     /* months since January - [0,11] */
//          int tm_year;    /* years since 1900 */
//          int tm_wday;    /* days since Sunday - [0,6] */
//          int tm_yday;    /* days since January 1 - [0,365] */
//          int tm_isdst;   /* daylight savings time flag */
//          };



