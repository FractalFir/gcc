#!/usr/bin/env sh

# The first command argument tells us which flavour to generate for
# the rest of the command line arguments.

what=$1
shift

# The second command argument is the prefix to prepend to all functions.
# It is defined by F7_PREFIX in $2.

PRE=$1
shift

case ${what} in
    head)
        cat << EOF
/*
   Auto-generated file, do not change by hand.

   Generated by:    `basename $0`.
   Generated using: F7_PREFIX = ${PRE} from $1.
		    F7F, F7F_cst, F7F_asm from libf7-common.mk.
   Included by:	    libf7.h.
   Used by: 	    libf7.c, libf7.h, libf7-asm.sx, f7-wraps.h.
*/

#ifndef F7_RENAMES_H
#define F7_RENAMES_H

#define F7_(name)  ${PRE}##name
#define F7P	   ${PRE}
EOF
        ;;

    c)
        if [ x${PRE} != xf7_ ]; then
            echo ""
            echo "/* Renames for libf7.c, libf7.h.  */"
            echo ""
            for x in $*; do
                echo "#define f7_$x ${PRE}$x"
            done
        fi
        ;;

    cst)
        if [ x${PRE} != xf7_ ]; then
            echo ""
            echo "/* Renames for libf7.c, libf7.h.  */"
            echo ""
            for x in $*; do
                echo "#define f7_const_${x}   ${PRE}const_${x}"
                echo "#define f7_const_${x}_P ${PRE}const_${x}_P"
            done
        fi
        ;;

    asm)
        if [ x${PRE} != xf7_ ]; then
            echo ""
            echo "/* Renames for libf7-asm.sx, f7-wraps.h.  */"
            echo ""
            for x in $*; do
                echo "#define f7_${x}_asm ${PRE}${x}_asm"
            done
        fi
        ;;

    tail)
        cat << EOF

#endif /* F7_RENAMES_H */
EOF
        ;;

    *)
        exit 1
        ;;
esac
