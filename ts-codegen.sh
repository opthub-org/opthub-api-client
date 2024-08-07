#!/bin/sh
SCRIPT_DIR=$(cd $(dirname $0) && pwd)

docker run --rm -u $(id -u):$(id -g) -v $SCRIPT_DIR:/local openapitools/openapi-generator-cli \
    generate \
        --input-spec /local/opthub_spec.yaml \
        --generator-name typescript-node \
        --output /local/opthub-api-client-ts \
        --package-name opthub-api-client-ts \
        --git-user-id opthub-org \
        --git-repo-id opthub-api-client-ts
