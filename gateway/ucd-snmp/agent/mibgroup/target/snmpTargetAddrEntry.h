
/* This file was generated by mib2c and is intended for use as a mib module
   for the ucd-snmp snmpd agent.  Edited by Michael Baer

   last changed 2/2/99.
*/

#ifndef _MIBGROUP_SNMPTARGETADDRENTRY_H
#define _MIBGROUP_SNMPTARGETADDRENTRY_H

/* we use header_generic and checkmib from the util_funcs module */

config_require(util_funcs)

/* Magic number definitions: */

#define   SNMPTARGETADDRTDOMAIN      1
#define   SNMPTARGETADDRTADDRESS     2
#define   SNMPTARGETADDRTIMEOUT      3
#define   SNMPTARGETADDRRETRYCOUNT   4
#define   SNMPTARGETADDRTAGLIST      5
#define   SNMPTARGETADDRPARAMS       6
#define   SNMPTARGETADDRSTORAGETYPE  7
#define   SNMPTARGETADDRROWSTATUS    8

#define   SNMPTARGETADDRTDOMAINCOLUMN      2
#define   SNMPTARGETADDRTADDRESSCOLUMN     3
#define   SNMPTARGETADDRTIMEOUTCOLUMN      4
#define   SNMPTARGETADDRRETRYCOUNTCOLUMN   5
#define   SNMPTARGETADDRTAGLISTCOLUMN      6
#define   SNMPTARGETADDRPARAMSCOLUMN       7
#define   SNMPTARGETADDRSTORAGETYPECOLUMN  8
#define   SNMPTARGETADDRROWSTATUSCOLUMN    9

/* structure definitions */

struct targetAddrTable_struct {
  char  *name;
  oid    tDomain[128];
  int    tDomainLen;
  char  *tAddress;
  int    timeout;
  int    retryCount;
  char  *tagList;
  char  *params;
  int    spinLock;
  int    storageType;
  int    rowStatus;
  struct targetAddrTable_struct *next;
};

/* function definitions */

extern void          init_snmpTargetAddrEntry(void);
extern void          shutdown_snmpTargetAddrEntry(void);
extern FindVarMethod var_snmpTargetAddrEntry;

void snmpd_parse_config_targetAddr( char *, char *);

WriteMethod write_snmpTargetAddrTDomain;
WriteMethod write_snmpTargetAddrTAddress;
WriteMethod write_snmpTargetAddrTimeout;
WriteMethod write_snmpTargetAddrRetryCount;
WriteMethod write_snmpTargetAddrTagList;
WriteMethod write_snmpTargetAddrParams;
WriteMethod write_snmpTargetAddrStorageType;
WriteMethod write_snmpTargetAddrRowStatus;


/* Only load this structure when this .h file is called in the snmp_vars.c 
   file in tha agent subdirectory of the source tree */

#ifdef IN_SNMP_VARS_C

/* this variable defines function callbacks and type return information 
   for the snmpTargetAddrEntry mib */

struct variable2 snmpTargetAddrEntry_variables[] = {
  { SNMPTARGETADDRTDOMAIN,     ASN_OBJECT_ID , RWRITE, 
    var_snmpTargetAddrEntry, 1, { SNMPTARGETADDRTDOMAINCOLUMN } },
  { SNMPTARGETADDRTADDRESS,    ASN_OCTET_STR , RWRITE, 
    var_snmpTargetAddrEntry, 1, { SNMPTARGETADDRTADDRESSCOLUMN } },
  { SNMPTARGETADDRTIMEOUT,     ASN_INTEGER   , RWRITE, 
    var_snmpTargetAddrEntry, 1, { SNMPTARGETADDRTIMEOUTCOLUMN } },
  { SNMPTARGETADDRRETRYCOUNT,  ASN_INTEGER   , RWRITE, 
    var_snmpTargetAddrEntry, 1, { SNMPTARGETADDRRETRYCOUNTCOLUMN } },
  { SNMPTARGETADDRTAGLIST,     ASN_OCTET_STR , RWRITE, 
    var_snmpTargetAddrEntry, 1, {SNMPTARGETADDRTAGLISTCOLUMN } },
  { SNMPTARGETADDRPARAMS,      ASN_OCTET_STR , RWRITE, 
    var_snmpTargetAddrEntry, 1, { SNMPTARGETADDRPARAMSCOLUMN } },
  { SNMPTARGETADDRSTORAGETYPE, ASN_INTEGER   , RWRITE, 
    var_snmpTargetAddrEntry, 1, { SNMPTARGETADDRSTORAGETYPECOLUMN } },
  { SNMPTARGETADDRROWSTATUS,   ASN_INTEGER   , RWRITE, 
    var_snmpTargetAddrEntry, 1, { SNMPTARGETADDRROWSTATUSCOLUMN } },

};

/* now load this mib into the agents mib table */
config_load_mib(1.3.6.1.6.3.12.1.2.1, 10, snmpTargetAddrEntry_variables)

#endif /* IN_SNMP_VARS_C */
#endif /* _MIBGROUP_SNMPTARGETADDRENTRY_H */
