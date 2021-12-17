//SPDX-LICENSE-IDENTIFIER:GPL-3.0
/*
*Copyright(c)2021 Ryuichi Ueda. Yuma Ito. All rights reserved.
*/


#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>
MODULE_AUTHOR("Ryuichi Ueda & Yuma Ito & Koutarou Murabayashi");
MODULE_DESCRIPTION("driver for LED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");
static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;
static ssize_t led_write(struct file* filp* filp, const char* buf, size_t count, loft_t* pos){
  char c;
  if(copy_from_user(&c, buf, sizeof(char)))
    return -EFAULT;
  if(c == '0'){
    gpio_base[10] = 1 << 25;
  }
  else if(c == '1'){
    gpio_base[7] = 1 << 25;
  }
  else if(c == '2'){
    gpio_base[10] = 1 << 24;
  }
  else if(c == '3'){
    gpio_base[7] = 1 << 24;
  }
  else if(c == '4'){
    gpio_base[10] = 1 << 23;
  }
  else if(c == '5'){
    gpio_base[7] = 1<< 23;
  }
return 1;
}

static struct file_operations led_fops = {
  .Owner = THIS_MODULE,
  .write = led_write
};

static int__init_mod(void){
  int retval;
  retval = alloc_chrdev_region(&dev, 0, 1, "myled");
            if(retval < 0){
            printk(KERN_ERR "alloc_chrdev_region failed. \n");
            return retval;
    }
  printk(KERN_INFO "%s is loaded. major:%d\n", __FIRE__, MAJOR(dev));
  cdev_init(&cdv, &led_fops);
  retval = cdev_add(&cdv, dev, 1);
           if(retval < 0){
            printk(KERN_ERR "cdev_add failed. major:%d. minor:%d", MAJOR(dev),MINOR(dev));
            return retval;
    }
  cls = Class_create(THIS_MODULE, "myled");
        if(IS_ERR(cls)){
          printk(KERN_ERR ")
        
  
  
