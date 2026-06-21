#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <dephy_module_golden_sample/sample.h>

LOG_MODULE_REGISTER(dephy_sample_main, LOG_LEVEL_INF);

int main(void)
{
    dephy_sample_config_t cfg = {
        .device_id = "sample-module",
    };

    if (dephy_sample_init(&cfg) != 0 || dephy_sample_start() != 0) {
        LOG_ERR("sample module startup failed");
        return 1;
    }

    LOG_INF("sample module running");
    return 0;
}

