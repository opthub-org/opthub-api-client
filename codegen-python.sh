#!/bin/sh
set -e
SCRIPT_DIR=$(cd $(dirname $0) && pwd)

API_VERSION=$( docker run --rm -v $SCRIPT_DIR:/work mikefarah/yq '.info.version' /work/opthub-spec.yaml )

docker run --rm -u $(id -u):$(id -g) -v $SCRIPT_DIR:/local openapitools/openapi-generator-cli \
    generate \
        --input-spec /local/opthub-spec.yaml \
        --generator-name python \
        --output /local/opthub-api-client-python \
        --package-name opthub_api_client \
        --git-user-id opthub-org \
        --git-repo-id opthub-api-client-python \
        --additional-properties packageVersion=$API_VERSION

for PATCH_FILE in $(ls $SCRIPT_DIR/patch/python/*.patch); do
    echo "Applying patch '$PATCH_FILE'..."
    patch -p1 --directory=$SCRIPT_DIR/opthub-api-client-python < $PATCH_FILE
done
