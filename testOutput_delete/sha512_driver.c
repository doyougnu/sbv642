/* Example driver program for sha512. */
/* Automatically generated by SBV. Edit as you see fit! */

#include <stdio.h>
#include "sha512.h"

int main(void)
{
  const SWord8 hIn[64] = {
       87, 235, 178,   2,  66,  95,  54, 149, 135, 172, 187,  70,   5,
       73, 250, 173,  19, 217, 181, 193,  38, 159, 255,  92, 150,  13,
      224, 214,  11,  95, 168,  22, 153,  81,  10,  98, 216,  92, 151,
       32,  54,  68, 253,   2, 237, 101,  92,   2, 151, 116,  11, 255,
        1, 202,  21, 252, 169,  98,  82,  15, 136, 116,  38,  33
  };

  printf("Contents of input array hIn:\n");
  int hIn_ctr;
  for(hIn_ctr = 0; hIn_ctr < 64 ; ++hIn_ctr)
    printf("  hIn[%2d] = %"PRIu8"\n", hIn_ctr ,hIn[hIn_ctr]);

  const SWord8 block[128] = {
      207, 151, 107, 171,  49, 205, 216, 117,  20, 142,  91, 171, 214,
      214, 199,  43, 114, 213,  66, 169, 120, 140, 119, 191, 106, 136,
       49,  63, 246, 103, 131,  61,  77,  70,  75,  41, 237, 162, 141,
      113, 121, 114, 224,   7, 191, 178, 186,  66, 252, 160,  77, 159,
      178,  28,  59,  33, 236,   0,   0,  93, 193,  84, 151, 129,   5,
      165,  62,  11,  89, 194,  33,   0, 249,  98, 149, 192, 205,  80,
       94, 178, 223, 182,  62, 117, 204, 227,  82,  37,  93, 187, 183,
      179,  18, 107, 148, 213, 225,  29,  32,   4, 239,  91,  93,  52,
      104,  18,  94, 115, 177, 157, 202, 233, 203, 221, 218, 175, 119,
      208, 131, 174, 212,  95, 222, 167, 163,  27,  76, 217
  };

  printf("Contents of input array block:\n");
  int block_ctr;
  for(block_ctr = 0; block_ctr < 128 ; ++block_ctr)
    printf("  block[%3d] = %"PRIu8"\n", block_ctr ,block[block_ctr]);

  SWord8 hash[64];

  sha512(hIn, block, hash);

  printf("sha512(hIn, block, hash) ->\n");
  int hash_ctr;
  for(hash_ctr = 0; hash_ctr < 64 ; ++hash_ctr)
    printf("  hash[%2d] = %"PRIu8"\n", hash_ctr ,hash[hash_ctr]);

  return 0;
}