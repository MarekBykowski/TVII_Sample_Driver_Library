#ifndef _CY_PROT_EXAMPLE_HEADERS_H_
#define _CY_PROT_EXAMPLE_HEADERS_H_

#define TP_PRIVIREGED         (1)              /* privileged */
#define TP_SECURE             (0)              /* non secure */
#define TP_PERMITTED_PC       (CY_PROT_PC6)    /* context 6 */
#define TP_PROHIBITED_PC      (CY_PROT_PC5)    /* context 5 */
#define TP_PERMITTED_PC_MASK  (1 << (TP_PERMITTED_PC-1u))
#define TP_PROHIBITED_PC_MASK (1 << (TP_PROHIBITED_PC-1u))

#endif
