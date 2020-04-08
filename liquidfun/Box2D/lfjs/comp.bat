emcc -I ../ -o dist/a.out.js -O3 --bind ./jsBindings/bindings.cpp -s "EXTRA_EXPORTED_RUNTIME_METHODS=['getValue']" && ^
cp dist/a.out.* ../../../../liquidfunpaint/src/liquidfun/ && ^
ECHO DONE