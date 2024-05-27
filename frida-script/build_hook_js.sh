#!/bin/sh

# get absolute path of shell script directory
SCRIPT_DIR=$(dirname "$(realpath "$0")")

cd "${SCRIPT_DIR}/hooks"
npm run build

