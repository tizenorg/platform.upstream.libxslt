/*
 * Summary: interface for the extension support
 * Description: This provide the API needed for simple and module
 *              extension support.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __XML_XSLT_EXTENSION_H__
#define __XML_XSLT_EXTENSION_H__

#include <libxml/xpath.h>
#include "xsltexports.h"
#include "xsltInternals.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Extension Modules API.
 */

/**
 * xsltInitGlobals:
 *
 * Initialize the global variables for extensions
 *
 */

XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltInitGlobals                 (void);

/**
 * xsltStyleExtInitFunction:
 * @ctxt:  an XSLT stylesheet
 * @URI:  the namespace URI for the extension
 *
 * A function called at initialization time of an XSLT extension module.
 *
 * Returns a pointer to the module specific data for this transformation.
 */
typedef void * (*xsltStyleExtInitFunction)	(xsltStylesheetPtr style,
						 const xmlChar *URI);

/**
 * xsltStyleExtShutdownFunction:
 * @ctxt:  an XSLT stylesheet
 * @URI:  the namespace URI for the extension
 * @data:  the data associated to this module
 *
 * A function called at shutdown time of an XSLT extension module.
 */
typedef void (*xsltStyleExtShutdownFunction)	(xsltStylesheetPtr style,
						 const xmlChar *URI,
						 void *data);

/**
 * xsltExtInitFunction:
 * @ctxt:  an XSLT transformation context
 * @URI:  the namespace URI for the extension
 *
 * A function called at initialization time of an XSLT extension module.
 *
 * Returns a pointer to the module specific data for this transformation.
 */
typedef void * (*xsltExtInitFunction)	(xsltTransformContextPtr ctxt,
					 const xmlChar *URI);

/**
 * xsltExtShutdownFunction:
 * @ctxt:  an XSLT transformation context
 * @URI:  the namespace URI for the extension
 * @data:  the data associated to this module
 *
 * A function called at shutdown time of an XSLT extension module.
 */
typedef void (*xsltExtShutdownFunction) (xsltTransformContextPtr ctxt,
					 const xmlChar *URI,
					 void *data);

XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRegisterExtModule	(const xmlChar *URI,
					 xsltExtInitFunction initFunc,
					 xsltExtShutdownFunction shutdownFunc);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRegisterExtModuleFull
					(const xmlChar * URI,
					 xsltExtInitFunction initFunc,
					 xsltExtShutdownFunction shutdownFunc,
					 xsltStyleExtInitFunction styleInitFunc,
					 xsltStyleExtShutdownFunction styleShutdownFunc);

XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltUnregisterExtModule	(const xmlChar * URI);

XSLTPUBFUN __attribute__ ((visibility ("default"))) void * XSLTCALL
		xsltGetExtData		(xsltTransformContextPtr ctxt,
					 const xmlChar *URI);

XSLTPUBFUN __attribute__ ((visibility ("default"))) void * XSLTCALL
		xsltStyleGetExtData	(xsltStylesheetPtr style,
					 const xmlChar *URI);
#ifdef XSLT_REFACTORED
XSLTPUBFUN void * XSLTCALL
		xsltStyleStylesheetLevelGetExtData(
					 xsltStylesheetPtr style,
					 const xmlChar * URI);
#endif
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltShutdownCtxtExts	(xsltTransformContextPtr ctxt);

XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltShutdownExts	(xsltStylesheetPtr style);

XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltTransformContextPtr XSLTCALL
		xsltXPathGetTransformContext
					(xmlXPathParserContextPtr ctxt);

/*
 * extension functions
*/
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRegisterExtModuleFunction
					(const xmlChar *name,
					 const xmlChar *URI,
					 xmlXPathFunction function);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlXPathFunction XSLTCALL
	xsltExtModuleFunctionLookup	(const xmlChar *name,
					 const xmlChar *URI);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltUnregisterExtModuleFunction
					(const xmlChar *name,
					 const xmlChar *URI);

/*
 * extension elements
 */
