// #include <emscripten/bind.h>
// #include<Box2D/Box2D.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(math_module) {
  class_<b2Vec2>("Vec2")
    .constructor<float,float>()
    .function("Set", &b2Vec2::Set)
    .property("x", &b2Vec2::x)
    .property("y", &b2Vec2::y);

  class_<b2Transform>("Transform")
    .constructor<>()
    .constructor<b2Vec2, b2Rot>()
    .function("SetIdentity", &b2Transform::SetIdentity)
    .function("GetPositionY", &b2Transform::GetPositionX)
    .function("GetRotationSin", &b2Transform::GetRotationSin)
    .function("GetRotationCos", &b2Transform::GetRotationCos)
    .property("p", &b2Transform::p)
    .property("q", &b2Transform::q);
}
