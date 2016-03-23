/*
 * Summary: interface for the XSLT import support
 * Description: macros and fuctions needed to implement and
 *              access the import tree
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __XML_XSLT_IMPORTS_H__
#define __XML_XSLT_IMPORTS_H__

#include <libxml/tree.h>
#include "xsltexports.h"
#include "xsltInternals.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * XSLT_GET_IMPORT_PTR:
 *
 * A macro to import pointers from the stylesheet cascading order.
 */
#define XSLT_GET_IMPORT_PTR(res, style, name) {			\
    xsltStylesheetPtr st = style;				\
    res = NULL;							\
    while (st != NULL) {					\
	if (st->name != NULL) { res = st->name; break; }	\
	st = xsltNextImport(st);				\
    }}

/**
 * XSLT_GET_IMPORT_INT:
 *
 * A macro to import intergers from the stylesheet cascading order.
 */
#define XSLT_GET_IMPORT_INT(res, style, name) {			\
    xsltStylesheetPtr st = style;				\
    res = -1;							\
    while (st != NULL) {					\
	if (st->name != -1) { res = st->name; break; }	\
	st = xsltNextImport(st);				\
    }}

/*
 * Module interfaces
 */
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
			xsltParseStylesheetImport(xsltStylesheetPtr style,
						  xmlNodePtr cur);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
			xsltParseStylesheetInclude
						 (xsltStylesheetPtr style,
						  xmlNodePtr cur);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltStylesheetPtr XSLTCALL
			xsltNextImport		 (xsltStylesheetPtr style);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
			xsltNeedElemSpaceHandling(xsltTransformContextPtr ctxt);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
			xsltFindElemSpaceHandling(xsltTransformContextPtr ctxt,
						  xmlNodePtr node);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltTemplatePtr XSLTCALL
			xsltFindTemplate	 (xsltTransformContextPtr ctxt,
						  const xmlChar *name,
						  const xmlChar *nameURI);

#ifdef __cplusplus
}
#endif

#endif /* __XML_XSLT_IMPORTS_H__ */

