# dephy_module_golden_sample

Golden sample for reusable C/Zephyr Dephy modules.

## Overview

This repo is the executable reference for reusable module structure. Use it to
start a new module or audit real modules for missing public API, source, tests,
Zephyr metadata, docs, or TODO files.

## Key Value

- Defines the expected reusable C/Zephyr module contract.
- Includes a minimal public API, portable C source, Linux unit test, and Zephyr
  metadata.
- Provides `scripts/audit_module_structure.sh` to check real module repos.
- Keeps product-specific workflow out of reusable module repos.

## How To Use

```sh
make -f Makefile.linux test
scripts/audit_module_structure.sh ../dephy_industrial_io ../modbus_zephyr_esp32 ../mqtt_min_broker
scripts/test_zephyr_module.sh --metadata-only
```

## Architecture Flow

```mermaid
flowchart LR
    Golden[Golden sample contract] --> Audit[audit_module_structure.sh]
    Audit --> Module[Target module repo]
    Module --> Include[include/*.h]
    Module --> Src[src/*.c]
    Module --> Tests[tests/unit_*.c]
    Module --> Zephyr[zephyr/module.yml + Kconfig]
```

## Example User Scenario

```mermaid
flowchart TD
    A[Create or refactor module] --> B[Follow golden layout]
    B --> C[Add public header and source]
    C --> D[Add Linux unit test]
    D --> E[Add Zephyr metadata]
    E --> F[Run audit script]
    F --> G[Product can pin module]
```

## Simple Principle

A reusable module should be buildable, testable, and auditable before any
product depends on it.

## Docs

- `docs/module_structure.md`: full reusable module contract.
- `docs/todo.md`: current TODO summary.

## License

MIT. See `LICENSE` and `NOTICE.md`. Reuse and references are allowed, but the
copyright notice and attribution to Judd (judadao) must be preserved.
