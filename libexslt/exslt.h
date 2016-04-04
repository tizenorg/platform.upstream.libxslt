
#ifndef __EXSLT_H__
#define __EXSLT_H__

#include <libxml/tree.h>
#include <libxml/xpath.h>
#include "exsltexports.h"
#include <libexslt/exsltconfig.h>

#ifdef __cplusplus
extern "C" {
#endif

__attribute__ ((visibility ("default"))) EXSLTPUBVAR const char *exsltLibraryVersion;
__attribute__ ((visibility ("default"))) EXSLTPUBVAR const int exsltLibexsltVersion;
__attribute__ ((visibility ("default"))) EXSLTPUBVAR const int exsltLibxsltVersion;
__attribute__ ((visibility ("default"))) EXSLTPUBVAR const int exsltLibxmlVersion;

/**
 * EXSLT_COMMON_NAMESPACE:
 *
 * Namespace for EXSLT common functions
 */
#define EXSLT_COMMON_NAMESPACE ((const xmlChar *) "http://exslt.org/common")
/**
 * EXSLT_CRYPTO_NAMESPACE:
 *
 * Namespace for EXSLT crypto functions
 */
#define EXSLT_CRYPTO_NAMESPACE ((const xmlChar *) "http://exslt.org/crypto")
/**
 * EXSLT_MATH_NAMESPACE:
 *
 * Namespace for EXSLT math functions
 */
#define EXSLT_MATH_NAMESPACE ((const xmlChar *) "http://exslt.org/math")
/**
 * EXSLT_SETS_NAMESPACE:
 *
 * Namespace for EXSLT set functions
 */
#define EXSLT_SETS_NAMESPACE ((const xmlChar *) "http://exslt.org/sets")
/**
 * EXSLT_FUNCTIONS_NAMESPACE:
 *
 * Namespace for EXSLT functions extension functions
 */
#define EXSLT_FUNCTIONS_NAMESPACE ((const xmlChar *) "http://exslt.org/functions")
/**
 * EXSLT_STRINGS_NAMESPACE:
 *
 * Namespace for EXSLT strings functions
 */
#define EXSLT_STRINGS_NAMESPACE ((const xmlChar *) "http://exslt.org/strings")
/**
 * EXSLT_DATE_NAMESPACE:
 *
 * Namespace for EXSLT date functions
 */
#define EXSLT_DATE_NAMESPACE ((const xmlChar *) "http://exslt.org/dates-and-times")
/**
 * EXSLT_DYNAMIC_NAMESPACE:
 *
 * Namespace for EXSLT dynamic functions
 */
#define EXSLT_DYNAMIC_NAMESPACE ((const xmlChar *) "http://exslt.org/dynamic")

/**
 * SAXON_NAMESPACE:
 *
 * Namespace for SAXON extensions functions
 */
#define SAXON_NAMESPACE ((const xmlChar *) "http://icl.com/saxon")

EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltCommonRegister (void);
#ifdef EXSLT_CRYPTO_ENABLED
EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltCryptoRegister (void);
#endif
EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltMathRegister (void);
EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltSetsRegister (void);
EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltFuncRegister (void);
EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltStrRegister (void);
EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltDateRegister (void);
EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltSaxonRegister (void);
EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltDynRegister(void);

EXSLTPUBFUN __attribute__ ((visibility ("default"))) void EXSLTCALL exsltRegisterAll (void);

EXSLTPUBFUN __attribute__ ((visibility ("default"))) int EXSLTCALL exsltDateXpathCtxtRegister (xmlXPathContextPtr ctxt,
                                                      const xmlChar *prefix);
EXSLTPUBFUN __attribute__ ((visibility ("default"))) int EXSLTCALL exsltMathXpathCtxtRegister (xmlXPathContextPtr ctxt,
                                                      const xmlChar *prefix);
EXSLTPUBFUN __attribute__ ((visibility ("default"))) int EXSLTCALL exsltSetsXpathCtxtRegister (xmlXPathContextPtr ctxt,
                                                      const xmlChar *prefix);
EXSLTPUBFUN __attribute__ ((visibility ("default"))) int EXSLTCALL exsltStrXpathCtxtRegister (xmlXPathContextPtr ctxt,
                                                     const xmlChar *prefix);

#ifdef __cplusplus
}
#endif
#endif /* __EXSLT_H__ */

