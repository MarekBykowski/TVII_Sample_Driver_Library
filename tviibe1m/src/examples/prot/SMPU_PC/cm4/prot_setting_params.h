#ifndef _CY_PROT_EXAMPLE_HEADERS_H_
#define _CY_PROT_EXAMPLE_HEADERS_H_

#define TP_PRIVIREGED         (1)              /* privileged */
#define TP_SECURE             (0)              /* non secure */
#define TP_PROT_CONTEXT       (6)              /* enable context 6 */

#define TP_PROHIBITED_ADDR    (0x08018000UL)   /* This area is going to be prohibited accessing from a master who has TP_PROHIBITED_CONTEXT as context */
#define TP_PROHIBITED_CONTEXT (5)

#define TP_PERMITTED_ADDR     (0x08019000UL)   /* This area is going to be permitted accessing from a master who has TP_PERMITTED_CONTEXT as context */
#define TP_PERMITTED_CONTEXT  (TP_PROT_CONTEXT)

#endif
