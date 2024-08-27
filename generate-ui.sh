#!/bin/sh
SCRIPT_DIR=$(cd $(dirname $0) && pwd)
set -e

# ref: https://github.com/swagger-api/swagger-ui/blob/HEAD/docs/usage/installation.md#plain-old-htmlcssjs-standalone

pushd $SCRIPT_DIR
rm -rf ui
mkdir ui
curl -L https://github.com/swagger-api/swagger-ui/archive/refs/tags/v5.17.14.tar.gz | tar xvzf - -C ui swagger-ui-5.17.14/dist
pushd ui/swagger-ui-5.17.14/dist
cp ../../../opthub_spec.yaml ./
sed -i -e 's/https:\/\/petstore.swagger.io\/v2\/swagger.json/opthub_spec.yaml/' swagger-initializer.js
popd
popd
