#include<linux/init.h>
#include<linux/module.h>

static int __init hello_init(void)
{

	printk(KERN_INFO "Hello Linux Kernel\n");
	return 0;
}

static void __exit hello_exit(void)
{

	printk(KERN_INFO "GoodBye Linux Kernel\n");
}	

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Jack Ma <majian699@163.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple Hello Module");
MODULE_ALIAS("A Hello module");
