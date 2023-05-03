#include "lib64.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, k, l, m, n, nx, ny;
	BMPIMAGE im;                      //BMP�摜�̏�⪓���ϐ�
	float** inputimageR;
	float** outimageR;
	float** inputimageG;
	float** outimageG;
	float** inputimageB;
	float** outimageB;
    float arrayR[9] = {};
    float arrayG[9] = {};
    float arrayB[9] = {};
    float tmp;

	char filename[512];
	// printf("Sample Program for Filtering \n");
	printf("Input Image Filename (BMP) = ");
	scanf("%s", filename,500);
	getchar();

	//BMP�摜���w�肵���t�@�C������ǂݍ���
	im = Input_BMP(filename);
	if (im == 0)
	{
		printf("No such file as '%s'\n", filename);
		exit(0);
	}

	ny = im->height; nx = im->width;   // �摜�̃T�C�Y��ǂݍ��⾉摜��⩂�l��

	inputimageR = f2d(ny, nx);  // ny�s nx���float�^�̂Q�����z����m��
	outimageR = f2d(ny, nx);    // ny�s nx���float�^�̂Q�����z����m��
	inputimageG = f2d(ny, nx);  // ny�s nx���float�^�̂Q�����z����m��
	outimageG = f2d(ny, nx);    // ny�s nx���float�^�̂Q�����z����m��
	inputimageB = f2d(ny, nx);  // ny�s nx���float�^�̂Q�����z����m��
	outimageB = f2d(ny, nx);    // ny�s nx���float�^�̂Q�����z����m��

	//�摜�̉�f�l��float�^��2�����z��ɃR�s�[�i�����̂��߁j
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimageR[i][j] = (float)im->red[i][j];
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimageG[i][j] = (float)im->green[i][j];
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimageB[i][j] = (float)im->blue[i][j];
	/////////////////////////////////////////////////////////////////////
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
            if (i-1>=0 && i+1<ny && j-1>=0 && j+1<nx) {
                arrayR[0] = inputimageR[i-1][j-1];
                arrayR[1] = inputimageR[i][j-1];
                arrayR[2] = inputimageR[i+1][j-1];
                arrayR[3] = inputimageR[i-1][j];
                arrayR[4] = inputimageR[i][j];
                arrayR[5] = inputimageR[i+1][j];
                arrayR[6] = inputimageR[i-1][j+1];
                arrayR[7] = inputimageR[i][j+1];
                arrayR[8] = inputimageR[i+1][j+1];
                for (m = 0; m < 9; m++) {
                    for (n = m + 1; n < 9; n++) {
                        if (arrayR[m] > arrayR[n]) {
                            tmp = arrayR[m];
                            arrayR[m] = arrayR[n];
                            arrayR[n] = tmp;
                        }
                    }
                }
                outimageR[i][j] = arrayR[4];
            } else {
                outimageR[i][j] = 0.0;
            }
            if (i-1>=0 && i+1<ny && j-1>=0 && j+1<nx) {
                arrayG[0] = inputimageG[i-1][j-1];
                arrayG[1] = inputimageG[i][j-1];
                arrayG[2] = inputimageG[i+1][j-1];
                arrayG[3] = inputimageG[i-1][j];
                arrayG[4] = inputimageG[i][j];
                arrayG[5] = inputimageG[i+1][j];
                arrayG[6] = inputimageG[i-1][j+1];
                arrayG[7] = inputimageG[i][j+1];
                arrayG[8] = inputimageG[i+1][j+1];
                for (m = 0; m < 9; m++) {
                    for (n = m + 1; n < 9; n++) {
                        if (arrayG[m] > arrayG[n]) {
                            tmp = arrayG[m];
                            arrayG[m] = arrayG[n];
                            arrayG[n] = tmp;
                        }
                    }
                }
                outimageG[i][j] = arrayG[4];
            } else {
                outimageG[i][j] = 0.0;
            }
            if (i-1>=0 && i+1<ny && j-1>=0 && j+1<nx) {
                arrayB[0] = inputimageB[i-1][j-1];
                arrayB[1] = inputimageB[i][j-1];
                arrayB[2] = inputimageB[i+1][j-1];
                arrayB[3] = inputimageB[i-1][j];
                arrayB[4] = inputimageB[i][j];
                arrayB[5] = inputimageB[i+1][j];
                arrayB[6] = inputimageB[i-1][j+1];
                arrayB[7] = inputimageB[i][j+1];
                arrayB[8] = inputimageB[i+1][j+1];
                for (m = 0; m < 9; m++) {
                    for (n = m + 1; n < 9; n++) {
                        if (arrayB[m] > arrayB[n]) {
                            tmp = arrayB[m];
                            arrayB[m] = arrayB[n];
                            arrayB[n] = tmp;
                        }
                    }
                }
                outimageB[i][j] = arrayB[4];
            } else {
                outimageB[i][j] = 0.0;
            }
		}
	}/////////////////////////////////////////////////////////////////////////////
	
	 //float�^��2�����z�⩂�IMAGE�\���̃f�[�^�ɃR�s�[�i�Z�[�u���邽�߁j
	//�R�s�[����O�ɁC�O�ȉ��̒l�͂O�ɁC�Q�T�T�ȏ�̒l�͂Q�T�T�ɂ��Ă���D
	//�����������q�f�a���ꂼ��ɂ��ČJ��Ԃ��Ă���
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			if (outimageB[i][j] > 255.0) outimageB[i][j] = 255.0;
			if (outimageB[i][j] < 0.0) outimageB[i][j] = 0.0;
			im->blue[i][j] = (unsigned char)(outimageB[i][j]);
		}
	}

	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			if (outimageR[i][j] > 255.0) outimageR[i][j] = 255.0;
			if (outimageR[i][j] < 0.0) outimageR[i][j] = 0.0;
			im->red[i][j] = (unsigned char)(outimageR[i][j]);
		}
	}
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			if (outimageG[i][j] > 255.0) outimageG[i][j] = 255.0;
			if (outimageG[i][j] < 0.0) outimageG[i][j] = 0.0;
			im->green[i][j] = (unsigned char)(outimageG[i][j]);
		}
	}
	//BMP�摜�Ƃ��ăt�@�C���ɃZ�[�u
	printf("Output Image Filename (BMP)  = ");
	scanf("%s", filename,500);
	getchar();
	Output_BMP(im, filename);
}