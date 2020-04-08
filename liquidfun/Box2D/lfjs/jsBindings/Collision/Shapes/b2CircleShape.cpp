using namespace emscripten;

EMSCRIPTEN_BINDINGS(circle_shape_module) {
  class_<b2CircleShape, base<b2Shape>>("CircleShape")
    .constructor<>()
    .function("SetPosition", &b2CircleShape::SetPosition);
    // .property("radius", &b2CircleShape::m_radius);
    // .property("radius", &b2CircleShape::m_radius);
    // .function("SetAsBox", select_overload<void(float, float)>(&b2CircleShape::SetAsBox))
    // .function("SetAsBox", select_overload<void(float, float, const b2Vec2&, float)>(&b2CircleShape::SetAsBox));
}
