#define SYSCALL_EXIT 1
#define SYSCALL_WRITE 4

void syscall(int syscall, int arg1)
{
	asm("movl %0,%%ebx" : "=S"(arg1) : "S"(arg1) : "%ebx");
	asm("movl %0,%%eax" : "=S"(syscall) : "S"(syscall) : "%eax");
	asm ("int $0x80");
}

void myexit(int code)
{
	syscall(SYSCALL_EXIT, code);
}


int main() {
	myexit(36);
	return 27;
}

void _start() {
	int ret = main();
	myexit(ret);
}
