#!/bin/sh
SCRIPT_DIR=$(cd $(dirname $0) && pwd)


for GEN_SCRIPT in $(ls $SCRIPT_DIR/*-codegen.sh); do
    FILENAME=$(basename $GEN_SCRIPT)
    LANG=${FILENAME%-codegen.sh}
    shopt -s dotglob
    yes | rm -rf $SCRIPT_DIR/opthub-api-client-$LANG/*
    $GEN_SCRIPT
    cp $SCRIPT_DIR/LICENSE $SCRIPT_DIR/opthub-api-client-$LANG/
done
