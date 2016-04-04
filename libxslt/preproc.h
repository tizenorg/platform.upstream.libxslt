/*
 * Summary: precomputing stylesheets
 * Description: this is the compilation phase, where most of the
 *              stylesheet is "compiled" into faster to use data.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __XML_XSLT_PRECOMP_H__
#define __XML_XSLT_PRECOMP_H__

#include <libxml/tree.h>
#include "xsltexports.h"
#include "xsltInternals.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Interfaces
 */
__attribute__ ((visibility ("default"))) extern const xmlChar *xsltExtMarker;

XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltElemPreCompPtr XSLTCALL
		xsltDocumentComp	(xsltStylesheetPtr style,
					 xmlNodePtr inst,
					 xsltTransformFunction function);

XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltStylePreCompute	(xsltStylesheetPtr style,
					 xmlNodePtr inst);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltFreeStylePreComps	(xsltStylesheetPtr style);

#ifdef __cplusplus
}
#endif

#endif /* __XML_XSLT_PRECOMP_H__ */

