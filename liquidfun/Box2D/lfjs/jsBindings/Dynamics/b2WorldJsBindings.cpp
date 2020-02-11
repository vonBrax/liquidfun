#include <emscripten/bind.h>
#include <Box2D/Box2D.h>


using namespace emscripten;

EMSCRIPTEN_BINDINGS(world_module) {
  class_<b2World>("World")
    .constructor<b2Vec2>()
    .function("GetGravity", &b2World::GetGravity)
    .function("CreateBody", &b2World::CreateBody, allow_raw_pointers())
    .function("DestroyBody", &b2World::DestroyBody, allow_raw_pointers())
    .function("CreateJoint", &b2World::CreateJoint, allow_raw_pointers())
    .function("DestroyJoint", &b2World::DestroyJoint, allow_raw_pointers());
}
