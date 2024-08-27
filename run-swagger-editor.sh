#!/bin/sh
SCRIPT_DIR=$(cd $(dirname $0) && pwd)

docker run --rm -p 80:8080 -e SWAGGER_FILE="/local/opthub-spec.yaml" --name opthub-swagger-editor -v $SCRIPT_DIR:/local swaggerapi/swagger-editor

