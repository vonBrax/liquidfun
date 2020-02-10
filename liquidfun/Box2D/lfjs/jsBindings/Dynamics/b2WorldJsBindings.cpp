#include <emscripten/bind.h>
#include <Box2D/Common/b2Settings.cpp>
#include <Box2D/Collision/b2BroadPhase.cpp>
#include <Box2D/Collision/b2DynamicTree.cpp>
#include <Box2D/Common/b2BlockAllocator.cpp>
#include <Box2D/Common/b2StackAllocator.cpp>
#include <Box2D/Common/b2TrackedBlock.cpp>
#include <Box2D/Dynamics/b2Fixture.cpp>
#include <Box2D/Dynamics/b2ContactManager.cpp>
#include <Box2D/Dynamics/Contacts/b2Contact.cpp>
#include <Box2D/Dynamics/b2WorldCallbacks.cpp>
#include <Box2D/Particle/b2ParticleSystem.cpp>
#include <Box2D/Dynamics/b2World.cpp>
using namespace emscripten;

EMSCRIPTEN_BINDINGS(world_module) {
  class_<b2World>("World")
    .constructor<b2Vec2>()
    .function("GetGravity", &b2World::GetGravity);
}
