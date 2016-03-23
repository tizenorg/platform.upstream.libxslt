/*
 * Summary: Locale handling
 * Description: Interfaces for locale handling. Needed for language dependent
 *              sorting.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Nick Wellnhofer
 */

#ifndef __XML_XSLTLOCALE_H__
#define __XML_XSLTLOCALE_H__

#include <libxml/xmlstring.h>

#ifdef XSLT_LOCALE_XLOCALE

#include <locale.h>
#include <xlocale.h>

#ifdef __GLIBC__
/*locale_t is defined only if _GNU_SOURCE is defined*/
typedef __locale_t xsltLocale;
#else
typedef locale_t xsltLocale;
#endif
typedef xmlChar xsltLocaleChar;

#elif defined(XSLT_LOCALE_WINAPI)

#include <windows.h>
#include <winnls.h>

typedef LCID xsltLocale;
typedef wchar_t xsltLocaleChar;

#else

/*
 * XSLT_LOCALE_NONE:
 * Macro indicating that locale are not supported
 */
#ifndef XSLT_LOCALE_NONE
#define XSLT_LOCALE_NONE
#endif

typedef void *xsltLocale;
typedef xmlChar xsltLocaleChar;

#endif

__attribute__ ((visibility ("default"))) xsltLocale xsltNewLocale(const xmlChar *langName);
__attribute__ ((visibility ("default"))) void xsltFreeLocale(xsltLocale locale);
__attribute__ ((visibility ("default"))) xsltLocaleChar *xsltStrxfrm(xsltLocale locale, const xmlChar *string);
__attribute__ ((visibility ("default"))) int xsltLocaleStrcmp(xsltLocale locale, const xsltLocaleChar *str1, const xsltLocaleChar *str2);
__attribute__ ((visibility ("default"))) void xsltFreeLocales(void);

#endif /* __XML_XSLTLOCALE_H__ */
