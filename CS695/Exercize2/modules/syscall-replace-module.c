
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/unistd.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

#include <linux/unistd.h>
#include <asm/cacheflush.h>

#define VM_READ         0x00000001      /* currently active flags */
#define VM_WRITE        0x00000002

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kedar Anavardekar");
MODULE_DESCRIPTION("Module to extend sys call functionality");

void **sys_call_table;


asmlinkage void (*original_syscall) (char *);
asmlinkage void (*temp) (char *);

asmlinkage void extended_syscall(char *str)
{
	printk( KERN_INFO "%s, passed arrgument= %s\n", __func__ ,str);
}

/*
// this is to be done to make sys_call_table Read-Writable
int set_page_rw(long unsigned int _addr)
{
   struct page *pg;
   pgprot_t prot;
   pg = virt_to_page(_addr);
   prot.pgprot = VM_READ | VM_WRITE;
   return change_page_attr(pg, 1, prot);
}
*/

int make_rw(unsigned long long address){
    unsigned int level;
    pte_t *pte = lookup_address(address, &level);
    if(pte->pte &~_PAGE_RW){
        pte->pte |=_PAGE_RW;
    }
    return 0;
}
int init_module( void )
{
	printk( KERN_INFO "\t\tvvvvvvvvvvvvvvv\n");
	printk( KERN_INFO "%s.1 \n",__func__);
	sys_call_table = (void*) 0xffffffff820001a0; 
	printk( KERN_INFO "%s.2 \n",__func__);
	original_syscall = sys_call_table[335];
	//original_syscall("original");
	printk( KERN_INFO "%s.3 \n",__func__);
	
	make_rw((unsigned long long)sys_call_table);
	printk( KERN_INFO "%s.4 \n",__func__);
	//set_page_rw(sys_call_table);
	sys_call_table[335] = extended_syscall;
	temp = sys_call_table[335];
	temp("hmm");
	//original_syscall = extended_syscall;
	//original_syscall("hmm");
	return 0;
}

void cleanup_module( void )
{
	sys_call_table[335] = original_syscall;
	printk( KERN_INFO "Goodbe in -> %s\n" ,__func__);
}
