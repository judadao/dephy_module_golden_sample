# Repository Guidelines

## Project Structure

This repository is a golden sample for reusable Dephy modules. Public APIs live
in `include/dephy_module_golden_sample/`, portable implementation lives in
`src/`, Zephyr module metadata lives in `zephyr/`, Linux tests live in `tests/`,
and helper scripts live in `scripts/`.

## Development Model

Keep module behavior reusable and product-agnostic. Product-specific workflows,
UI, provisioning, and deployment logic belong in product repositories. Product
repositories consume modules by pinning tags or commits in their `deps.json`.

## Commands

- `make -f Makefile.linux`: build the Linux static library.
- `make -f Makefile.linux test`: trigger Linux and metadata checks through
  `dephy_testkit`.
- `make -f Makefile.linux direct-test`: build and run Linux unit tests without
  result wrapping for local debugging.
- `./scripts/test_zephyr_module.sh`: smoke-test Zephyr module metadata in an
  existing Zephyr workspace.

## Style

Use C11, four-space indentation, snake_case symbols, small public APIs, and
uppercase compile-time symbols.

## Testing

The default `test` target must trigger suites through `dephy_testkit` using
`scripts/trigger_testkit.sh` so CI receives a JSON result line for each suite.
When adding or changing a test case or test script, add or update the matching
Makefile target and make sure it is reachable from a `testkit-*` target.
