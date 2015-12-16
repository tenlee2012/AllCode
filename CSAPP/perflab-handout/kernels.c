/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "xxxxxx",              /* Team name */

    "JiaHao Li",     /* First member full name */
    "794963035@qq.com",  /* First member email address */

    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 * 基本的旋转版本
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * 你当前旋转的工作版本
 * IMPORTANT: This is the version you will be graded on
 * 你可能将这个版本分级表示。
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    naive_rotate(dim, src, dst);
}

char myrotate_1_descr[] = "myrotate_1: Current working version";
void myrotate_1(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i+=2)
    {
	    for (j = 0; j < dim; j++)
        {
	        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
	        dst[RIDX(dim-1-j, i+1, dim)] = src[RIDX(i+1, j, dim)];
        }
    }
    for(; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
	        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        }
    }
}

char myrotate_2_descr[] = "myrotate_2: Current working version";
void myrotate_2(int dim, pixel *src, pixel *dst) 
{
    int i, j, tmp, tmp1;

    for (i = 0; i < dim; i+=2)
    {
	    for (j = 0; j < dim; j++)
        {
            tmp = i * dim + j;
            tmp1 = dim * (dim - 1 - j) + i;
	        dst[tmp1] = src[tmp];
	        dst[tmp1+1] = src[tmp+dim];
        }
    }
    for(; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
	        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
        }
    }
}

char myrotate_3_descr[] = "myrotate_3: Current working version";
void myrotate_3(int dim, pixel *src, pixel *dst) 
{
    int i, j, i1, j1;
    int block = 32;//blocking the Matrix
    for(i = 0; i < dim; i += block)
        for(j = 0; j < dim; j += block)
        {
            //block*block mini matrix
            for(i1 = i; i1 < i+block; i1++) 
            {
                for(j1 = j; j1 < j+block; j1++)
                    dst[RIDX(i1, j1, dim)] = src[RIDX(j1, dim-i1-1, dim)];
            }
        }
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function. 
 * 通过调用add_rotate_function（）对每个测试函数注册所有不同版本的内核旋转与驱动。
 * 例如，你写的函数是rotate1,那么就需要在这个函数中这样写
 * add_rotate_function(&rotate1, rotate1_descr);  rotate1_descr是一个字符串，随自己定义
 * 当您运行驱动程序，它会测试并报告每一个注册的测试功能的性能。 
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
    add_rotate_function(&myrotate_1, myrotate_1_descr);
    add_rotate_function(&myrotate_2, myrotate_2_descr);
    add_rotate_function(&myrotate_3, myrotate_3_descr);
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 * 对于smooth function你可以有不同的类型定义和辅助函数，你可以以任何喜欢的方式去修改。
 **************************************************************/

/* A struct used to compute averaged pixel value 
 * 一个用来计算平均像素的结构体
 */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 全部初始化为0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum  计算p对应的每个字段的和
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 * 计算每个字段的平均值
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
		for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    	accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}
static pixel myavg(int dim, int i, int j, pixel *src) 
{
    int ii, jj, min1, min2, max2;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    min1 = min(i+1, dim-1);
    min2 = min(j+1, dim-1);
    max2 = max(j-1, 0);
    for(ii = max(i-1, 0); ii <= min1; ii++) 
    {
        for(jj = max2; jj <= min2; jj++) 
        {
	    	accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);
        }
    }

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

static pixel avg_opt(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    int min1, min2, max2;
	int blue = 0, green = 0, red = 0, num = 0, loc, iidim;
    pixel current_pixel;
	
	ii = max(i-1, 0);
    min1 = min(i+1, dim-1);
    min2 = min(j+1, dim-1);
    max2 = max(j-1, 0);
	iidim = ii * dim;
    for(; ii <= min1; ii++) 
    {
		for(jj = max2; jj <= min2; jj++) 
        {
			loc = iidim + jj;
			blue += (int) src[loc].blue;
			red += (int) src[loc].red;
			green += (int) src[loc].green;
			num++;
		}
		iidim += dim;
	}
	current_pixel.red = (unsigned short) (red/num);
	current_pixel.blue = (unsigned short) (blue/num);
	current_pixel.green = (unsigned short) (green/num);
    return current_pixel;
}


/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    naive_smooth(dim, src, dst);
}

char mysmooth_1_descr[] = "My smooth 1: --->";
void mysmooth_1(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i += 2)
    {
        for (j = 0; j < dim; j++)
        {
	        dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
	        dst[RIDX(i+1, j, dim)] = avg(dim, i+1, j, src);
        }
    }
    for(; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
	        dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
        }
      
    }
}
char mysmooth_2_descr[] = "My smooth 2--->";
void mysmooth_2(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i += 2)
    {
        for (j = 0; j < dim; j++)
        {
	        dst[RIDX(i, j, dim)] = myavg(dim, i, j, src);
	        dst[RIDX(i+1, j, dim)] = myavg(dim, i+1, j, src);
        }
    }
    for(; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
	        dst[RIDX(i, j, dim)] = myavg(dim, i, j, src);
        }
      
    }
}
char mysmooth_3_descr[] = "My smooth 3: Memory access optimization";
void mysmooth_3(int dim, pixel *src, pixel *dst) 
{
    int i, j;
	
	int rindex = 0;
    for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++){
			dst[rindex+j] = avg_opt(dim, i, j, src);
		}
		rindex += dim;
	}
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
    add_smooth_function(&mysmooth_1, mysmooth_1_descr);
    add_smooth_function(&mysmooth_2, mysmooth_2_descr);
    add_smooth_function(&mysmooth_3, mysmooth_3_descr);
}

