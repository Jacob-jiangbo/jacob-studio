/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2007, 2010 fengGuojin(fgjnew@163.com)
 */


#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd;
	char num[2];

	fd = open("/dev/fgj", O_RDWR, S_IRUSR | S_IWUSR);
	if (fd != - 1)
	{
		while (1)
		{
			read(fd, &num,2); //���������ڴ����
			printf("The data is %s\n", num);

			//���������5�����˳�
			if (num[1] ==0x35)
			{
				close(fd);
				break;
			}
		}
	}
	else
	{
		printf("device open failure\n");
	}
}
