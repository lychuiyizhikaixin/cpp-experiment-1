#!/bin/bash
set -euo pipefail
cd "$(dirname "$0")/.."
bash script/build.sh
bash script/run.sh "$@"
