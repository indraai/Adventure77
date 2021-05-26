/* recase.c (acdc) - copyright Mike Arnautov 1990-2020.
 * Licensed under GPL, version 3 or later (see the supplied LICENCE file).
 *
 * 01 Jul 20   MLA           Allowed for style 2.
 *                           Bug: check that recasing is actually required.
 * 03 Mar 16   MLA           Removed non-ANSI C support.
 * 24 Jul 99   MLA           Fixed complier warnings.
 * 06 Mar 91   MLA           Provide own tolower/upper, to guard against
 *                           implementations which make no checks.
 * 15 Sep 90   MLA           Initial coding.
 *
 */

// #include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#define MAX_UTF8_CHAR 0x0010FFFF
#define MAX_UTF8_LEN  4

unsigned utf8proc_tolower(unsigned);
unsigned utf8proc_toupper(unsigned);

#define TOLOWER(x) (x >= 'A' && x <= 'Z') ? x += 'a' - 'A' : x
#define TOUPPER(x) (x >= 'a' && x <= 'z') ? x += 'A' - 'a' : x

static int utf8_to_unicode(
  char *line, unsigned index, unsigned len, unsigned *res)
{
  if (index >= len)
  {
    *res = 0;
    return 0;
  }
      
  unsigned value;
  unsigned char c = line[index];
  unsigned bytes, mask, i;
   
  *res = c;
  line += index;
  len -= index;
    
/* 0xxxxxxx is valid utf8
 * 10xxxxxx is invalid UTF-8, we assume it is Latin1
 */
  if (c < 0xc0) return 1;
   
/* OK, it's 11xxxxxx, do a stupid decode */
  mask = 0x20;
  bytes = 2;
  while (c & mask)
  {
    bytes++;
    mask >>= 1;   
  }
        
/* Invalid? Do it as a single byte Latin1
 */ 
  if (bytes > MAX_UTF8_LEN) return 1;  
  if (bytes > len) return 1;
    
  value = c & (mask-1);
    
/* OK, do the bytes */   
  for (i = 1; i < bytes; i++)
  {
    c = line[i];
    if ((c & 0xc0) != 0x80) return 1;
    value = (value << 6) | (c & 0x3f);
  }
  if (value > MAX_UTF8_CHAR)
    return 1;
  *res = value;   
  return bytes;
}

static void reverse_string(char *begin, char *end)
{
  do
  {
    char a = *begin, b = *end;
    *end = a; *begin = b;
    begin++; end--;
  } while (begin < end);
}

unsigned unicode_to_utf8(unsigned int c, char *utf8)
{
  int bytes = 1;

  *utf8 = c;
  if (c >= 0x80) 
  {
    unsigned int prefix = 0x80;
    unsigned max = 0x3f;
    char *p = utf8;
    do 
    {
      *p++ = 0x80 + (c & 0x3f);
      bytes++;
      prefix = 0x80 | (prefix >> 1);
      max >>= 1;
      c >>= 6;            /* We use 6-bits in each extension byte */
    } while (c > max);
    *p = (prefix | c);      /* Add in the final byte */
    reverse_string(utf8, p);
  }
  return bytes;
}

void recase(int key, char *instr)
{
  char *in = instr;
  unsigned char outstr [1024];
  unsigned char *out = outstr;
  unsigned gph;
  int ilen, olen;
  while (*in)
  {
    ilen = utf8_to_unicode(in, 0, 8, &gph);
    in += ilen;
    if (key != LOWERCASE)
    {
      if (ilen == 1)
        gph = TOUPPER (gph);
      else
        gph = utf8proc_toupper (gph);
      if (key == CAPITALISE)
        key = LOWERCASE;
    }
    else
    {
      if (ilen == 1)
        gph = TOLOWER (gph);
      else
        gph = utf8proc_tolower (gph);
    } 
    olen = unicode_to_utf8 (gph, out);
    out += olen;
    if (ilen != olen)
    {
      fprintf(stderr, "Length trouble: %d => %d\n", ilen, olen);
      exit(1);
    }
    strcpy (in,out);
  }
}

void main ()
{
  char upper [64];
  char lower [64];
  strcpy (upper, "ЯЩИК");
  puts (upper);
  recase (LOWERCASE, upper);
  puts (upper);
}
