#ifndef __output_format_h__
#define __output_format_h__

#include "mean_qualities.h"

#include <stddef.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int genotype;
    int consensus_quality;
    int variant_allele_quality;
    int mean_mapping_quality;
    int somatic_score;
    int is_somatic;
    dqstats_t dqstats;
} sample_data_t;

typedef struct {
    const char* seq_name;
    uint32_t pos;

    /* genotype data*/
    int ref_base;
    int ref_base4;

    sample_data_t tumor;
    sample_data_t normal;
} sniper_output_t;

typedef struct {
    const char *refseq;
    const char *normal_sample_id;
    const char *tumor_sample_id;
} header_data_t;

typedef void(*output_fn)(FILE*, const sniper_output_t*);
typedef void(*output_header_fn)(FILE*, const header_data_t*);

typedef struct {
    output_header_fn header_fn;
    output_fn output_fn;
} output_formatter_t;

/* available formatters: vcf, classic */
const output_formatter_t *get_formatter(const char* name);

#ifdef __cplusplus
}
#endif

#endif /* __output_format_h__ */
