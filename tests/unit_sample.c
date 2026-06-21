#include <stdio.h>
#include <string.h>

#include <dephy_module_golden_sample/sample.h>

static int passed;
static int failed;

#define CHECK(expr) do {                                                    \
    if (expr) {                                                             \
        passed++;                                                           \
    } else {                                                                \
        failed++;                                                           \
        fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #expr);    \
    }                                                                       \
} while (0)

static void test_init_rejects_invalid_config(void)
{
    dephy_sample_config_t cfg = {0};

    CHECK(dephy_sample_init(NULL) == -1);
    CHECK(dephy_sample_init(&cfg) == -1);
}

static void test_lifecycle(void)
{
    dephy_sample_config_t cfg = {
        .device_id = "node-a",
    };
    dephy_sample_status_t status;

    CHECK(dephy_sample_init(&cfg) == 0);
    CHECK(dephy_sample_get_status(&status) == 0);
    CHECK(strcmp(status.device_id, "node-a") == 0);
    CHECK(strcmp(status.state, "initialized") == 0);

    CHECK(dephy_sample_start() == 0);
    CHECK(dephy_sample_get_status(&status) == 0);
    CHECK(strcmp(status.state, "running") == 0);
    CHECK(status.starts == 1);

    CHECK(dephy_sample_stop() == 0);
    CHECK(dephy_sample_get_status(&status) == 0);
    CHECK(strcmp(status.state, "stopped") == 0);
}

int main(void)
{
    printf("=== unit_sample ===\n");
    test_init_rejects_invalid_config();
    test_lifecycle();
    printf("%d passed, %d failed\n", passed, failed);
    return failed ? 1 : 0;
}

