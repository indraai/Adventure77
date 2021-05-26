/* major.h (acdc) - copyright Mike Arnautov 1990-2020.
 * Licensed under GPL, version 3 or later (see the supplied LICENCE file).
 *
 * 02 Jul 20   MLA           Added CIF and CENDIF for Adv580.
 * 22 Jun 20   MLA           Added COMMA and SEMICOLON major types.
 * 04 Apr 12   MLA           Removed redundant definition of FREE.
 * 21 Mar 08   MLA           Added embedded texts.
 * 12 Mar 08   MLA           Version 12 changes.
 * 07 Mar 08   MLA           Removed LIST, NOLIST, XREF and NOXREF.
 * 27 Aug 05   MLA           Restored GAMEID for backward compatibility.
 * 20 Feb 05   MLA           Added separate VERSION and DATE.
 * 03 Mar 03   MLA           Added AUTHOR.
 * 10 Mar 02   MLA           Added XREF/NOXREF.
 * 21 Dec 01   MLA           Tidied up.
 * 14 Mar 01   MLA           Added STYLE directive.
 * 31 Dec 98   MLA           Added ARRAY type. 
 * 15 Sep 90   MLA           Initial coding.
 */

/* First the major data types -- the real ones */

#define OBJECT       0         /* A thing in the game */
#define OBJ          0         /* Ditto */
#define PLACE        1         /* A location in the game */
#define LOCATION     1         /* Ditto */
#define LOC          1         /* Ditto */
#define WORD         2         /* A dictionary word (verb, noun, etc...) */
#define VERB         2         /* Ditto */
#define VARIABLE     3         /* A variable or an array */
#define VAR          3         /* Ditto */
#define TEXT         4         /* A "random text", complete or a fragment */
#define PROCEDURE    5         /* A callable procedure */
#define PROC         5         /* Ditto */
#define CONSTANT     6         /* A symbolic value */
#define CONST        6         /* Ditto */
#define MAXTYPES  CONSTANT     /* In case we ever need to define more of them */

/* Next lot are data psudo-types, i.e. special cases of the real ones */
/* SYNONYM is for style 1 only. The lot after that not yet in use. */

#define FLAGS       10         /* A kind of constant */
#define STATE       11         /* Ditto */
#define FRAGMENT    12         /* An inclomplete text */
#define FRAG        12         /* Ditto */
#define EMBEDDED    13         /* A text embedded in code */
#define ARRAY       14         /* An extended variable */
#define SYNONYM     15         /* An additional name for name or place */
#define SYNON       15         /* Ditto */
#define NOUN        16         /* A kind of non-verb word */
#define ADJECTIVE   17         /* Ditto */
#define ADJ         17         /* Ditto */
#define PREPOSITION 18         /* Ditto */
#define PREP        18         /* Ditto */

/* The PARSER sub-definitions (COMMA etc) must be in the same order as
 * tokens in the ptype[] definition in domajor.c */

#define PARSER      20         /* Kernel-level parser word */
#define COMMA       21         /* Object list separator(s) */
#define SEMICOLON   22         /* In-line command separator(s) */
#define REPEATER    23         /* Command repeater */
#define NOISE       24         /* Word to ignore */

/* Now various procedure types */

#define ACTION      30         /* Code chunk associated with a dictionary word */
#define AT          31         /* Code chunk associated with a location */
#define INIT        32         /* Initialisation code chunk */
#define REPEAT      33         /* Code chunk of the main game loop */

/* Two compilation directives (have chucked LIST/NOLIST and XREF/NOXREF). */

#define INCLUDE     40         /* Include a source file */
#define CONCLUDE    41         /* Conditional include */

/* Game header (description) directives */

#define NAME        50         /* Game's name */
#define AUTHOR      51         /* Game's author */
#define GVERSION    52         /* Game's version string */
#define DATE        53         /* Game's date */
#define STYLE       54         /* A-code style */
#define UTF8        55         /* UTF8 support */

/* Finally, the deprecated directives -- you don't want to know them */

#define DEFINE      90         /* A-code 1 only */
#define GAMEID      91         /* A-code 10 only */
#define DBNAME      92         /* Obsolete  style 10 directive */
#define CIF         93         /* Goetz's text variant start */
#define CENDIF      94         /* End of a text variant */

/*====================================================================*/
