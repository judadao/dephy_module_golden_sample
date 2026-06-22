# Module Structure

Reusable modules should keep a small public API under `include/`, portable
implementation under `src/`, and Zephyr integration under `zephyr/`.

Product repositories should not copy module code. They should pin module tags or
commits in `deps.json`, sync the module into `deps/`, and include the public
headers from the synced checkout.

## C/Zephyr Module Contract

Reusable C/Zephyr modules should carry:

- `repo.json`, `README.md`, `VERSION`, and `AGENTS.md`
- `docs/todo.yaml` and `docs/module_structure.md`
- public headers under `include/`
- portable C implementation under `src/`
- Linux unit tests under `tests/`
- validation scripts under `scripts/`
- `Makefile.linux`, root `CMakeLists.txt`, and root `Kconfig`
- Zephyr metadata under `zephyr/`

Run `scripts/audit_module_structure.sh MODULE_REPO...` to check this contract.
