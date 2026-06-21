# Module Structure

Reusable modules should keep a small public API under `include/`, portable
implementation under `src/`, and Zephyr integration under `zephyr/`.

Product repositories should not copy module code. They should pin module tags or
commits in `deps.json`, sync the module into `deps/`, and include the public
headers from the synced checkout.

