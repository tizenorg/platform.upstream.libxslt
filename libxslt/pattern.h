/*
 * Summary: interface for the pattern matching used in template matches.
 * Description: the implementation of the lookup of the right template
 *              for a given node must be really fast in order to keep
 *              decent performances.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __XML_XSLT_PATTERN_H__
#define __XML_XSLT_PATTERN_H__

#include "xsltInternals.h"
#include "xsltexports.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * xsltCompMatch:
 *
 * Data structure used for the implementation of patterns.
 * It is kept private (in pattern.c).
 */
typedef struct _xsltCompMatch xsltCompMatch;
typedef xsltCompMatch *xsltCompMatchPtr;

/*
 * Pattern related interfaces.
 */

XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltCompMatchPtr XSLTCALL
		xsltCompilePattern	(const xmlChar *pattern,
					 xmlDocPtr doc,
					 xmlNodePtr node,
					 xsltStylesheetPtr style,
					 xsltTransformContextPtr runtime);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltFreeCompMatchList	(xsltCompMatchPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltTestCompMatchList	(xsltTransformContextPtr ctxt,
					 xmlNodePtr node,
					 xsltCompMatchPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltNormalizeCompSteps	(void *payload,
					 void *data,
					 const xmlChar *name);

/*
 * Template related interfaces.
 */
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltAddTemplate		(xsltStylesheetPtr style,
					 xsltTemplatePtr cur,
					 const xmlChar *mode,
					 const xmlChar *modeURI);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltTemplatePtr XSLTCALL
		xsltGetTemplate		(xsltTransformContextPtr ctxt,
					 xmlNodePtr node,
					 xsltStylesheetPtr style);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltFreeTemplateHashes	(xsltStylesheetPtr style);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltCleanupTemplates	(xsltStylesheetPtr style);

#if 0
int		xsltMatchPattern	(xsltTransformContextPtr ctxt,
					 xmlNodePtr node,
					 const xmlChar *pattern,
					 xmlDocPtr ctxtdoc,
					 xmlNodePtr ctxtnode);
#endif
#ifdef __cplusplus
}
#endif

#endif /* __XML_XSLT_PATTERN_H__ */

