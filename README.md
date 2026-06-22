# dephy_module_golden_sample

Golden sample for reusable C/Zephyr Dephy modules.

Use this repo as the structure contract for module repos that products consume
through `deps.json` and Zephyr `ZEPHYR_EXTRA_MODULES`.

## Contract

A reusable C/Zephyr module should carry:

```text
repo.json
AGENTS.md
README.md
VERSION
docs/todo.yaml
docs/module_structure.md
include/<module_name>/*.h
src/*.c
tests/unit_*.c
scripts/test_*.sh
Makefile.linux
CMakeLists.txt
Kconfig
zephyr/CMakeLists.txt
zephyr/Kconfig
zephyr/module.yml
```

## Commands

```sh
make -f Makefile.linux test
scripts/audit_module_structure.sh ../dephy_industrial_io ../modbus_zephyr_esp32 ../mqtt_min_broker
```

`make -f Makefile.linux test` builds the sample unit test and audits this repo's
own structure. `scripts/audit_module_structure.sh` checks real module repos for
drift from the golden contract.

## Module Use

Add this repository to `ZEPHYR_EXTRA_MODULES`, enable:

```conf
CONFIG_DEPHY_MODULE_GOLDEN_SAMPLE=y
```

Then include:

```c
#include <dephy_module_golden_sample/sample.h>
```

## TODO

TODO state is tracked in `docs/todo.yaml` and summarized in `docs/todo.md`.
