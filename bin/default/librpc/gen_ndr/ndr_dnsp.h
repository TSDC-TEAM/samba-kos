/* header auto-generated by pidl */

#include "librpc/ndr/libndr.h"
#include "bin/default/librpc/gen_ndr/dnsp.h"

#ifndef _HEADER_NDR_dnsp
#define _HEADER_NDR_dnsp

#include "../librpc/ndr/ndr_dnsp.h"
#define NDR_DNSP_UUID "bdd66e9e-d45f-4202-85c0-6132edc4f30a"
#define NDR_DNSP_VERSION 0.0
#define NDR_DNSP_NAME "dnsp"
#define NDR_DNSP_HELPSTRING "DNSP interfaces"
extern const struct ndr_interface_table ndr_table_dnsp;
#define NDR_DNSP_CALL_COUNT (0)
enum ndr_err_code ndr_push_dns_record_type(struct ndr_push *ndr, int ndr_flags, enum dns_record_type r);
enum ndr_err_code ndr_pull_dns_record_type(struct ndr_pull *ndr, int ndr_flags, enum dns_record_type *r);
void ndr_print_dns_record_type(struct ndr_print *ndr, const char *name, enum dns_record_type r);
void ndr_print_dns_rpc_node_flags(struct ndr_print *ndr, const char *name, uint32_t r);
void ndr_print_dns_record_rank(struct ndr_print *ndr, const char *name, enum dns_record_rank r);
void ndr_print_dns_zone_type(struct ndr_print *ndr, const char *name, enum dns_zone_type r);
enum ndr_err_code ndr_push_dns_zone_update(struct ndr_push *ndr, int ndr_flags, enum dns_zone_update r);
enum ndr_err_code ndr_pull_dns_zone_update(struct ndr_pull *ndr, int ndr_flags, enum dns_zone_update *r);
void ndr_print_dns_zone_update(struct ndr_print *ndr, const char *name, enum dns_zone_update r);
void ndr_print_dns_property_id(struct ndr_print *ndr, const char *name, enum dns_property_id r);
void ndr_print_dns_dcpromo_flag(struct ndr_print *ndr, const char *name, enum dns_dcpromo_flag r);
enum ndr_err_code ndr_push_dnsp_soa(struct ndr_push *ndr, int ndr_flags, const struct dnsp_soa *r);
enum ndr_err_code ndr_pull_dnsp_soa(struct ndr_pull *ndr, int ndr_flags, struct dnsp_soa *r);
void ndr_print_dnsp_soa(struct ndr_print *ndr, const char *name, const struct dnsp_soa *r);
enum ndr_err_code ndr_push_dnsp_mx(struct ndr_push *ndr, int ndr_flags, const struct dnsp_mx *r);
enum ndr_err_code ndr_pull_dnsp_mx(struct ndr_pull *ndr, int ndr_flags, struct dnsp_mx *r);
void ndr_print_dnsp_mx(struct ndr_print *ndr, const char *name, const struct dnsp_mx *r);
enum ndr_err_code ndr_push_dnsp_hinfo(struct ndr_push *ndr, int ndr_flags, const struct dnsp_hinfo *r);
enum ndr_err_code ndr_pull_dnsp_hinfo(struct ndr_pull *ndr, int ndr_flags, struct dnsp_hinfo *r);
void ndr_print_dnsp_hinfo(struct ndr_print *ndr, const char *name, const struct dnsp_hinfo *r);
enum ndr_err_code ndr_push_dnsp_srv(struct ndr_push *ndr, int ndr_flags, const struct dnsp_srv *r);
enum ndr_err_code ndr_pull_dnsp_srv(struct ndr_pull *ndr, int ndr_flags, struct dnsp_srv *r);
void ndr_print_dnsp_srv(struct ndr_print *ndr, const char *name, const struct dnsp_srv *r);
void ndr_print_dnsp_ip4_array(struct ndr_print *ndr, const char *name, const struct dnsp_ip4_array *r);
void ndr_print_dnsp_dns_addr(struct ndr_print *ndr, const char *name, const struct dnsp_dns_addr *r);
enum ndr_err_code ndr_push_dnsp_dns_addr_array(struct ndr_push *ndr, int ndr_flags, const struct dnsp_dns_addr_array *r);
enum ndr_err_code ndr_pull_dnsp_dns_addr_array(struct ndr_pull *ndr, int ndr_flags, struct dnsp_dns_addr_array *r);
void ndr_print_dnsp_dns_addr_array(struct ndr_print *ndr, const char *name, const struct dnsp_dns_addr_array *r);
enum ndr_err_code ndr_push_dnsp_string_list(struct ndr_push *ndr, int ndr_flags, const struct dnsp_string_list *r);
enum ndr_err_code ndr_pull_dnsp_string_list(struct ndr_pull *ndr, int ndr_flags, struct dnsp_string_list *r);
void ndr_print_dnsp_string_list(struct ndr_print *ndr, const char *name, const struct dnsp_string_list *r);
size_t ndr_size_dnsp_string_list(const struct dnsp_string_list *r, int flags);
void ndr_print_dnsRecordData(struct ndr_print *ndr, const char *name, const union dnsRecordData *r);
enum ndr_err_code ndr_push_dnsp_DnssrvRpcRecord(struct ndr_push *ndr, int ndr_flags, const struct dnsp_DnssrvRpcRecord *r);
enum ndr_err_code ndr_pull_dnsp_DnssrvRpcRecord(struct ndr_pull *ndr, int ndr_flags, struct dnsp_DnssrvRpcRecord *r);
void ndr_print_dnsp_DnssrvRpcRecord(struct ndr_print *ndr, const char *name, const struct dnsp_DnssrvRpcRecord *r);
void ndr_print_dnsPropertyData(struct ndr_print *ndr, const char *name, const union dnsPropertyData *r);
enum ndr_err_code ndr_push_dnsp_DnsProperty(struct ndr_push *ndr, int ndr_flags, const struct dnsp_DnsProperty *r);
enum ndr_err_code ndr_pull_dnsp_DnsProperty(struct ndr_pull *ndr, int ndr_flags, struct dnsp_DnsProperty *r);
void ndr_print_dnsp_DnsProperty(struct ndr_print *ndr, const char *name, const struct dnsp_DnsProperty *r);
enum ndr_err_code ndr_push_dnsp_DnsProperty_short(struct ndr_push *ndr, int ndr_flags, const struct dnsp_DnsProperty_short *r);
enum ndr_err_code ndr_pull_dnsp_DnsProperty_short(struct ndr_pull *ndr, int ndr_flags, struct dnsp_DnsProperty_short *r);
void ndr_print_dnsp_DnsProperty_short(struct ndr_print *ndr, const char *name, const struct dnsp_DnsProperty_short *r);
#endif /* _HEADER_NDR_dnsp */
