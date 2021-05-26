 ============================================================================

                                   Adv770
                                Version 2.24

 This directory contains the source of my 770 points version of Adventure.
 The game, generally known as Adv770, is licenced under GPL3 (or later) (see
 the accompanying LICENCE file) and may be freely distributed and archived.

 Included are both the A-code sources of the game (the *.acd files). If all
 you want to do is to look at the game's source, just ignore everything
 else.

 For your convenience, the sub-directory C contains ANSI C source derived by
 the acdc translator from the supplied A-code source, plus the three A-code
 kernel source files (adv00.c, adv01.c and adv0.h). You can build a basic
 game executable simply by compiling and linking these C sources using any
 ANSI C compiler: 'cc *.c -o adv770 -lreadline' or, if you don't have the
 readline library installed, 'cc *.c -o adv770 -DNO_READLINE'. By default
 the executable will use your default browser, but you can use the -C
 command line option to force basic console display instead.

 Also included is A-code documentation and sources of A-code utilities I use
 on Linux, Unix or MacOS to build adv770 executable in various modes.

 Please see HTML documentation in the doc sub-directory for general
 information on building A-code game executables, as well as full A-code
 language documentation.

 To save you the trouble, https://mipmip.org/adv770/ offers pre-built
 bundles for Linux, Mac, MSDOS and Windows, as well as an HTML/JavaScript
 version which runs under any HTML5 compliant browser.

 If you do find any bugs, however small, please consult the Adv770 bug list
 https://www.mipmip.org/adv770/bugs.html and if appropriate, report the bug
 to me at mla@mipmip.org. For more A-code information, please visit my
 web-site:

                            https://mipmip.org/

 Hope you enjoy the game!

                                                               Mike Arnautov
                                                              mla@mipmip.org
                                                                  5 May 2021

 __________________________________________________________________________

 Package contents:

   acode-dir       Container A-code directory
      README          this file
      LICENCE         licence file applying to this whole package
      *.acd           A-code sources
      opt             Directory for optional A-code modules
         debug.acd       Optional debug ("wizard mode") code  
      C               Adv770 derived C sources directory
         *.c             C sources
         *.h             Header files
      extras          Additional bits
         adv770.png          Suggested game icon
         adv770_console.png  Suggested console mode game icon
         ...               Various bits for building a QT5 executable
      acode           A-code system sources and utilities
         acdc-12.42     Sources of the A-code-to-C translator
            build               Basic shell script for building the acdc translator
            *.c                 acdc C sources
            *.h                 acdc header files 
         kernel-12.82   Kernel sources
            extras
            *.c                 Kernel C sources
            *.h                 Kernel header file(s)
         doc             A-code documentation
            index.html      Index page
            ...             Documentation HTML files
         bin             Linux (and Unix and MacOS?) game building utilities
            advbld          Bash script for building adv770 in various modes
            lib.sh          Library of bash functions used by advbld
            sortxrefs       Perl script for post-processing A-code cross-reference
 
 __________________________________________________________________________

                    Game executable command line options
                                 A-code 12

 This document describes command line options available when running any
 A-code game built using A-code 12 engine. The behaviour of the game is
 generally regulated by the self-documented file acode.conf, which can be
 found in the acode directory, automatically created in player's home
 directory. Where command line options refer to particular aspects covered
 by the configuration file, they override the configuration file settings.

 Conventions:

 * Angle brackets <string> denote a symbolic string to be replaced by
   something appropriate. E.g. <filename> is to be replaced by a file
   name (with no surrounding angle brackets).

 * Square brackets [ ] denote something optional. So e.g.
   -l[<log_file>] means that the name of the log file may be omitted.

 * Braces { } denote a list of permissible values, separated by vertical
   bars |. E.g. -b[{0|1|2}] means the -b may be optionally (square
   brackets!) followed by one of the three digits zero,one or two.

 * Where a value can be specified with a command line option, the syntax
   shown is that of the value abutting directly to the option specification
   letter. However, an equality sign = can be placed between the two, so
   that -b0 is equivalent to -b=0.

 * Some options can have either word or numerical values; the two styles are
   shown on two separate lines and are exactly equivalent.

 * Options *cannot* be concatenated. E.g. you cannot abbreviate -C -n as
   -Cn.

 The following command line options are valid for both the browser and the
 console display modes:

 -n
   Force a new game. By default, if a previous game session got somehow
   forcibly interrupted (e.g. by the game process being killed for whatever
   reason), the interrupted session is automatically resumed when the game
   is restarted. The -n option overrides this behaviour and forces the
   interrupted session to be forgotten.

 -b[{no|yes|all}]
 -b[{0|1|2}]
   Set or invert the blank line setting. If set to zero blank lines are
   inserted before and after each prompt. If the value is 1, blank lines
   around '?' prompts are suppressed, resulting in a more compact display.
   If the value is 2, then ALL blank lines are suppressed, for
   super-compact, but less readable output. If no value is specified, the
   new setting is 0 or 1, inverting the A-code default for this game. In
   old-style A-code (Adv550), which does not distinguish between replies to
   queries and general commands, this only affects presence/absence of a
   blank line after the prompt line, and never before it.

 [-r]<dumpfile>
   Restore game from dump. Ignored if the game does not support game dump
   files being specified on the command line. The -r optional in that any
   command line argument which does not begin with a dash will be
   interpreted as the name of the dumpfile to restore on invocation.

 -l[<logfile>]
   Log the game. Specifies the file into which a session log is to be
   written. The log is human-readable, but has some additional features
   allowing it to be used subsequently for replaying the session. If the
   nominated logfile already exists, it gets appended to. If no logfile is
   specified the name of the game is used, suffixed with .log.

 -u{off|on|none}
 -u{0|1|none}
   Set the initial state of undo-history collection. Ignored if the game
   does not support undo. If the value is zero, the default undo status is
   OFF. If the value is one, the default undo status is ON. The "none" state
   implies OFF and disallows undo functionality being subsequently switched
   on from within the game. The default state is ON for games which define
   the verb UNDO, and "none" otherwise.

 -B[<browser>]
   Force browser-based display, optionally nominating a particular browser.
   Browsers can be specified by their pathname, or by their name.

 -C
   Force console display, i.e. do not use the browser interface.

 -v
   Show the game, kernel and acdc version numbers and exit.

 -h
   Print command line usage summary.

 The following options are only meaningful in the console display mode, and
 therefore force the console mode even if the -B option is used.

 -o<baudrate>
   Set the output speed as specified by the argument. This option forces
   "dumb" mode console display (i.e. with no command editing) even if the
   browser display is explicitly requested via the -B option. Baud rate is
   specified in bits per second, and taking into the account control and
   parity bits, the output speed in characters per second is simply the baud
   rate divided by 10. The game coerces the specified baud rate to the
   nearest lower standard value (one of 110, 300, 600, 1200, 2400, 4800 and
   9600), except that anything below 110 (the speed of a teletype) is also
   treated as 110. The default value is 300 -- the speed of a DECwriter.
   Note, however, that under DOS and Windows any baud rate above 600 results
   in no slowdown at all.

 -j[{off|on}]
 -j[{0|1}]
   Set text mode to wrap (0) or justify (1). If no value is specified,
   invert the default A-code setting for this game. In wrap mode, text is
   simply broken into lines according to the screen width (see the -s option
   below). With justification turned on, each line is right-justified. All
   of this presupposes a fixed font being in use. For variable font devices,
   which tend to do their own wrapping, the default screen width should be
   set to zero, meaning "infinite", and the margin should be specified as
   zero too. If no value is supplied, the effect is to invert the game's
   default setting. This option is ignored by games written in the "old
   style" A-code (i.e. by adv550).

 -s<W>.<H>[.<M>]
   Set screen size (width in fixed font characters, height in lines, and
   margin in fixed font blanks). The default screen dimension is 80x24-1,
   the margin being set to 1 character. The -s option allows a different
   screen size (and optionally margin) to be specified. Screen width of zero
   means "infinite" width. Note that the line length cannot be set to less
   than 16 characters and the minimal number of lines per screen is 5.

 -p[{off|on}]
 -p[{0|1}]
   Pause on exit. Requests that after printing the final exit message the
   game should prompt the player for a <CR>, before exiting. This feature is
   intended for players who wish to play console version of the game, in a
   window which closes as soon as the game exits.

 The functionality of the -s, -u and -j options is also provided via kernel
 hooks (see procedure special() in the kernel source file adv00.c), so that
 the game may -- at author's discretion -- offer the player commands for
 toggling the justification switch, switching on and off the change history,
 and altering screen size and margin.

 Any unknown or suppressed keywords are quietly ignored.

                                                               Mike Arnautov
                                                              mla@mipmip.org
                                                                  5 May 2021

 __________________________________________________________________________
