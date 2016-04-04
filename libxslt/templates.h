/*
 * Summary: interface for the template processing
 * Description: This set of routine encapsulates XPath calls
 *              and Attribute Value Templates evaluation.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __XML_XSLT_TEMPLATES_H__
#define __XML_XSLT_TEMPLATES_H__

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include "xsltexports.h"
#include "xsltInternals.h"

#ifdef __cplusplus
extern "C" {
#endif

XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltEvalXPathPredicate		(xsltTransformContextPtr ctxt,
						 xmlXPathCompExprPtr comp,
		                                 xmlNsPtr *nsList,
						 int nsNr);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlChar * XSLTCALL
		xsltEvalTemplateString		(xsltTransformContextPtr ctxt,
						 xmlNodePtr contextNode,
						 xmlNodePtr inst);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlChar * XSLTCALL
		xsltEvalAttrValueTemplate	(xsltTransformContextPtr ctxt,
						 xmlNodePtr node,
						 const xmlChar *name,
						 const xmlChar *ns);
XSLTPUBFUN __attribute__ ((visibility ("default"))) const xmlChar * XSLTCALL
		xsltEvalStaticAttrValueTemplate	(xsltStylesheetPtr style,
						 xmlNodePtr node,
						 const xmlChar *name,
						 const xmlChar *ns,
						 int *found);

/* TODO: this is obviously broken ... the namespaces should be passed too ! */
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlChar * XSLTCALL
		xsltEvalXPathString		(xsltTransformContextPtr ctxt,
						 xmlXPathCompExprPtr comp);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlChar * XSLTCALL
		xsltEvalXPathStringNs		(xsltTransformContextPtr ctxt,
						 xmlXPathCompExprPtr comp,
						 int nsNr,
						 xmlNsPtr *nsList);

XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlNodePtr * XSLTCALL
		xsltTemplateProcess		(xsltTransformContextPtr ctxt,
						 xmlNodePtr node);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlAttrPtr XSLTCALL
		xsltAttrListTemplateProcess	(xsltTransformContextPtr ctxt,
						 xmlNodePtr target,
						 xmlAttrPtr cur);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlAttrPtr XSLTCALL
		xsltAttrTemplateProcess		(xsltTransformContextPtr ctxt,
						 xmlNodePtr target,
						 xmlAttrPtr attr);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlChar * XSLTCALL
		xsltAttrTemplateValueProcess	(xsltTransformContextPtr ctxt,
						 const xmlChar* attr);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlChar * XSLTCALL
		xsltAttrTemplateValueProcessNode(xsltTransformContextPtr ctxt,
						 const xmlChar* str,
						 xmlNodePtr node);
#ifdef __cplusplus
}
#endif

#endif /* __XML_XSLT_TEMPLATES_H__ */

