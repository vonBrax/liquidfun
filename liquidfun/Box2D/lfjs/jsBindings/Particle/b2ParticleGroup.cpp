namespace emscripten {

  namespace internal {
    template<> void raw_destructor<b2ParticleGroup>(b2ParticleGroup* ptr) {
      // Do nothing.
    }
  }

  EMSCRIPTEN_BINDINGS(particle_group_module) {

    class_<b2ParticleGroupDef>("ParticleGroupDef")
      .constructor<>()
      .function("SetColor", &b2ParticleGroupDef::SetColor)
      // .function("SetCircleShapesFromVertexList", &b2ParticleGroupDef::SetCircleShapesFromVertexList, allow_raw_pointers())
      .function("SetCircleShapesFromVertexList", optional_override(
        [](b2ParticleGroupDef& self, uintptr_t buffPtr, int numShapes, float radius) {
          int* ptr = reinterpret_cast<int*>(buffPtr);
          return self.SetCircleShapesFromVertexList(ptr, numShapes, radius);
        }
      ))
      .property("flags", &b2ParticleGroupDef::flags)
      .property("groupFlags", &b2ParticleGroupDef::groupFlags)
      .property("linearVelocity", &b2ParticleGroupDef::linearVelocity);


    class_<b2ParticleGroup>("ParticleGroup")
      // .function("GetNext", &b2ParticleGroup::GetNext, allow_raw_pointers());
      .function("GetNext", select_overload<b2ParticleGroup*()>(&b2ParticleGroup::GetNext), allow_raw_pointers())
      .function("GetParticleCount", &b2ParticleGroup::GetParticleCount)
      .function("GetGroupFlags", &b2ParticleGroup::GetGroupFlags)
      .function("GetBufferIndex", &b2ParticleGroup::GetBufferIndex);

    // enum_<b2ParticleGroupFlag>("ParticleGroupFlag")
    //   .value("solidParticleGroup", b2_solidParticleGroup)
    //   .value("rigidParticleGroup", b2_rigidParticleGroup)
    //   .value("particleGroupCanBeEmpty", b2_particleGroupCanBeEmpty)
    //   .value("particleGroupWillBeDestroyed", b2_particleGroupWillBeDestroyed)
    //   .value("particleGroupNeedsUpdateDepth", b2_particleGroupNeedsUpdateDepth)
    //   .value("particleGroupInternalMask", b2_particleGroupInternalMask);

    // EM_ASM(
    //   Module["ParticleGroupFlag"]["particleGroupCanBeEmpty"] = Module["ParticleGroupFlag"]["particleGroupCanBeEmpty"]["value"];
    // )
  }
}