
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kedar Anavardekar");
MODULE_DESCRIPTION(DRIVER_DESC);

int init_module( void )
{
	printk( KERN_INFO "Hello IIT 1." \n);
	return 0;
}

void cleanup_module( void )
{
	printk( KERN_INFO "Goodbe IIT 1."\n );
}
