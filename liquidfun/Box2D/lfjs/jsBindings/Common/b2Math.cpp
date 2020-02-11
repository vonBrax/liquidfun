#include <emscripten/bind.h>
#include<Box2D/Box2D.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(lfjs_module) {
  class_<b2Vec2>("Vec2")
    .constructor<float,float>()
    .function("Set", &b2Vec2::Set)
    .property("x", &b2Vec2::x)
    .property("y", &b2Vec2::y);
}
