/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2007, 2010 fengGuojin(fgjnew@163.com)
 */
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<linux/rtc.h>
#include<linux/ioctl.h>
#include<stdio.h>
#include<stdlib.h>

#define COMMAND1 1
#define COMMAND2 2

main()
{
  int fd;
  int i;
 char data[256];
  
  int retval;
  fd=open("/dev/fgj",O_RDWR);
  if(fd==-1)
  {
     perror("error open\n");
     exit(-1);
  }
  printf("open /dev/smbus successfully\n");
  retval=ioctl(fd,COMMAND1,0);
  if(retval==-1)
  {
    perror("ioctl error\n");
    exit(-1);
  }
  printf("send command1 successfully\n");
  
  retval=write(fd,"fgj",3);
  if(retval==-1)
  {
    perror("write error\n");
    exit(-1);
  }
  retval=lseek(fd,0,0);
  if(retval==-1)
  {
    perror("lseek error\n");
    exit(-1);
  }
  retval=read(fd,data,3);
  
 if(retval==-1)
  {
    perror("read error\n");
    exit(-1);
  }
   printf("read successfully:%s\n",data);
  close(fd);
}
