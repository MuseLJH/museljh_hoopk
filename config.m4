dnl $Id$
dnl config.m4 for extension museljh

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(museljh, for museljh support,
dnl Make sure that the comment is aligned:
dnl [  --with-museljh             Include museljh support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(museljh, whether to enable museljh support,
Make sure that the comment is aligned:
[  --enable-museljh           Enable museljh support])

if test "$PHP_MUSELJH" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-museljh -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/museljh.h"  # you most likely want to change this
  dnl if test -r $PHP_MUSELJH/$SEARCH_FOR; then # path given as parameter
  dnl   MUSELJH_DIR=$PHP_MUSELJH
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for museljh files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       MUSELJH_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$MUSELJH_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the museljh distribution])
  dnl fi

  dnl # --with-museljh -> add include path
  dnl PHP_ADD_INCLUDE($MUSELJH_DIR/include)

  dnl # --with-museljh -> check for lib and symbol presence
  dnl LIBNAME=museljh # you may want to change this
  dnl LIBSYMBOL=museljh # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $MUSELJH_DIR/$PHP_LIBDIR, MUSELJH_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_MUSELJHLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong museljh lib version or lib not found])
  dnl ],[
  dnl   -L$MUSELJH_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(MUSELJH_SHARED_LIBADD)

  PHP_NEW_EXTENSION(museljh, museljh.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
