#!/bin/sh
SCRIPT_DIR=$(cd $(dirname $0) && pwd)
set -e

echo -n "一括コミット&pushを行う場合はコミットメッセージを入力（空入力で生成のみ）: "
read COMMIT_MSG

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

    if [ "$COMMIT_MSG" != "" ]; then
        pushd $SCRIPT_DIR/opthub-api-client-$LANG
        git add .
        git commit -m "$COMMIT_MSG"
        git push origin HEAD:main
        popd
    fi
done

echo "Generating documentation UI..."
$SCRIPT_DIR/generate-ui.sh
