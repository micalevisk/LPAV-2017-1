

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

int main (int argc, char * argv[])
{
   struct timeval antes, depois ;
   float delta, delta2 ;

   gettimeofday (&antes, 0) ;
   sleep (2) ;
   gettimeofday (&depois, 0) ;

   delta = (depois.tv_sec + depois.tv_usec/1000000.0) -
               (antes.tv_sec  + antes.tv_usec /1000000.0) ;
   printf ("Diferenca de %f segundos\n", delta) ;

   delta2 = ((depois.tv_sec * 1000000 + depois.tv_usec)
          - (antes.tv_sec * 1000000 + antes.tv_usec));
   printf ("Diferenca de %f microsegundos\n", delta2) ;
}






