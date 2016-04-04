/*
 * Summary: the XSLT engine transformation part.
 * Description: This module implements the bulk of the actual
 *              transformation processing. Most of the xsl: element
 *              constructs are implemented in this module.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __XML_XSLT_TRANSFORM_H__
#define __XML_XSLT_TRANSFORM_H__

#include <libxml/parser.h>
#include <libxml/xmlIO.h>
#include "xsltexports.h"
#include <libxslt/xsltInternals.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * XInclude default processing.
 */
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltSetXIncludeDefault	(int xinclude);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltGetXIncludeDefault	(void);

/**
 * Export context to users.
 */
XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltTransformContextPtr XSLTCALL
		xsltNewTransformContext	(xsltStylesheetPtr style,
					 xmlDocPtr doc);

XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltFreeTransformContext(xsltTransformContextPtr ctxt);

XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlDocPtr XSLTCALL
		xsltApplyStylesheetUser	(xsltStylesheetPtr style,
					 xmlDocPtr doc,
					 const char **params,
					 const char *output,
					 FILE * profile,
					 xsltTransformContextPtr userCtxt);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
                xsltProcessOneNode      (xsltTransformContextPtr ctxt,
                                         xmlNodePtr node,
                                         xsltStackElemPtr params);
/**
 * Private Interfaces.
 */
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltApplyStripSpaces	(xsltTransformContextPtr ctxt,
					 xmlNodePtr node);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlDocPtr XSLTCALL
		xsltApplyStylesheet	(xsltStylesheetPtr style,
					 xmlDocPtr doc,
					 const char **params);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlDocPtr XSLTCALL
		xsltProfileStylesheet	(xsltStylesheetPtr style,
					 xmlDocPtr doc,
					 const char **params,
					 FILE * output);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRunStylesheet	(xsltStylesheetPtr style,
					 xmlDocPtr doc,
					 const char **params,
					 const char *output,
					 xmlSAXHandlerPtr SAX,
					 xmlOutputBufferPtr IObuf);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRunStylesheetUser	(xsltStylesheetPtr style,
					 xmlDocPtr doc,
					 const char **params,
					 const char *output,
					 xmlSAXHandlerPtr SAX,
					 xmlOutputBufferPtr IObuf,
					 FILE * profile,
					 xsltTransformContextPtr userCtxt);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltApplyOneTemplate	(xsltTransformContextPtr ctxt,
					 xmlNodePtr node,
					 xmlNodePtr list,
					 xsltTemplatePtr templ,
					 xsltStackElemPtr params);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltDocumentElem	(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltSort		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltCopy		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltText		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltElement		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltComment		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltAttribute		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltProcessingInstruction(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltCopyOf		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltValueOf		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltNumber		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltApplyImports	(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltCallTemplate	(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltApplyTemplates	(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltChoose		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltIf			(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltForEach		(xsltTransformContextPtr ctxt,
	                                 xmlNodePtr node,
					 xmlNodePtr inst,
					 xsltStylePreCompPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltRegisterAllElement	(xsltTransformContextPtr ctxt);

XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlNodePtr XSLTCALL
		xsltCopyTextString	(xsltTransformContextPtr ctxt,
					 xmlNodePtr target,
					 const xmlChar *string,
					 int noescape);

/* Following 2 functions needed for libexslt/functions.c */
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltLocalVariablePop	(xsltTransformContextPtr ctxt,
					 int limitNr,
					 int level);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltLocalVariablePush	(xsltTransformContextPtr ctxt,
					 xsltStackElemPtr variable,
					 int level);
/*
 * Hook for the debugger if activated.
 */
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xslHandleDebugger	(xmlNodePtr cur,
					 xmlNodePtr node,
					 xsltTemplatePtr templ,
					 xsltTransformContextPtr ctxt);

#ifdef __cplusplus
}
#endif

#endif /* __XML_XSLT_TRANSFORM_H__ */

