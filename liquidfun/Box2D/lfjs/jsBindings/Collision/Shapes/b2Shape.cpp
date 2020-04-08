using namespace emscripten;

EMSCRIPTEN_BINDINGS(shape_module) {
  class_<b2Shape>("Shape")
  .property("radius", &b2Shape::m_radius);
}