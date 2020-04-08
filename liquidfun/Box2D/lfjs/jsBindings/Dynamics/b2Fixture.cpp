using namespace emscripten;

EMSCRIPTEN_BINDINGS(fixture_module) {
  class_<b2Fixture>("Fixture");
}