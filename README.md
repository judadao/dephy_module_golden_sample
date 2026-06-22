# dephy_module_golden_sample

Golden sample for reusable C/Zephyr Dephy modules.

This repo defines the expected shape of a reusable module. It is both an example
and an audit target: module repos can compare themselves against this structure
to avoid drifting into product-specific layout or missing test/doc metadata.

## Overview

Use this repo as the reference shape for reusable modules. It shows what files a
module should carry, how Linux tests and Zephyr metadata fit together, and how
to audit real module repos for structure drift.

## Key Value

- New modules need a repeatable starting point.
- Existing modules need an objective structure check.
- Product repos should be able to consume modules through the same dependency
  and Zephyr conventions.
- AI and humans need one compact reference for where files should live.

## How To Use

1. Start a reusable module from this layout.
2. Put public APIs in `include/<module_name>/`.
3. Put portable implementation in `src/`.
4. Add Linux tests and Zephyr metadata before product integration.
5. Run the audit script against real modules when refactoring.

## How It Works

The golden sample carries a minimal public API, implementation, Linux unit test,
Zephyr metadata, TODO file, and structure documentation. The audit script checks
whether target module repos contain the expected contract files and reports
drift. The goal is not to force identical business logic; it is to keep the
module boundary predictable.

## Contract

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
