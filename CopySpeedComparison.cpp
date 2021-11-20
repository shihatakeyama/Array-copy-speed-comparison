// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// �R�s�[���x��r
// 
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include "stdafx.h"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// �Ăяo�����x
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#include <time.h>
#define NUMBER_REPETITIONS		1000000
#define MAX_BUFSIZE				1024

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int loop;
	int i;
	clock_t begin;
	char srcbuf[MAX_BUFSIZE];
	char dstbuf[MAX_BUFSIZE];

	// �f�[�^�ϐ��C�j�V�����C�Y
	for (int i = 0; i < MAX_BUFSIZE; i++){
		srcbuf[i] = i;
	}

	printf("==== Copy Speed Comparison START ====\n");
	printf("Number of loops\t: %d\n", NUMBER_REPETITIONS);


	{	// memcpy �R�s�[
		begin = clock();
		for (loop = 0; loop<NUMBER_REPETITIONS; loop++){
			memcpy(dstbuf, srcbuf, sizeof(dstbuf));
		}
		printf("memcpy copy time\t: %d ms\n", clock() - begin);
	}

	{	// while loop �R�s�[
		begin = clock();
		for (loop = 0; loop < NUMBER_REPETITIONS; loop++){
			char *src = srcbuf;
			char *itr = dstbuf;
			char *end = dstbuf + MAX_BUFSIZE;
			while (itr < end){
				*itr++ = *src++;
			}
		}
		printf("while loop copy time\t: %d ms\n", clock() - begin);
	}

	{	// for loop �R�s�[
		begin = clock();
		for (loop = 0; loop<NUMBER_REPETITIONS; loop++){
			for (i = 0; i < MAX_BUFSIZE; i++){
				dstbuf[i] = srcbuf[i];
			}
		}
		printf("for loop copy time\t: %d ms\n", clock() - begin);
	}

	printf("==== Copy Speed Comparison END ====\n");

	getchar();

	return 0;
}

