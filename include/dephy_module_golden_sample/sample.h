#ifndef DEPHY_MODULE_GOLDEN_SAMPLE_SAMPLE_H
#define DEPHY_MODULE_GOLDEN_SAMPLE_SAMPLE_H

#include <stdint.h>

#define DEPHY_SAMPLE_DEVICE_ID_MAX 32
#define DEPHY_SAMPLE_STATUS_MAX 32

typedef struct {
    const char *device_id;
} dephy_sample_config_t;

typedef struct {
    char device_id[DEPHY_SAMPLE_DEVICE_ID_MAX];
    char state[DEPHY_SAMPLE_STATUS_MAX];
    uint32_t starts;
} dephy_sample_status_t;

int dephy_sample_init(const dephy_sample_config_t *config);
int dephy_sample_start(void);
int dephy_sample_stop(void);
int dephy_sample_get_status(dephy_sample_status_t *out);

#endif /* DEPHY_MODULE_GOLDEN_SAMPLE_SAMPLE_H */

