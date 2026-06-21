# dephy_module_golden_sample

Golden sample repository for reusable Dephy modules.

This repo demonstrates the expected shape of a module that can be consumed by
product repositories through `deps.json` and Zephyr `ZEPHYR_EXTRA_MODULES`.

## Layout

```text
dephy_module_golden_sample/
├── include/dephy_module_golden_sample/
│   └── sample.h
├── src/
│   ├── sample.c
│   └── main.c
├── zephyr/
│   ├── CMakeLists.txt
│   ├── Kconfig
│   └── module.yml
├── tests/
│   └── unit_sample.c
├── scripts/
│   └── test_zephyr_module.sh
├── CMakeLists.txt
├── Kconfig
├── Makefile.linux
├── VERSION
└── repo.json
```

## Module Contract

- `repo.json` marks this repo as `repo_type: module`.
- Public headers are stable and live under `include/<module_name>/`.
- Portable logic stays in `src/` and does not depend on product code.
- Zephyr metadata lives under `zephyr/`.
- Product repositories may pin this module in `deps.json`.

## Linux Build And Test

```bash
make -f Makefile.linux
make -f Makefile.linux test
```

## Zephyr Module Use

Add this repository to `ZEPHYR_EXTRA_MODULES`, then enable:

```conf
CONFIG_DEPHY_MODULE_GOLDEN_SAMPLE=y
```

An embedding app can then call:

```c
#include <dephy_module_golden_sample/sample.h>

dephy_sample_config_t cfg = {
    .device_id = "product-node",
};

dephy_sample_init(&cfg);
dephy_sample_start();
```

