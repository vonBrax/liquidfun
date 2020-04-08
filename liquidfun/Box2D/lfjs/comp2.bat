emcc -I ../ -o dist/liquidfun.js --bind ./jsBindings/bindings.cpp -Oz --proxy-to-worker -s "EXTRA_EXPORTED_RUNTIME_METHODS=['getValue']" -s "ENVIRONMENT=web,worker" && ^
cp dist/*.* ../../../../liquidfunpaint/static/liquidfun/ && ^
ECHO DONE