/*	ǰ�˲��Գ��� ��������
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
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
  int fd;//�ļ�������
  int i;
  char data[256];
  
  int retval;
  fd=open("/dev/demo",O_RDWR);
  if(fd==-1)//���û�г�������ļ�������
  {
     perror("error open\n");
     exit(-1);
  }
  printf("open /dev/demo successfully\n");
  retval=ioctl(fd,COMMAND1,0);//ioctl io���� ��ȫ������������ ����COMMAND1
  if(retval==-1)
  {
    perror("ioctl error\n");	
    exit(-1);
  }
  printf("send command1 successfully\n");
  
  retval=write(fd,"test",4);//4 ƫ����
  if(retval==-1)
  {
    perror("write error\n");
    exit(-1);
  }
  retval=lseek(fd,0,0);//����ȥ 0 0�����ڴ�ȥ�ͷ��λ��
  if(retval==-1)
  {
    perror("lseek error\n");
    exit(-1);
  }
  retval=read(fd,data,4); //��ȡ�ĸ��ֽ�
  
 if(retval==-1)
  {
    perror("read error\n");
    exit(-1);
  }
   printf("read successfully:%s\n",data);
  close(fd);
}
