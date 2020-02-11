#include <emscripten/bind.h>
#include <Box2D/Box2D.h>

namespace emscripten {

  namespace internal {
    template<> void raw_destructor<b2Body>(b2Body* ptr) {
      // Do nothing.
    }
  }

EMSCRIPTEN_BINDINGS(body_module) {
  enum_<b2BodyType>("BodyType")
    .value("StaticBody", b2BodyType::b2_staticBody)
    .value("KinematicBody", b2BodyType::b2_kinematicBody)
    .value("DynamicBody", b2BodyType::b2_dynamicBody);

  class_<b2BodyDef>("BodyDef")
    .constructor<>()
    .property("position", &b2BodyDef::position)
    .property("angle", &b2BodyDef::angle)
    .property("linearVelocity", &b2BodyDef::linearVelocity)
    .property("angularVelocity", &b2BodyDef::angularVelocity)
    .property("linearDamping", &b2BodyDef::linearDamping)
    .property("angularDamping", &b2BodyDef::angularDamping)
    .property("allowSleep", &b2BodyDef::allowSleep)
    .property("awake", &b2BodyDef::awake)
    .property("fixedRotation", &b2BodyDef::fixedRotation)
    .property("bullet", &b2BodyDef::bullet)
    .property("type", &b2BodyDef::type)
    .property("active", &b2BodyDef::active)
    .property("gravityScale", &b2BodyDef::gravityScale);

  class_<b2Body>("Body")
    .function(
      "CreateFixture",
      select_overload<b2Fixture*(b2FixtureDef*)>(&b2Body::CreateFixture),
      allow_raw_pointers()
    )
    .function(
      "CreateFixtureShape",
      select_overload<b2Fixture(b2Shape,float)>(&b2Body::CreateFixture),
      allow_raw_pointers()
    );
}
}
