#include "lib64.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, k, l, nx, ny;
	BMPIMAGE im;                      //BMP�摜�̏�⪓���ϐ�
	BMPIMAGE im_outR;
	BMPIMAGE im_outG;
	BMPIMAGE im_outB;
	float** inputimageR;
	float** outimageR;
	float** inputimageG;
	float** outimageG;
	float** inputimageB;
	float** outimageB;
	int R[256] = {};
	int G[256] = {};
	int B[256] = {};

	char filename[512];
	char filename2[512];
	char filename3[512];
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

    im_outR = Generate_BMP(filename, 512, 512);
	im_outG = Generate_BMP(filename, 512, 512);
	im_outB = Generate_BMP(filename, 512, 512);

	inputimageR = f2d(ny, nx);  // ny�s nx���float�^�̂Q�����z����m��
	outimageR = f2d(512, 512);    // ny�s nx���float�^�̂Q�����z����m��
	inputimageG = f2d(ny, nx);  // ny�s nx���float�^�̂Q�����z����m��
	outimageG = f2d(512, 512);    // ny�s nx���float�^�̂Q�����z����m��
	inputimageB = f2d(ny, nx);  // ny�s nx���float�^�̂Q�����z����m��
	outimageB = f2d(512, 512);    // ny�s nx���float�^�̂Q�����z����m��

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
			R[(int)inputimageR[i][j]] = R[(int)inputimageR[i][j]] + 1; 
		}
	}
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			G[(int)inputimageG[i][j]] = G[(int)inputimageG[i][j]] + 1; 
		}
	}
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			B[(int)inputimageB[i][j]] = B[(int)inputimageB[i][j]] + 1; 
		}
	}
	/*for(j = 0; j< 256; j++){
		printf("R[j]:%d", R[j]);
	}*/
	for (j = 0; j < 256; j++) {
		for (i = 0; (i < R[j]) && (i < 512); i++) {
			/*if(i > 255 || j > 255){
				printf("%d %d\n", i, j);
			}*/
			outimageR[511 - i][2 * j] = 255.0;
		}
		for (i = R[j]; i < 256; i++) {
			outimageR[511 - i][2 * j] = 0;
		}
	}
	for (j = 0; j < 256; j++) {
		for (i = 0; (i < G[j]) && (i < 512); i++) {
			outimageG[511 - i][2 * j] = 255.0;
		}
		for (i = G[j]; i < 256; i++) {
			outimageG[511 - i][2 * j] = 0;
		}
	}
	for (j = 0; j < 256; j++) {
		for (i = 0; (i < B[j]) && (i < 512); i++) {
			outimageB[511 - i][2 * j] = 255.0;
		}
		for (i = B[j]; i < 256; i++) {
			outimageB[511 - i][2 * j] = 0;
		}
	}
	/////////////////////////////////////////////////////////////////////////////
	
	 //float�^��2�����z�⩂�IMAGE�\���̃f�[�^�ɃR�s�[�i�Z�[�u���邽�߁j
	//�R�s�[����O�ɁC�O�ȉ��̒l�͂O�ɁC�Q�T�T�ȏ�̒l�͂Q�T�T�ɂ��Ă���D
	//�����������q�f�a���ꂼ��ɂ��ČJ��Ԃ��Ă���
	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			if (outimageB[i][j] > 255.0) outimageB[i][j] = 255.0;
			if (outimageB[i][j] < 0.0) outimageB[i][j] = 0.0;
			im_outB->blue[i][j] = (unsigned char)(outimageB[i][j]);
			im_outB->red[i][j] = 0;
			im_outB->green[i][j] = 0;
		}
	}

	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			if (outimageR[i][j] > 255.0) outimageR[i][j] = 255.0;
			if (outimageR[i][j] < 0.0) outimageR[i][j] = 0.0;
			im_outR->blue[i][j] = 0;
			im_outR->red[i][j] = (unsigned char)(outimageR[i][j]);
			im_outR->green[i][j] = 0;
		}
	}
	for (i = 0; i < 512; i++) {
		for (j = 0; j < 512; j++) {
			if (outimageG[i][j] > 255.0) outimageG[i][j] = 255.0;
			if (outimageG[i][j] < 0.0) outimageG[i][j] = 0.0;
			im_outG->blue[i][j] = 0;
			im_outG->red[i][j] = 0;
			im_outG->green[i][j] = (unsigned char)(outimageG[i][j]);
		}
	}
	//BMP�摜�Ƃ��ăt�@�C���ɃZ�[�u
	printf("Output three Filenames R->G->B (BMP) : ");
	scanf("%s %s %s", filename, filename2, filename3, 500);
	getchar();
	Output_BMP(im_outR, filename);
	Output_BMP(im_outG, filename2);
	Output_BMP(im_outB, filename3);
}