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
"xxxxxxx",              /* Team name */

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

/***************************************************************
 * Helper functions for the rotate function.
 * You may modify these any way you like.
 **************************************************************/

/*
 * ridx - turn a row/column index in an n by n matrix into a linear index,
 * with bounds checking.
 */
int ridx(int i, int j, int n)
{
    if (i < 0  ||  i >= n  ||  j < 0  ||  j >= n)
	return 0;	  /* Turn illegal indices into [0,0] */
    else
	return RIDX(i, j, n);
}

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;
	
    for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			dst[ridx(dim-1-j, i, dim)] = src[ridx(i, j, dim)];
}


char ji_rotate_descr[] = "ji_rotate: Naive baseline implementation";
void ji_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;
	
    for (j = 0; j < dim; j++)
		for (i = 0; i < dim; i++)
			dst[ridx(dim-1-j, i, dim)] = src[ridx(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
	int i, j, ii, jj;
	
	for (ii = 0; ii < dim; ii+=16) 
		for (jj = 0; jj < dim; jj+=16) 
			for (j = jj; j < jj+16; j++) 
				for (i = ii; i < ii+16; i++) 
					dst[(dim-j-1)*dim+i] = src[i*dim+j];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotateb_descr[] = "rotate: Current working version";
void rotateb(int dim, pixel *src, pixel *dst, int bsize) 
{
    int i, j, ii, jj;//, dd1 = dim*(dim-1);
	
	for (ii = 0; ii < dim; ii+=bsize) {
		for (jj = 0; jj < dim; jj+=bsize) {
				for (j = jj; j < jj+bsize; j++) {
			for (i = ii; i < ii+bsize; ++i) {
					dst[dim*(dim-1-j)+i] = src[i*dim+j];
				}
			}
		}
	}
}

char rotate2d[] = "rotate bsize 2";
void rotate2(int dim, pixel *src, pixel *dst) 
{
	rotateb(dim, src, dst, 2);
}

char rotate4d[] = "rotate bsize 4";
void rotate4(int dim, pixel *src, pixel *dst) 
{
	rotateb(dim, src, dst, 4);
}

char rotate8d[] = "rotate bsize 8";
void rotate8(int dim, pixel *src, pixel *dst) 
{
	rotateb(dim, src, dst, 8);
}

char rotate16d[] = "rotate bsize 16";
void rotate16(int dim, pixel *src, pixel *dst) 
{
	rotateb(dim, src, dst, 16);
}

char rotate32d[] = "rotate bsize 32";
void rotate32(int dim, pixel *src, pixel *dst) 
{
	rotateb(dim, src, dst, 32);
}

char rotatesmartd[] = "rotatesmart rotate bsize = dim/16";
void rotatesmart(int dim, pixel *src, pixel *dst) 
{
	rotateb(dim, src, dst, dim/16);
}


/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr); 
//    add_rotate_function(&rotate4, rotate4d); 
//    add_rotate_function(&rotate8, rotate8d); 
//    add_rotate_function(&rotate16, rotate16d); 
//    add_rotate_function(&rotate32, rotate32d); 
    add_rotate_function(&rotatesmart, rotatesmartd);
	
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
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
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
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
			accumulate_sum(&sum, src[ridx(ii, jj, dim)]);
	
    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg_opt(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
	int blue=0, green=0, red=0, num=0, loc, iidim;
    pixel current_pixel;
	
	ii = max(i-1, 0);
	iidim = ii * dim;
    for( ; ii <= min(i+1, dim-1); ii++) {
		for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) {
			loc = iidim + jj;
			blue += (int) src[loc].blue;
			red += (int) src[loc].red;
			green += (int) src[loc].green;
			num++;
		}
		iidim += dim;
	}
	//	accumulate_sum(&sum, src[ridx(ii, jj, dim)]);
	current_pixel.red = (unsigned short) (red/num);
	current_pixel.blue = (unsigned short) (blue/num);
	current_pixel.green = (unsigned short) (green/num);
	// assign_sum_to_pixel(&current_pixel, sum);
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
			dst[ridx(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * firstTry 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth1_descr[] = "smooth1: Memory access optimization";
void smooth1(int dim, pixel *src, pixel *dst) 
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

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j, rij;
	int rindex = dim;
	
	// Corner cases
	dst[0].red = (src[0].red+src[1].red+src[dim].red+src[dim+1].red)/4;
	dst[0].blue = (src[0].blue+src[1].blue+src[dim].blue+src[dim+1].blue)/4;
	dst[0].green = (src[0].green+src[1].green+src[dim].green+src[dim+1].green)/4;
	
	dst[dim-1].red = (src[dim-1].red+src[dim-2].red+src[dim*2-1].red+src[dim*2-2].red)/4;
	dst[dim-1].blue = (src[dim-1].blue+src[dim-2].blue+src[dim*2-1].blue+src[dim*2-2].blue)/4;
	dst[dim-1].green = (src[dim-1].green+src[dim-2].green+src[dim*2-1].green+src[dim*2-2].green)/4;
	
	dst[dim*(dim-1)].red = (src[dim*(dim-1)].red+src[dim*(dim-1)+1].red+src[dim*(dim-2)].red+src[dim*(dim-2)+1].red)/4;
	dst[dim*(dim-1)].blue = (src[dim*(dim-1)].blue+src[dim*(dim-1)+1].blue+src[dim*(dim-2)].blue+src[dim*(dim-2)+1].blue)/4;
	dst[dim*(dim-1)].green = (src[dim*(dim-1)].green+src[dim*(dim-1)+1].green+src[dim*(dim-2)].green+src[dim*(dim-2)+1].green)/4;
	
	dst[dim*dim-1].red = (src[dim*dim-1].red+src[dim*dim-2].red+src[dim*(dim-1)-1].red+src[dim*(dim-1)-2].red)/4;
	dst[dim*dim-1].blue = (src[dim*dim-1].blue+src[dim*dim-2].blue+src[dim*(dim-1)-1].blue+src[dim*(dim-1)-2].blue)/4;
	dst[dim*dim-1].green = (src[dim*dim-1].green+src[dim*dim-2].green+src[dim*(dim-1)-1].green+src[dim*(dim-1)-2].green)/4;
	
	for (j = 1; j < dim-1; j++) {
		dst[j].red = (src[j].red+src[j-1].red+src[j+1].red+src[j+dim].red+src[j+1+dim].red+src[j-1+dim].red)/6;
		dst[j].green = (src[j].green+src[j-1].green+src[j+1].green+src[j+dim].green+src[j+1+dim].green+src[j-1+dim].green)/6;
		dst[j].blue = (src[j].blue+src[j-1].blue+src[j+1].blue+src[j+dim].blue+src[j+1+dim].blue+src[j-1+dim].blue)/6;
	}
	
	for (j = dim*(dim-1)+1; j < dim*dim-1; j++) {
		dst[j].red = (src[j].red+src[j-1].red+src[j+1].red+src[j-dim].red+src[j+1-dim].red+src[j-1-dim].red)/6;
		dst[j].green = (src[j].green+src[j-1].green+src[j+1].green+src[j-dim].green+src[j+1-dim].green+src[j-1-dim].green)/6;
		dst[j].blue = (src[j].blue+src[j-1].blue+src[j+1].blue+src[j-dim].blue+src[j+1-dim].blue+src[j-1-dim].blue)/6;
	}
	
	for (j = dim; j < dim*(dim-1); j+=dim) {
		dst[j].red = (src[j].red+src[j-dim].red+src[j+1].red+src[j+dim].red+src[j+1+dim].red+src[j-dim+1].red)/6;
		dst[j].green = (src[j].green+src[j-dim].green+src[j+1].green+src[j+dim].green+src[j+1+dim].green+src[j-dim+1].green)/6;
		dst[j].blue = (src[j].blue+src[j-dim].blue+src[j+1].blue+src[j+dim].blue+src[j+1+dim].blue+src[j-dim+1].blue)/6;
	}
	
	for (j = dim+dim-1; j < dim*dim-1; j+=dim) {
		dst[j].red = (src[j].red+src[j-1].red+src[j-dim].red+src[j+dim].red+src[j-dim-1].red+src[j-1+dim].red)/6;
		dst[j].green = (src[j].green+src[j-1].green+src[j-dim].green+src[j+dim].green+src[j-dim-1].green+src[j-1+dim].green)/6;
		dst[j].blue = (src[j].blue+src[j-1].blue+src[j-dim].blue+src[j+dim].blue+src[j-dim-1].blue+src[j-1+dim].blue)/6;
	}
	
    for (i = 1; i < dim-1; i++)
	{
		for (j = 1; j < dim-1; j++){
			rij = rindex+j;
			dst[rij].red = (src[rij].red+src[rij-1].red+src[rij+1].red+src[rij-dim].red+src[rij-dim-1].red+src[rij-dim+1].red+src[rij+dim].red+src[rij+dim+1].red+src[rij+dim-1].red)/9;
			dst[rij].green = (src[rij].green+src[rij-1].green+src[rij+1].green+src[rij-dim].green+src[rij-dim-1].green+src[rij-dim+1].green+src[rij+dim].green+src[rij+dim+1].green+src[rij+dim-1].green)/9;
			dst[rij].blue = (src[rij].blue+src[rij-1].blue+src[rij+1].blue+src[rij-dim].blue+src[rij-dim-1].blue+src[rij-dim+1].blue+src[rij+dim].blue+src[rij+dim+1].blue+src[rij+dim-1].blue)/9;
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
    add_smooth_function(&smooth1, smooth1_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}

