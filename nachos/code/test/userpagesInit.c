#include "syscall.h"

/*
  pour lancer :
  ./nachos -x ./test/userpagesInit ( en étant dans userprog )
  comportement attendu :
  affiche deux appel a putchar

  *note : programme de test pour la partie II du TD3
*/

main(){
	ForkExec("../test/putchar");
	ForkExec("../test/putchar");
	while(1);
}
