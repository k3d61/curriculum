
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/modulesparam.h>
#include <linux/unistd.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

extern void *sys_call_table[];

static int uid;
module_param(uid, int, 0644);

asmlinkage int (*original_call) (const char *, int, int);

asmlinkage int our_sys_open(const char *filename, int flags, int mode)
{
	int i = 0;
	char ch;
	if (uid == current−>uid) {
/*
* Report the file, if relevant
*/
printk("Opened file by %d: ", uid);
do {
get_user(ch, filename + i);
i++;
printk("%c", ch);
} while (ch != 0);
printk("\n");
}
/*
* Call the original sys_open − otherwise, we lose
* the ability to open files
*/
return original_call(filename, flags, mode);
}

int init_module()
{
/*
* Warning − too late for it now, but maybe for
* next time...
*/
printk(KERN_ALERT "I'm dangerous. I hope you did a ");
printk(KERN_ALERT "sync before you insmod'ed me.\n");
printk(KERN_ALERT "My counterpart, cleanup_module(), is even");
printk(KERN_ALERT "more dangerous. If\n");
printk(KERN_ALERT "you value your file system, it will ");
printk(KERN_ALERT "be \"sync; rmmod\" \n");
printk(KERN_ALERT "when you remove this module.\n");
/*
* Keep a pointer to the original function in
* original_call, and then replace the system call
* in the system call table with our_sys_open
*/
original_call = sys_call_table[__NR_open];
sys_call_table[__NR_open] = our_sys_open;
/*
* To get the address of the function for system
* call foo, go to sys_call_table[__NR_foo].
*/
printk(KERN_INFO "Spying on UID:%d\n", uid);
return 0;
}

void cleanup_module()
{

	if (sys_call_table[__NR_open] != our_sys_open) {
printk(KERN_ALERT "Somebody else also played with the ");
printk(KERN_ALERT "open system call\n");
printk(KERN_ALERT "The system may be left in ");
printk(KERN_ALERT "an unstable state.\n");
}
sys_call_table[__NR_open] = original_call;
}
