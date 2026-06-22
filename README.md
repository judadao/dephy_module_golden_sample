# dephy_module_golden_sample

Golden sample for reusable C/Zephyr Dephy modules.

## Overview

This repo is the reference shape for reusable modules. Use it to start a new
module or audit existing modules for layout drift.

## Key Value

- One expected structure for module repos.
- Public API, portable source, tests, Zephyr metadata, docs, and TODO examples.
- Audit script for real module repos.
- Clear boundary between reusable modules and product apps.

## How To Use

```sh
make -f Makefile.linux test
scripts/audit_module_structure.sh ../dephy_industrial_io ../modbus_zephyr_esp32 ../mqtt_min_broker
```

For Zephyr:

```conf
CONFIG_DEPHY_MODULE_GOLDEN_SAMPLE=y
```

## Simple Principle

A reusable module should be buildable and testable on its own before a product
pins it.

## Docs

- `docs/module_structure.md`: full sample contract.
- `docs/todo.md`: current TODO summary.
