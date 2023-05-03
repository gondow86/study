#include "lib64.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, k, l, nx, ny;
	BMPIMAGE im;                      //BMP�摜�̏�⪓���ϐ�
	float** inputimageR;
	float** outimageR;
	float** inputimageG;
	float** outimageG;
	float** inputimageB;
	float** outimageB;
    float fmax;
    float fmin;

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
    printf("input fmax fmin:");
    scanf("%f %f", &fmax, &fmin);
    for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			outimageR[i][j] = ((inputimageR[i][j] - fmin)*255) / (fmax - fmin);///inputimage�̒l�����̂܂�outimage�֊i�[
			outimageG[i][j] = ((inputimageG[i][j] - fmin)*255) / (fmax - fmin);///���ۂɂ̓t�B���^�����Ȃǂ��������̂�outimage�֊i�[
			outimageB[i][j] = ((inputimageB[i][j] - fmin)*255) / (fmax - fmin);
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