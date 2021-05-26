/* adv1.h: Adv770 - copyright Mike Arnautov 2021. Licensed under
 * GPL (version 3 or later) or the Modified BSD Licence, whichever
 * is asserted by the supplied LICENCE file.*/

#ifndef ADV1_H
#define ADV1_H
#define GAME_NAME "Adv770"
#define GAME_VERSION "2.24"
#define GAME_ID "Adv770 version 2.24, 04 May 2021"
#define STYLE 12
#ifndef ADV01
#define GAME_DATE "04 May 2021"
#define ACDC_VERSION "12.41, 15 Oct 2020"
#if defined(MSDOS) || defined(_WIN32)
#  define PERSISTENT_DATA "_adv770.adp"
#  define CGINAME "_adv770"
#else
#  define PERSISTENT_DATA ".adv770.adp"
#  define CGINAME ".adv770"
#endif
#define DBNAME "adv770.dat"
#define OBJSIZE 2
#define LOCSIZE 2
#define VARSIZE 1
#define FOBJ 3
#define LOBJ 194
#define FLOC 195
#define LLOC 703
#define FVERB 704
#define LVERB 1138
#define FVAR 1139
#define LVAR 1260
#define FTEXT 1260
#define LTEXT 3488
#define NOISE 24
#define COMMA 21
#define SEMICOLON 22
#define KNOT 124
#define PARSER 1258
#define INHAND 703
#define HERE 1141
#define THERE 1142
#define STATUS 1173
#define ARG1 1139
#define ARG2 1140
#define ARG3 1259
#define UNDO 738
#define REDO 739
#define UNDO_STAT 1187
#define UNDO_INFO 4
#define UNDO_TRIM 5
#define UNDO_INV 6
#define UNDO_BAD 7
#define UTF8 0
#define SCHIZOID 6
#define JUGGLED 6
#define MOVED 0
#define PLSCLARIFY 5
#define SEEN 4
#define AGAIN 724
#define ALL 3
#define EXCEPT 1138
#define TYPO 2553
#define IT 166
#define ADVCONTEXT 1175
#define DWARVEN 1257
#define DWARVISH     021
#define PROMPTED 4
#define FSPECIAL 723
#define LSPECIAL 742
#define FACT 704
#define LACT 722
#define FDIR 743
#define LDIR 755
#define SAY 730
#define BADWORD -2
#define AMBIGWORD -3
#define AMBIGTYPO -4
#define SCENEWORD -5
#define BADSYNTAX -6
#define NO_MATCH 98
#define NO_AMATCH 99
#define OBJ 0
#define LOC 1
#define VERB 2
#define FULL 3
#define BEENHERE 4
#define TERSE 2
#define BRIEF 1
#define PLAIN 0
#define DBSTATUS 0
#define LPROC 1139
#define KEY(X) (value[1139]==X || value[1140]==X)
#define INIT_PROC p1
#define REPEAT_PROC p2
#endif
#define SW_START     037
#define SW_BREAK     036
#define HOLDER       035
#define IGNORE_EOL   032
#define NEST_TEXT    031
#define QUOTE_START  030
#define TAG_START    027
#define TAG_END      026
#define NBSP         025
#define BLOCK_START  024
#define BLOCK_END    023
#define CENTRE_START 022
#define VHOLDER      020
#define VOCAB_SIZE 1273
#define TEXT_BYTES 513171
#define USEQUERY 0
#endif