typedef xsltElemPreCompPtr (*xsltPreComputeFunction)
					(xsltStylesheetPtr style,
					 xmlNodePtr inst,
					 xsltTransformFunction function);

XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltElemPreCompPtr XSLTCALL
		xsltNewElemPreComp	(xsltStylesheetPtr style,
					 xmlNodePtr inst,
					 xsltTransformFunction function);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltInitElemPreComp	(xsltElemPreCompPtr comp,
					 xsltStylesheetPtr style,
					 xmlNodePtr inst,
					 xsltTransformFunction function,
					 xsltElemPreCompDeallocator freeFunc);

XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRegisterExtModuleElement
					(const xmlChar *name,
					 const xmlChar *URI,
					 xsltPreComputeFunction precomp,
					 xsltTransformFunction transform);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltTransformFunction XSLTCALL
		xsltExtElementLookup	(xsltTransformContextPtr ctxt,
					 const xmlChar *name,
					 const xmlChar *URI);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltTransformFunction XSLTCALL
		xsltExtModuleElementLookup
					(const xmlChar *name,
					 const xmlChar *URI);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltPreComputeFunction XSLTCALL
		xsltExtModuleElementPreComputeLookup
					(const xmlChar *name,
					 const xmlChar *URI);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltUnregisterExtModuleElement
					(const xmlChar *name,
					 const xmlChar *URI);

/*
 * top-level elements
 */
typedef void (*xsltTopLevelFunction)	(xsltStylesheetPtr style,
					 xmlNodePtr inst);

XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRegisterExtModuleTopLevel
					(const xmlChar *name,
					 const xmlChar *URI,
					 xsltTopLevelFunction function);
XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltTopLevelFunction XSLTCALL
		xsltExtModuleTopLevelLookup
					(const xmlChar *name,
					 const xmlChar *URI);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltUnregisterExtModuleTopLevel
					(const xmlChar *name,
					 const xmlChar *URI);


/* These 2 functions are deprecated for use within modules. */
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRegisterExtFunction	(xsltTransformContextPtr ctxt,
					 const xmlChar *name,
					 const xmlChar *URI,
					 xmlXPathFunction function);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRegisterExtElement	(xsltTransformContextPtr ctxt,
					 const xmlChar *name,
					 const xmlChar *URI,
					 xsltTransformFunction function);

/*
 * Extension Prefix handling API.
 * Those are used by the XSLT (pre)processor.
 */

XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltRegisterExtPrefix	(xsltStylesheetPtr style,
					 const xmlChar *prefix,
					 const xmlChar *URI);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltCheckExtPrefix	(xsltStylesheetPtr style,
					 const xmlChar *URI);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltCheckExtURI		(xsltStylesheetPtr style,
					 const xmlChar *URI);
XSLTPUBFUN __attribute__ ((visibility ("default"))) int XSLTCALL
		xsltInitCtxtExts	(xsltTransformContextPtr ctxt);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltFreeCtxtExts	(xsltTransformContextPtr ctxt);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltFreeExts		(xsltStylesheetPtr style);

XSLTPUBFUN __attribute__ ((visibility ("default"))) xsltElemPreCompPtr XSLTCALL
		xsltPreComputeExtModuleElement
					(xsltStylesheetPtr style,
					 xmlNodePtr inst);
/*
 * Extension Infos access.
 * Used by exslt initialisation
 */

XSLTPUBFUN __attribute__ ((visibility ("default"))) xmlHashTablePtr XSLTCALL
		xsltGetExtInfo		(xsltStylesheetPtr style,
					 const xmlChar *URI);

/**
 * Test module http://xmlsoft.org/XSLT/
 */
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltRegisterTestModule	(void);
XSLTPUBFUN __attribute__ ((visibility ("default"))) void XSLTCALL
		xsltDebugDumpExtensions	(FILE * output);


#ifdef __cplusplus
}
#endif

#endif /* __XML_XSLT_EXTENSION_H__ */

