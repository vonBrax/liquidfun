#include <emscripten/bind.h>
#include <Box2D/Common/b2Math.h>
#include <Box2D/Common/b2Math.cpp>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(lfjs_module) {
  class_<b2Vec2>("Vec2")
    .constructor<float,float>()
    .property("x", &b2Vec2::x)
    .property("y", &b2Vec2::y); 
}
