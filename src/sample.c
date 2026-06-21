#include <stdio.h>
#include <string.h>

#include <dephy_module_golden_sample/sample.h>

static dephy_sample_status_t status;
static uint8_t initialized;

static void copy_str(char *dst, size_t cap, const char *src)
{
    if (!dst || cap == 0) {
        return;
    }
    if (!src) {
        src = "";
    }
    snprintf(dst, cap, "%s", src);
}

int dephy_sample_init(const dephy_sample_config_t *config)
{
    if (!config || !config->device_id || config->device_id[0] == '\0') {
        return -1;
    }

    memset(&status, 0, sizeof(status));
    copy_str(status.device_id, sizeof(status.device_id), config->device_id);
    copy_str(status.state, sizeof(status.state), "initialized");
    initialized = 1;
    return 0;
}

int dephy_sample_start(void)
{
    if (!initialized) {
        return -1;
    }

    copy_str(status.state, sizeof(status.state), "running");
    status.starts++;
    return 0;
}

int dephy_sample_stop(void)
{
    if (!initialized) {
        return -1;
    }

    copy_str(status.state, sizeof(status.state), "stopped");
    return 0;
}

int dephy_sample_get_status(dephy_sample_status_t *out)
{
    if (!out || !initialized) {
        return -1;
    }

    *out = status;
    return 0;
}

