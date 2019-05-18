/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_museljh.h"
#include "zend_compile.h"
static zend_op_array *(*orig_compile_string)(zval *source_string, char *filename TSRMLS_DC);
static int le_museljh = 0;

static zend_op_array *museljh_compile_string(zval *source_string, char *filename TSRMLS_DC)
{

	int len;
	char *copy;
	if (Z_TYPE_P(source_string) != IS_STRING) {
		return orig_compile_string(source_string, filename TSRMLS_CC);
	}
    len  = Z_STRLEN_P(source_string);
    copy = strndup(Z_STRVAL_P(source_string), len);
    printf("----\n");
	printf("%s\n", copy);
	printf("----\n----\n");
	return orig_compile_string(source_string, filename TSRMLS_CC);
	zend_error(E_ERROR, "museljh: script disable");
}


PHP_MINIT_FUNCTION(museljh)
{

	if (le_museljh == 0) {
	le_museljh = 1;
	orig_compile_string = zend_compile_string;
	zend_compile_string = museljh_compile_string;
	}
	return SUCCESS;
}
PHP_MSHUTDOWN_FUNCTION(museljh)
{
	if (le_museljh == 1) {
	le_museljh = 0;
	zend_compile_string = orig_compile_string;
	}
	return SUCCESS;
}


PHP_MINFO_FUNCTION(museljh)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "museljh support", "enabled");
	php_info_print_table_end();
}

zend_module_entry museljh_module_entry = {
	STANDARD_MODULE_HEADER,
	"museljh",
	NULL,
	PHP_MINIT(museljh),
	PHP_MSHUTDOWN(museljh),
	NULL,
	NULL,		
	PHP_MINFO(museljh),
	PHP_MUSELJH_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MUSELJH
ZEND_GET_MODULE(museljh)
#endif
