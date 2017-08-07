/* 
 * Authors: Felipe A. Louza, Simon Gog, Guilherme P. Telles
 * contact: louza@ic.unicamp.br
 * 03/04/2017
 */

/* 
 * This code is a modification of  SA-IS algorithm by G. Nong et al., which can be
 * retrieved at: http://code.google.com/p/ge-nong/ 
 *
 * Our version of SA-IS, called gSAIS, maintain the theoretical bounds of the
 * original algorithm to construct the generalized suffix array.
 *
 * Our algorithm gSAIS can also computes the LCP-array and the Document-array
 * with no additional costs.
 * 
 * gsais(s, SA, NULL, NULL, n) //computes only SA
 * gsais(s, SA, LCP,  NULL, n) //computes SA and LCP
 * gsais(s, SA, NULL, DA,   n) //computes SA and DA
 * gsais(s, SA, LCP,  DA,   n) //computes SA, LCP and DA
 * 
 */

#ifndef GSAIS_H
#define GSAIS_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

#ifndef DEBUG
        #define DEBUG 0
#endif

#ifndef M64
        #define M64 0
#endif

#if M64
        typedef int64_t  int_t;
        typedef uint64_t uint_t;
        #define PRIdN    PRId64
        #define U_MAX    UINT64_MAX
        #define I_MAX    INT64_MAX
        #define I_MIN    INT64_MIN
#else
        typedef int32_t  int_t;
        typedef uint32_t uint_t;
        #define PRIdN    PRId32
        #define U_MAX    UINT32_MAX
        #define I_MAX    INT32_MAX
        #define I_MIN    INT32_MIN
#endif
 
/** @brief computes the suffix array of string s[0..n-1] 
 *
 *  @param s	input string with s[n-1]=0
 *  @param SA 	suffix array 
 *  @param n	string length
 *  @return -1 if an error occured, otherwise the depth of the recursive calls.
 */
int sais(unsigned char *s, uint_t *SA, uint_t n);

/** @brief computes the suffix array of string s[0..n-1]
 *  @param k	alphabet size
 */
int sais_int(int_t *s, uint_t *SA, uint_t n, uint_t k);


/** @brief Computes the suffix array SA (LCP, DA) of T^cat in s[0..n-1]
 *
 *  @param s	input string
 *  @param SA 	suffix array 
 *  @param LCP 	LCP array 
 *  @param DA 	Document array
 *  @param n	string length
 * 
 *  @return depth of the recursive calls.
 */
int gsais(unsigned char *s, uint_t *SA, int_t *LCP, int_t *DA, uint_t n);

/** @brief Computes the suffix array SA (LCP, DA) of T^cat in s[0..n-1]
 *
 *  @param s	input string
 *  @param SA 	suffix array 
 *  @param LCP 	LCP array 
 *  @param DA 	Document array
 *  @param n	string length
 *  @param K	alphabet size
 * 
 *  @return depth of the recursive calls.
 */
int gsais_int(uint_t *s, uint_t *SA, int_t *LCP, int_t *DA, uint_t n, uint_t k);

#endif