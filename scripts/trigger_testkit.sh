#!/usr/bin/env sh
# Trigger a module test case through dephy_testkit result wrapping.
set -eu

if [ "$#" -lt 2 ]; then
    echo "usage: $0 CASE_NAME COMMAND [ARG ...]" >&2
    exit 2
fi

ROOT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
TESTKIT="${DEPHY_TESTKIT_ROOT:-$ROOT_DIR/../dephy_testkit}"

if [ ! -x "$TESTKIT/scripts/run_with_result.sh" ]; then
    echo "missing dephy_testkit; set DEPHY_TESTKIT_ROOT or keep dephy_testkit as a sibling repo" >&2
    exit 1
fi

"$TESTKIT/scripts/run_with_result.sh" "$@"
