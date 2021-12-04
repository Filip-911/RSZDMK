#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/uaccess.h>
#include <linux/errno.h>
#include <linux/device.h>

#define BUFF_SIZE 20
MODULE_LICENSE("Dual BSD/GPL");

dev_t my_dev_id;
static struct class *my_class;
static struct device *my_device;
static struct cdev *my_cdev;

int fifo[16];
int pos = 0;
int endRead = 0;

int fifo_open(struct inode *pinode, struct file *pfile);
int fifo_close(struct inode *pinode, struct file *pfile);
ssize_t fifo_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset);
ssize_t fifo_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset);

struct file_operations my_fops =
{
	.owner = THIS_MODULE,
	.open = fifo_open,
	.read = fifo_read,
	.write = fifo_write,
	.release = fifo_close,
};


int fifo_open(struct inode *pinode, struct file *pfile) 
{
		printk(KERN_INFO "Succesfully opened fifo\n");
		return 0;
}

int fifo_close(struct inode *pinode, struct file *pfile) 
{
		printk(KERN_INFO "Succesfully closed fifo\n");
		return 0;
}

ssize_t fifo_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset) 
{
	int ret;
	char buff[BUFF_SIZE];
	long int len = 0;
	if (endRead){
		endRead = 0;
		return 0;
	}

	if(pos > 0)
	{
		pos --;
		len = scnprintf(buff, BUFF_SIZE, "%d ", fifo[pos]);
		ret = copy_to_user(buffer, buff, len);
		if(ret)
			return -EFAULT;
		printk(KERN_INFO "Succesfully read\n");
		endRead = 1;
	}
	else
	{
			printk(KERN_WARNING "Fifo is empty\n"); 
	}

	return len;
}

ssize_t fifo_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset) 
{
	char buff[100];
	char *mesto;
	unsigned char dec;
	int i;
	int j; 
	int value[9];
	int ret = 0;
	char tmp = 0;
	long tmp2 = 0;
	ret = copy_from_user(buff, buffer, length);
	if(ret)
		return -EFAULT;
	buff[length-1] = '\0';

	while(pos < 16)
	{	
		dec = 1;
		mesto = strchr(buff, 'b');
		mesto++;
		ret = 0; 
		ret = sscanf(mesto,"%ld",&tmp2);
		int decimal = 0;
		if(tmp2%10 == 1)
			decimal++;
		tmp2 = tmp2/10;
		
		for(i = 0; i < 7;i++)
		{
			dec = 1;
			if(tmp2%10 == 1)
			{		
				
				for(j = 0;j < i;j++)
				{					
					dec *=2;
				}
				decimal += dec;
			}
			
			tmp2 = tmp2/10;
		}	
		
		if(ret==1) //one parameter parsed in sscanf
		{
			printk(KERN_INFO "Succesfully wrote value"); 
			/*binarno sabiranje
			for(i = 1;i < 8;i++)
			{
				printk(KERN_INFO "vrednosti value %d", value[7-i]);
				if(value[i] == 1)
				{
					tmp = 1;
					for(j = 0;j < i;j++)
					{
						dec *=2;
					}
				}
				
			}
			if(tmp == 0)
			{
				dec = 0;
			}
			if(value[0] == 1)
			{
				dec+=1;
			}
			*/
			//ubaciti decimalnu vrednost u fifo i povecaj pos za 1
			printk(KERN_INFO "Uspesno izracunato vrednost decimalno: %d", decimal);
			fifo[pos] = decimal;
			printk(KERN_INFO "Uspesno upisano u Fifo: %d", fifo[pos]);
			pos++;
		}	
		else
		{
			printk(KERN_WARNING "Wrong command format");
		}
		if(pos == 16)
			printk(KERN_WARNING "Fifo is full");
		if((*mesto) != ';')
			break;
	}		
	return length;				
}

static int __init fifo_init(void)
{
   int ret = 0;
	int i=0;

	//Initialize array
	for (i=0; i<10; i++)
		fifo[i] = 0;

   ret = alloc_chrdev_region(&my_dev_id, 0, 1, "fifo");
   if (ret){
      printk(KERN_ERR "failed to register char device\n");
      return ret;
   }
   printk(KERN_INFO "char device region allocated\n");

   my_class = class_create(THIS_MODULE, "fifo_class");
   if (my_class == NULL){
      printk(KERN_ERR "failed to create class\n");
      goto fail_0;
   }
   printk(KERN_INFO "class created\n");
   
   my_device = device_create(my_class, NULL, my_dev_id, NULL, "fifo");
   if (my_device == NULL){
      printk(KERN_ERR "failed to create device\n");
      goto fail_1;
   }
   printk(KERN_INFO "device created\n");

	my_cdev = cdev_alloc();	
	my_cdev->ops = &my_fops;
	my_cdev->owner = THIS_MODULE;
	ret = cdev_add(my_cdev, my_dev_id, 1);
	if (ret)
	{
      printk(KERN_ERR "failed to add cdev\n");
		goto fail_2;
	}
   printk(KERN_INFO "cdev added\n");
   printk(KERN_INFO "Hello world\n");

   return 0;

   fail_2:
      device_destroy(my_class, my_dev_id);
   fail_1:
      class_destroy(my_class);
   fail_0:
      unregister_chrdev_region(my_dev_id, 1);
   return -1;
}

static void __exit fifo_exit(void)
{
   cdev_del(my_cdev);
   device_destroy(my_class, my_dev_id);
   class_destroy(my_class);
   unregister_chrdev_region(my_dev_id,1);
   printk(KERN_INFO "Goodbye, cruel world\n");
}


module_init(fifo_init);
module_exit(fifo_exit);
