#include "syscall.h"
/*
  pour lancer :
  ./nachos -rs 1234 -x ./test/userpagesTest ( en étant dans userprog )
  comportement attendu :
  fais des fork avec douze appels a userpages2

  *note : programme de test pour la partie II du TD3
*/

main(){
	for(int i = 0; i<=12 ; i++){
		ForkExec("../test/userpages2");	
	}
	while(1);
}
