#!/bin/sh
set -eu

failures=0

usage() {
    echo "usage: $0 MODULE_REPO [MODULE_REPO ...]" >&2
}

check_path() {
    repo="$1"
    path="$2"
    if [ ! -e "$repo/$path" ]; then
        echo "$repo: missing $path" >&2
        failures=$((failures + 1))
    fi
}

check_dir_has_file() {
    repo="$1"
    dir="$2"
    pattern="$3"
    if ! find "$repo/$dir" -type f -name "$pattern" 2>/dev/null | grep -q .; then
        echo "$repo: missing $dir/$pattern" >&2
        failures=$((failures + 1))
    fi
}

check_repo() {
    repo="$1"
    if [ ! -d "$repo" ]; then
        echo "$repo: not a directory" >&2
        failures=$((failures + 1))
        return
    fi

    check_path "$repo" repo.json
    check_path "$repo" AGENTS.md
    check_path "$repo" README.md
    check_path "$repo" VERSION
    check_path "$repo" CMakeLists.txt
    check_path "$repo" Kconfig
    check_path "$repo" Makefile.linux
    check_path "$repo" docs/todo.yaml
    check_path "$repo" docs/module_structure.md
    check_path "$repo" zephyr/CMakeLists.txt
    check_path "$repo" zephyr/Kconfig
    check_path "$repo" zephyr/module.yml

    check_dir_has_file "$repo" include "*.h"
    check_dir_has_file "$repo" src "*.c"
    check_dir_has_file "$repo" tests "unit_*.c"
    check_dir_has_file "$repo" scripts "test_*.sh"

    echo "$repo: checked"
}

if [ "$#" -eq 0 ]; then
    usage
    exit 2
fi

for repo in "$@"; do
    check_repo "$repo"
done

if [ "$failures" -ne 0 ]; then
    echo "module structure audit failed: $failures issue(s)" >&2
    exit 1
fi

echo "module structure audit passed"
