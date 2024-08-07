#!/bin/sh
SCRIPT_DIR=$(cd $(dirname $0) && pwd)


for GEN_SCRIPT in $(ls $SCRIPT_DIR/codegen-*.sh); do
    FILENAME=$(basename $GEN_SCRIPT)
    LANG_SH=${FILENAME##codegen-}
    LANG=${LANG_SH%.sh}
    if [ "$LANG" = "all" ]; then
        continue
    fi
    find $SCRIPT_DIR/opthub-api-client-$LANG -mindepth 1 -maxdepth 1 ! -name '.git' -exec rm -rf {} +
    $GEN_SCRIPT
    cp $SCRIPT_DIR/LICENSE $SCRIPT_DIR/opthub-api-client-$LANG/
done
