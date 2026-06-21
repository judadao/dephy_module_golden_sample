# Module Golden Sample TODO

Tracks work for the reusable module repository template.

## Repo Identity

- [x] Add `repo.json` so the template is machine-recognizable as
      `repo_type: module`.
- [x] Document that product repositories may pin this module in `deps.json`.

## Module Structure

- [x] Add public headers under `include/dephy_module_golden_sample/`.
- [x] Add portable implementation under `src/`.
- [x] Add Zephyr module metadata under `zephyr/`.
- [x] Add Linux unit test coverage under `tests/`.
- [x] Add a Linux `Makefile.linux`.
- [x] Add a Zephyr module metadata smoke script.

## Validation

- [x] Run `make -f Makefile.linux test`.
- [x] Run `scripts/test_zephyr_module.sh --metadata-only`.
