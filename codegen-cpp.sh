#!/bin/sh
SCRIPT_DIR=$(cd $(dirname $0) && pwd)

docker run --rm -u $(id -u):$(id -g) -v $SCRIPT_DIR:/local openapitools/openapi-generator-cli \
    generate \
        --input-spec /local/opthub-spec.yaml \
        --generator-name cpp-restsdk \
        --output /local/opthub-api-client-cpp \
        --package-name opthub_api_client \
        --git-user-id opthub-org \
        --git-repo-id opthub-api-client-cpp
