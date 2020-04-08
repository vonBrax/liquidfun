// #include <emscripten/bind.h>
// #include <Box2D/Box2D.h>


using namespace emscripten;

EMSCRIPTEN_BINDINGS(world_module) {
  class_<b2World>("World")
    .constructor<b2Vec2>()
    // .function("GetGravity", &b2World::GetGravity)
    // .function("CreateBody", &b2World::CreateBody, allow_raw_pointers())
    // .function("DestroyBody", &b2World::DestroyBody, allow_raw_pointers())
    // .function("CreateJoint", &b2World::CreateJoint, allow_raw_pointers())
    // .function("DestroyJoint", &b2World::DestroyJoint, allow_raw_pointers());
    .function("SetGravity", select_overload<void(const b2Vec2&)>(&b2World::SetGravity))
    .function("SetGravity", select_overload<void(float, float)>(&b2World::SetGravity))
    .function("SetDebugDraw", &b2World::SetDebugDraw, allow_raw_pointers())
    .function("CreateParticleSystem", &b2World::CreateParticleSystem, allow_raw_pointers())
    .function("DrawDebugData", &b2World::DrawDebugData)
    .function("Step", select_overload<void(float,int,int,int)>(&b2World::Step))
    .function("Step", select_overload<void(float, int, int)>(&b2World::Step))
    .function("CreateBody", &b2World::CreateBody, allow_raw_pointers())
    .function("GetBodyCount", &b2World::GetBodyCount)
    .function("DestroyBody", &b2World::DestroyBody, allow_raw_pointers());
}
