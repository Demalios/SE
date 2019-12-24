#include "syscall.h"

main(){
	ForkExec("../test/userprog0")
	ForkExec("../test/userprog1")
}
